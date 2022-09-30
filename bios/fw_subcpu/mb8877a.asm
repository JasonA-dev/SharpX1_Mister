;******************************************************************************
;   FDC(MB8877A) microcode for X1 SUB-CPU (MR16) with FDD enulation
;
; 2005. 4.12 1st release
;
; note:
;
; -TYPE-IIIコマンド、まったく実装してません。
; -TYPE-IV適当に扱ってます。
; -エミュレーション用なので、現状ではFドライブは繋がりません。
; -128usタスク　＆　16us割り込み処理が汚く、動作も不安
;  RTOSを辞め、16usタイマにて自前でタスクスイッチすべきだった。
;
;******************************************************************************
;
;NO_LOST_DATA equ 1
;
;-----------------------------------------------------------------
;SHOW_TRK equ 1
;
;fixed register assign
;
;r7 = current FDC command code
;r6 = I/O signal & internal state
;
;FDC status code
;
STS_NOT_RDY		equ	80h
STS_WRITE_PROTECT	equ	40h
STS_HEAD_ENAGAED	equ	20h
STS_RECOARD_TYPE	equ	20h
STS_WRITE_FAULT		equ	20h
STS_SEEK_ERROR		equ	10h
STS_RECOARD_NOT_FOUND	equ	10h
STS_CRC_ERROR		equ	08h
STS_LOST_DATA		equ	04h
STS_TRACK_00		equ	04h 
;STS_DATA_REQ		equ	02h
STS_INDEX		equ	02h
STS_BUSY		equ	01h
;
IN_HLT 			equ	0100h ; Read Only HLT pin
IN_WPRT			equ	0200h ; Read Only (R/W for EMU)
STS_DATA_REQ		equ	0400h ; Read Only
IN_TRK00		equ	0800h ; Read Only (R/W for EMU)
IN_INDEX		equ	1000h ; Read Only (R/W for EMU)
;
;FD time count
;3xA1,FE,T,S,R,N,CRC,CRC,11xFF,3xA1,FB/F8+DATA = 26bytes
FDC_ID_WAIT equ	26
;
;FDC output port
;
;----------------------------------------------------------------------------
; register assign
;----------------------------------------------------------------------------
; r0-5  :work register
; r6    :output signal
; r7    :current command
; r8-15 :fixed register
;
;----------------------------------------------------------------------------
; I/O address map
;----------------------------------------------------------------------------
;
FDC_WORK_BASE	equ	R10_BASE ; 
FDC_REG_BASE	equ	R11_BASE ; FDC I/F register map
;FDC_CMD equ	0ff0h
;FDC_TRK equ	0ff2h
;FDC_SEC equ	0ff4h
;FDC_DAT equ	0ff6h
;
;FDD_MOT equ	0ff8h  ;X1 motor port
;FDD_MOT_MON	equ	80h ;motor ON
;FDD_MOT_SIDE	equ	10h ;head side
;FDD_MOT_DS1	equ	02h ;DriveSelect1
;FDD_MOT_DS0	equ	01h ;DriveSelect0
;
;----------------------------------------------------------------------------
; work buffer
;----------------------------------------------------------------------------
	DSEG
fdc_task ds	2  ;fdc ISRtimer routine
fdc_mode ds	2  ;FDC mode FM/MFM,etc.
;
fdc_drvp ds	2  ;pointer of drive work
drv_work ds	4*4
o_ptrk		equ	0
;
;--------------------------------------------------
;OUTPUT PORT PIN (r6)
;--------------------------------------------------
TG43	equ	0001h
FDC_HLD	equ	0008h
FDC_DIRC equ	0010h  ;0=STEP OUT(-) , 1=STEP IN(+)
;
	CSEG
;
;
;----------------------------------------------------------------------------
; FDC CMD WR TRAP ISR
;----------------------------------------------------------------------------
fdc_isr:
	push	flag
	push	r0
;CMD WR MARK
	ldm	r0,(r11,#FDC_CMD-R11_BASE)
	and	r0,#0ffh:8
	stm	(r11,#FDC_CMD-R11_BASE),r0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;BUSY ON
;	ldm	r0,(r14,#FDC_STS-R14_BASE)
;	or	r0,#STS_BUSY:8
;	stm	(r14,#FDC_STS-R14_BASE),r0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;FDC task wakeup!
	mov	r0,#1:8
	jsr	OS_Resume
	pop	r0
	pop	flag
	ret	sti
;
;----------------------------------------------------------------------------
; FDC MAIN TASK
;----------------------------------------------------------------------------
;r7 = current command
;r6 = FDC output port copy
fdc_entry:
	mov	r0,#0:8 ;clear all status
	stm	(r14,#FDC_STS-R14_BASE),r0
;clear DRQ
	ldm	r0,(r14,#FDC_DRQ_CLR-R14_BASE)
;FDD emulation init
	jsr	fdd_init
;
	mov	r0,#8000h  ; clear command in flag
	stm	(r11,#FDC_CMD-R11_BASE),r0 ;set clear mark
;
	mov	r6,#0:8      ;default output pins
	mov	r7,#0:8      ;clear last command code is TYPE-I
;
fdc_loop:
;BUSY clear
	ldm	r1,(r14,#FDC_STS-R14_BASE)
	and	r1,#0ffh ^ STS_BUSY:8
	stm	(r14,#FDC_STS-R14_BASE),r1
;----- wait until CMD.WR tarp input -----
fdc_l1:
;CHECK COMMAND IN ?
	ldm	r0,(r11,#FDC_CMD-R11_BASE)
	tst	r0,r0 ;writed ?
	bpl	fdc_cmd_in
;STATUS UPDATE
	jsr	fdc_upd_sts
;WAIT
	mov	r0,#2*8:8    ;short sleep
	jsr	OS_Sleep
;
	bra	fdc_l1
;
;----- command handling ------
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	mov	r0,#16*10:8
fdc_cmd_w:
	sub	r0,#1:8
	bne	fdc_cmd_w
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
fdc_cmd_in:
;wait some x 10us
	
	mov	r7,r0      ; new cmd
	mov	r0,#8000h  ; clear flag
	stm	(r11,#FDC_CMD-R11_BASE),r0 ;set clear mark
;
	tst	r7,#80h:8
	beq	fdc_type1
	tst	r7,#40h:8
	beq	fdc_type2
	cmp	r7,#0f0h:8
	jlo	fdc_type3
	jmp	fdc_type4
;
;----------------------------------------------------------------------------
; TYPE-I entry
;----------------------------------------------------------------------------
fdc_type1:
;BSY = 1 & clear status
	ldm	r0,(r14,#FDC_STS-R14_BASE)
	and	r0,#STS_NOT_RDY:8
	or	r0,#STS_BUSY:8
	stm	(r14,#FDC_STS-R14_BASE),r0
;TYPE 2/3 DRQ Clear
	ldm	r0,(r14,#FDC_DRQ_CLR-R14_BASE)
;
	jsr	fdc_upd_sts
;if(CMD.h) HLD = 1 else HLD = 0
	and	r6,#0ffh ^ FDC_HLD:8
	tst	r7,#8:8    ;CMD.h ?
	beq	fdc_t11
	or	r6,#FDC_HLD:8
fdc_t11:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;wait?
	mov	r0,#3000/TIME_TICK:8
	jsr	OS_Sleep
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
	tst	r7,#40h:8  ; step in or out ?
	bne	stepin_out
	tst	r7,#20h:8  ; step ?
	bne	step
	tst	r7,#10h:8  ; seek ?
	bne	seek
;restore
;TRK = 0xff;
	mov	r1,#0ffh:8
	stm	(r11,#FDC_TRK-R11_BASE),r1
	mov	r1,#0:8
	stm	(r11,#FDC_DAT-R11_BASE),r1
;change command code to SEEK
	or	r7,#10h:8  ;RESTORE -> SEEK
seek:
	or	r6,#FDC_DIRC:8   ;DIRC=1
	ldm	r0,(r11,#FDC_DAT-R11_BASE)
	ldm	r1,(r11,#FDC_TRK-R11_BASE)
	cmp	r0,r1
	beq	seek_end
	bhs	seek_out
	xor	r6,#FDC_DIRC:8   ;DIRC=0
seek_out:
	bra	fdc_t1u1
;
stepin_out:
	or	r6,#FDC_DIRC:8   ;DIRC=1
	tst	r7,#20h:8
	beq	step         ;step in
;step out
	xor	r6,#FDC_DIRC:8   ;DIRC=0
step:
	tst	r7,#10h:8   ;CMD.u ?
	beq	fdc_t1u0    ;no TRK update
;seek with track update
fdc_t1u1:
;update TRK reg
	ldm	r0,(r11,#FDC_TRK-R11_BASE)
	add	r0,#1:8   ;+1
	tst	r6,#FDC_DIRC:8
	bne	fdc_trk_set
	sub	r0,#2:8   ;-1
fdc_trk_set:
	stm	(r11,#FDC_TRK-R11_BASE),r0
fdc_t1u0:
;if(DIRC==0 & TRACK_00) goto seek_end
	jsr	fdc_upd_sts
;
	tst	r6,#FDC_DIRC:8
	bne	fdc_no_trk00
;
	ldm	r0,(r14,#FDC_STS-R14_BASE)
	tst	r0,#STS_TRACK_00:8
	beq	fdc_no_trk00
;goto seek_end
	mov	r0,#0:8
	stm	(r11,#FDC_TRK-R11_BASE),r0
	bra	seek_end
fdc_no_trk00:
;-------------------------------------
;OUTPUT SEEK PULSE
	jsr	fdd_seek_pulse
;-------------------------------------
.ifdef SHOW_TRK
	ldm	r1,(r11,#FDC_TRK-R11_BASE)
;	or	r1,#0ee00h
	and	r1,#0ffh:8
	ldm	r0,(r11,#FDC_TRK-R11_BASE)
;
	mov	r0,#fd_phy_trk
	ldm	r0,(r0)
	mlt	r0,#100h
	or	r1,r0

	stm	(r14,#SEG7_NUM-R14_BASE),r1
.endif
;seek time
	mov	r0,#6000/TIME_TICK ; 00=6ms/3ms
	tst	r7,#3:8
	beq	seek_spd
	add	r0,r0              ; 01=12ms/6ms
	tst	r7,#2:8
	beq	seek_spd
	mov	r0,#20000/TIME_TICK ; 10=20ms/10ms
	tst	r7,#1:8
	beq	seek_spd
	mov	r0,#30000/TIME_TICK ; 01=30ms/15ms
seek_spd:
;media check
; tst r0,#IN_CLK_2M
; beq
; mlh  r0,#8000h ;2HD 1/2
	jsr	OS_Sleep
;
	tst	r7,#0e0h:8 ;seek/restore ?
	beq	seek
seek_end:
	tst	r7,#004h:8 ;V=1 ?
	beq	type1_e
;Verify
	jsr	fdc_hld15
;
	mov	r0,#0:8
	stm	(r10,#fdc_ip-r10_BASE),r0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	jsr	read_idam
	jcs	type1_e  ;timeout
;clear CRC error
	ldm	r1,(r14,#FDC_STS-R14_BASE)
	and	r1,#0ffh ^ STS_CRC_ERROR:8
	stm	(r14,#FDC_STS-R14_BASE),r1
type1_e:
	bra	fdc_loop
;
;----------------------------------------------------------------------------
; HLD 15ms wait
;----------------------------------------------------------------------------
fdc_hld15:
	tst	r7,#04h:8  ;V flag ?
	beq	fdc_hld0
;
	mov	r0,#15000/TIME_TICK ;15ms wait
	jsr	OS_Sleep
fdc_hld0:
;HLD = 1
	or	r6,#FDC_HLD:8
;
;while (HLT=1)
;
	ret
;
;----------------------------------------------------------------------------
; TYPE-II not ready
;----------------------------------------------------------------------------
fdc_type2_nrdy:
;IRQ = 1
	jmp	fdc_loop
;;	bra	fdc_loop
;----------------------------------------------------------------------------
; TYPE-II write protect
;----------------------------------------------------------------------------
fdc_t2_wrt:
	ldm	r1,(r14,#FDC_STS-R14_BASE)
	or	r1,#STS_WRITE_PROTECT:8
	stm	(r14,#FDC_STS-R14_BASE),r1
;
	jmp	fdc_loop
;;	bra	fdc_loop
;
;----------------------------------------------------------------------------
; FDC ISR TYPE2
;
; note:
;  HLD not supported
;  HLT sampling not supported
;  E bit 15ms wait not supported
;  WPRT no check
;----------------------------------------------------------------------------
fdc_type2:
;BSY = 1 & clear status
	ldm	r0,(r14,#FDC_STS-R14_BASE)
	and	r0,#STS_NOT_RDY:8
	or	r0,#STS_BUSY:8
	stm	(r14,#FDC_STS-R14_BASE),r0
;update FDD status (NOT READY)
	jsr	fdc_upd_sts
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;wait?
	mov	r0,#2*8:8
	jsr	OS_Sleep
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;not ready check
;if(!READY) goto fdc_irq
	ldm	r0,(r14,#FDC_STS-R14_BASE)
	tst	r0,#STS_NOT_RDY:8
	bne	fdc_type2_nrdy  ;not ready
;HLD=1
	or	r6,#FDC_HLD:8
;if(E==1) wait(15ms)
	tst	r7,#04h:8  ;E=1 ?
	beq	fdc_t21
	mov	r0,#15000/TIME_TICK  ;15ms
	jsr	OS_Sleep
fdc_t21:
;while(HLT!=1);
	jsr	wait_hlt
;TG43 = TRK>43 ? 1 : 0
	and	r6,#0ffh^TG43:8
	ldm	r0,(r11,#FDC_TRK-R11_BASE)
	cmp	r0,#43+1:8
	blo	type2_3
	or	r6,#TG43:8
type2_3:
;if( WriteData & WPRT=0 goto fdc_irq)
	tst	r7,#20h:8  ;Write data ?
	beq	type2_4
	ldm	r0,(r14,#FDC_IN-R14_BASE)
	tst	r0,#IN_WPRT
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	bne	fdc_t2_wrt
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
type2_4:
	mov	r0,#0:8
	stm	(r10,#fdc_ip-r10_BASE),r0
type2_5:
	jsr	read_idam
	bcs	type2_rnf
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;TYPE-IV break check
	ldm	r0,(r11,#FDC_CMD-R11_BASE)
	tst	r0,r0
	jpl	fdc_cmd_in
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;compare target and readed-ID
	tst	r7,#02h:8  ; C=1?
	beq	type2_7
;S == H?
	ldm	r0,(r10,#fdd_H-R10_BASE)
	tst	r7,#08h:8  ; S=1?
	beq	type2_6
	xor	r0,#01h:8
type2_6:
	tst	r0,#01h:8
	bne	type2_5
type2_7:
;R == R
	ldm	r0,(r10,#fdd_R-R10_BASE)
	ldm	r1,(r11,#FDC_SEC-R11_BASE)
	cmp	r0,r1
	bne	type2_5
;ID CRC check
	ldm	r0,(r10,#fdd_sts-R10_BASE)
	tst	r0,#STS_CRC_ERROR:8
	beq	id_no_crc_err
;
	ldm	r0,(r14,#FDC_STS-R14_BASE)
	or	r0,#STS_CRC_ERROR:8
	stm	(r14,#FDC_STS-R14_BASE),r0
	bra	type2_5
id_no_crc_err:
	ldm	r0,(r14,#FDC_STS-R14_BASE)
	and	r0,#0ffh ^ STS_CRC_ERROR:8
	stm	(r14,#FDC_STS-R14_BASE),r0
;Write / Read branch
	tst	r7,#20h:8  ;Write data ?
	bne	fdc_type2_wr
;----------
;read sector
	ldm	r1,(R10,#fdd_meml-R10_BASE)
	ldm	r2,(R10,#fdd_memH-R10_BASE)
	or	r2,#DMAM_RFSH_REQ | DMAM_MREQ | DMAM_RD
	ldm	r3,(r10,#fdc_slen-R10_BASE)
;
fdc_rd_drq:
	mov	r0,#32/TIME_TICK:8
	jsr	OS_Sleep
.ifdef NO_LOST_DATA
;non overlow mode
	ldm	r0,(r14,#FDC_STS-R14_BASE)
	tst	r0,#STS_DATA_REQ
	bne	fdc_rd_drq
.endif
;read FDD data in RFSH access
	cli
	stm	(r14,#FDM_AL-R14_BASE),r1
	stm	(r14,#FDM_AH-R14_BASE),r2
;pointer increment
	add	r1,#1:8
	adc	r2,#0:8
;wait until data read
fdc_rd_drq1:
	ldm	r0,(r14,#DMA_DATA-R14_BASE)
	tst	r0,#DMAM_BUSY
	bne	fdc_rd_drq1
;copy read DATA to DATA regiter
	ldm	r0,(r14,#DMA_DATA-R14_BASE)
	and	r0,#0ffh:8
	stm	(r11,#FDC_DAT-R11_BASE),r0
;clear RFSH access
	mov	r0,#0:8
	stm	(r14,#FDM_AH-R14_BASE),r0
	sti
;set DRQ status
	ldm	r0,(r14,#FDC_DRQ_SET-R14_BASE)
;count down sector length
	sub	r3,#1:8
	bne	fdc_rd_drq
;end of RD
;wait until CRC read
	mov	r0,#32*2/TIME_TICK:8
	jsr	OS_Sleep
;
sec_end:
	tst	r7,#10h:8  ;m==1 ?
	jeq	fdc_loop
;multi sector
	ldm	r0,(r11,#FDC_SEC-R11_BASE)
	add	r0,#1:8
	and	r0,#0ffh:8
	stm	(r11,#FDC_SEC-R11_BASE),r0
	bra	type2_4
;
;----- recoard not found error -----
type2_rnf:
	jmp	fdc_loop
;
;----------------------------------------------------------------------------
; TYPE-II write main
;----------------------------------------------------------------------------
fdc_type2_wr:
;wait 2byte
;set DRQ for 1st data
	ldm	r0,(r14,#FDC_DRQ_SET-R14_BASE)
;wait 8byte
;if(not DREQ) goto LOST_DATA error
;wait 1byte
;if(dden==0)
;  wait 1byte,WG=1,write 12byte 00h
;else
;  WG=1,write 6byte
;
	tst	r7,#1:8   ;a0
;if(a0) write DeletedDataMark
;else   write DataMark
;
;DRQ ISR set
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;----------------------------------------------------------------------------
; FDC WriteSector DRQ ISR
;----------------------------------------------------------------------------
fdc_wr_drq:
	mov	r0,#32/TIME_TICK:8
	jsr	OS_Sleep
.ifdef NO_LOST_DATA
;non overlow mode
	ldm	r0,(r14,#FDC_STS-R14_BASE)
	tst	r0,#STS_DATA_REQ
	bne	fdc_wr_drq
.endif
	cli
;request FDD memory write
	ldm	r0,(r11,#FDC_DAT-R11_BASE)
	stm	(r14,#DMA_DATA-R14_BASE),r0
;
	push	r1
	ldm	r0,(R10,#fdd_meml-R10_BASE)
	stm	(r14,#FDM_AL-R14_BASE),r0
	ldm	r1,(R10,#fdd_memH-R10_BASE)
	or	r1,#DMAM_RFSH_REQ |DMAM_MREQ | DMAM_WR
	stm	(r14,#FDM_AH-R14_BASE),r1
;next FDD memory point
	add	r0,#1:8
	adc	r1,#0:8
	stm	(R10,#fdd_memH-r10_base),r1
	stm	(R10,#fdd_meml-r10_base),r0
	pop	r1
;wait until data wrote
fdc_wr_drq1:
	ldm	r0,(r14,#DMA_DATA-R14_BASE)
	tst	r0,#DMAM_BUSY
	bne	fdc_wr_drq1
;clear RFSH access
	mov	r0,#0:8
	stm	(r14,#FDM_AH-R14_BASE),r0
	sti
;count down
	ldm	r0,(r10,#fdc_slen-R10_BASE)
	sub	r0,#1:8
	stm	(r10,#fdc_slen-R10_BASE),r0
	beq	fdc_wr_drq_r
;set DRQ for next data
	ldm	r0,(r14,#FDC_DRQ_SET-R14_BASE)
;
	bra	fdc_wr_drq
;
fdc_wr_drq_r:
;wait until CRC write
	mov	r0,#32*2/TIME_TICK:8
	jsr	OS_Sleep
;
	bra	sec_end
;
;--------------------
;waiting for HLT=1
;--------------------
wait_hlt:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	ldm	r0,(r14,#FDC_IN-R14_BASE)
	tst	r0,#IN_HLT
	beq	wait_hlt_w
	ret
wait_hlt_w:
	mov	r0,#2:8
	jsr	OS_Sleep
	bra	wait_hlt
;
;------------------------------------------------
;read IDAM and comapre TRK
;------------------------------------------------
;input
;otuput
;  CF = IP timeout error
;  r0 = C
;  r1 = H
;  r2 = R
;  r3 = N
;  FDC.STS CRC error
read_idam:
;

	ldm	r0,(r10,#fdc_ip-r10_BASE)
	cmp	r0,#5:8
	bhs	read_idam_tout
;
;fdd_trk:	ds	2 ;track data top position
;fdd_num_sec	ds	2 ;data
;fdd_c		ds	2 ;C
;fdd_h		ds	2 ;H
;fdd_r		ds	2 ;R
;fdd_n		ds	2 ;N
;fdd_sts		ds	2 ;status
;
;fdd_meml	ds	2 ;memory point
;fdd_memh	ds	2
;fdc_slen		ds	2 ;memory point
;
	jsr	fdd_get_next_id
	bcs	read_idwt
;set recoard length
	ldm	r1,(r10,#fdd_N-R10_BASE)
	mov	r0,#80h:8 ;N=0:80H
	sub	r1,#1:8
	blo	n_sel
	add	r0,r0  ;N=1:100h
	sub	r1,#1:8
	blo	n_sel
	add	r0,r0  ;N=2:200h
	sub	r1,#1:8
	blo	n_sel
	add	r0,r0  ;N=3:400h
n_sel:
	stm	(r10,#fdc_slen-R10_BASE),r0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	jsr	fdc_upd_sts
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;compare TRK
	ldm	r0,(r11,#FDC_TRK-R11_BASE)
	ldm	r1,(r10,#fdd_C-R10_BASE)
	cmp	r0,r1
	beq	read_idok
;TRK mismatch , try to nect sector
;ID MARK
; FM  GAP1(40)+SYNC(6) +IDX(1)+GAP(26)
; MFM GAP1(80)+SYNC(12)+IDX(4)+GAP(50)
;sector to sector
; FM  GAP2(11)+SYNC(6) +DAM(1)+DATA+CRC(2)+GAP3(27) +SYNC(6) +ID(1)
; MFM GAP2(22)+SYNC(12)+DAM(4)+DATA+CRC(2)+GAP3(54) +SYNC(12)+ID(4)
	ldm	r0,(r10,#fdc_slen-R10_BASE)
	add	r0,#78:8 ;MFM
	mlh	r0,#100h*16/TIME_TICK
	jsr	OS_Sleep
	bra	read_idam
;
;OK return
read_idok:
	clc
	ret
;
read_idwt:
	bra	read_idam
;
;-- 5xID hole timeout --
read_idam_tout:
;STS_RECOARD_NOT_FOUND(SEEK_ERROR)
	ldm	r1,(r14,#FDC_STS-R14_BASE)
	or	r1,#STS_RECOARD_NOT_FOUND:8
	stm	(r14,#FDC_STS-R14_BASE),r1
	stc
	ret
;
;----------------------------------------------------------------------------
; UPDATE IDLE STSTUS PORT
;----------------------------------------------------------------------------
;r0 = update status mask
fdc_upd_sts:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	jsr	fdd_check
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	mov	r0,#STS_NOT_RDY|STS_WRITE_PROTECT|STS_CRC_ERROR:8 ;TYPE II/III
	tst	r7,#80h:8
	bne	fdc_upd_s1
	mov	r0,#STS_NOT_RDY|STS_WRITE_PROTECT|STS_TRACK_00|STS_INDEX:8 ;TYPE I
fdc_upd_s1:
	cli
	ldm	r1,(r10,#fdd_sts-R10_BASE)
	and	r1,r0
	ldm	r2,(r14,#FDC_STS-R14_BASE)
	or	r2,r0
	xor	r2,r0
;
	or	r1,r2
	stm	(r14,#FDC_STS-R14_BASE),r1
	sti
	ret
;
;----------------------------------------------------------------------------
; un emulatedf
;----------------------------------------------------------------------------
fdc_type3:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	mov	r0,#0fff0h
	stm	(r14,#SEG7_NUM-R14_BASE),r0
	cli
	bra	fdc_type3
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	jmp	fdc_loop
;;	bra	fdc_loop
fdc_type4:
;TYPE 2/3 DRQ Clear
;	ldm	r0,(r14,#FDC_DRQ_CLR-R14_BASE)
	jmp	fdc_loop
;;	bra	fdc_loop
