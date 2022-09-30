;******************************************************************************
; FD image data *.2D / *.D88 emulation for X1 FD Interface
;
; 2005. 4.12
;
;******************************************************************************
;
FDC_PRESET equ 1
;
;----- image mode -----
FDD_D88	equ	1
FDD_2D	equ	1
FDD_AUTO equ	FDD_D88 & FDD_2D
;
;D88 format
;
;----- HEADER -----
D88_NAME	equ	0000H ;17 DiskName (ASCII-Z)
D88_RSV11	equ	0009H ; 9 RSV
D88_WPRT	equ	001AH ; 1 10H = WriteProtect
D88_WPRT_OFF	equ	00H   ;   Protect OFF
D88_WPRT_ON	equ	10H   ;   Protect ON (*any)
D88_TYPE	equ	001BH ; 1 Disk Type
D88_TYPE_2D	equ	00H   ;   2D
D88_TYPE_2DD	equ	10H   ;   2DD
D88_TYPE_2HD	equ	20H   ;   2HD
D88_DISK_SIZE	equ	001CH ; 4 Disk Size
D88_TRK_TBL	equ	0020H ; 4*160 TrackDataTable
;
;----- TRACK -----
D88_TRK_C	equ	0000H ; 1 Cylinder
D88_TRK_H	equ	0001H ; 1 Head
D88_TRK_R	equ	0002H ; 1 Recoard
D88_TRK_N	equ	0003H ; 1 Number?
D88_TRK_NUM_SEC	equ	0004H ; 2 number of sectors per track
D88_TRK_ENC	equ	0006H ; 1 Encode Mode
D88_TRK_ENC_MFM	equ	00H   ;   MFM encode
D88_TRK_ENC_FM	equ	40H   ;   FM encode
D88_TRK_DD	equ	0007H ; 1 Data Mark
D88_TRK_DD_DEL	equ	10H   ;   DeletedDataMark
D88_TRK_STS	equ	0008H ; 1 Status
D88_TRK_STS_OK	equ	00H   ;   no error
D88_TRK_RSV09	equ	0009H ; 5 reserved
D88_TRK_SIZE	equ	000EH ; 2 sector size
D88_TRK_DATA	equ	0010H ;(D88_TRK_SIZE) sector data
;
	CSEG
;
;-------------------------------------
;get drive physical data pointer
;-------------------------------------
;input
; FDC_MOT : motor on/off and DS1,DS0
;output
; r0      : fdd_phyX
; fdd_sts : NOT READY
;
get_drv_ptr:
	ldm	r0,(r11,#FDC_MOT-R11_BASE) ;X1 DS0,DS1 port
	ldm	r1,(r10,#fdd_sts-R10_BASE)
	tst	r0,#80h:8
	beq	no_drv     ;motor OFF!
;
	tst	r0,#2:8
	bne	no_drv     ;Drive 2,3!
;
fdd_drv01:
	and	r0,#1:8
;LED Controll
	mov	r1,r0
	add	r1,#1:8
	stm	(r14,#FDD_PORT-R14_BASE),r1
;
	mlt	r0,#fd_phy_size:8
	add	r0,#fd_phy0
	and	r1,#0ffh ^ STS_NOT_RDY:8  ; READY
fdd_sd1:
	stm	(r10,#fdd_ptr-R10_BASE),r0
	stm	(r10,#fdd_sts-R10_BASE),r1
	ret
;
;drive 2,3 not ready
no_drv:
;LED OFF
	mov	r0,#0:8
	stm	(r14,#FDD_PORT-R14_BASE),r0
;
	mov	r0,#fd_phy0          ; NO DATA
	or	r1,#STS_NOT_RDY:8    ; NOT READY
	beq	no_drv     ;motor OFF!

	bra	fdd_sd1
;
;-------------------------------------
;seek one pulse
;-------------------------------------
fdd_seek_pulse
;
;-------------------------------------
;OUTPUT SEEK SOUND
	mov	r0,#0:8
	mov	r1,#160:8
	jsr	pcm_play
;-------------------------------------
;
	jsr	get_drv_ptr
	ldm	r1,(r0,#fd_phy_trk-fd_phy0)
	add	r1,#1:8   ;+1
	tst	r6,#FDC_DIRC:8
	bne	fdd_trk_set
	sub	r1,#2:8   ;-1
fdd_trk_set:
	stm	(r0,#fd_phy_trk-fd_phy0),r1
	bra	fdd_check2
;
;-------------------------------------
;FDD drive , status check
;-------------------------------------
fdd_check:
	jsr	get_drv_ptr
	ldm	r1,(r0,#fd_phy_trk-fd_phy0)
fdd_check2:
	cmp	r1,#1:8
	bhs	trk_plus
;0 or minus
	mov	r1,#0:8                      ;adjust TRK zero
	stm	(r0,#fd_phy_trk-fd_phy0),r1
;
	ldm	r0,(r10,#fdd_sts-R10_BASE)
	or	r0,#STS_TRACK_00:8           ; TRACK_00 = 1
	stm	(r10,#fdd_sts-R10_BASE),r0
	ret
;plus
trk_plus:
	cmp	r1,#40+3:8    ;TRACK LIMIT (2D)
;	cmp	r1,#82+3:8    ;TRACK LIMIT (2HD)
	blo	trk_ok
	mov	r1,#40+3:8    ;TRACK LIMIT (2D)
;	mov	r1,#82+3:8    ;TRACK LIMIT (2HD)
	stm	(r0,#fd_phy_trk-fd_phy0),r1
trk_ok:
	ldm	r0,(r10,#fdd_sts-R10_BASE)
	and	r0,#0ffh ^ STS_TRACK_00:8  ; TRACK_00 = 0
	stm	(r10,#fdd_sts-R10_BASE),r0
	ret
;
;-------------------------------------
;move FDD FDC target track
;-------------------------------------
;in
;
;out
; r0 : logical track number
fdd_focus:
;pick memory base pointer
	jsr	get_drv_ptr
	ldm	r1,(r0,#fd_phy_ml-fd_phy0)
	ldm	r2,(r0,#fd_phy_mh-fd_phy0)
	stm	(r10,#fdd_meml-R10_BASE),r1
	stm	(r10,#fdd_memh-R10_BASE),r2
;pick track
	ldm	r0,(r0,#fd_phy_trk-fd_phy0)
	add	r0,r0  ; x2
;pick HEAD SIDE
	ldm	r1,(r11,#FDC_MOT-R11_BASE)
	tst	r1,#10h:8
	beq	fdd_tg1
	or	r0,#1:8 ;+1 side
fdd_tg1:
	ret
;
;-------------------------------------
;get ID emulation
;-------------------------------------
fdd_get_next_id:
.if FDD_AUTO
	jsr	fdd_focus
	jsr	fdd_check_d88
	bcc	focus_d88
.endif
.if FDD_2D
;-------------------------------------
;.2D focus sector
;-------------------------------------
focus_2d:
;SAVE C,H
	jsr	fdd_focus
	mov	r1,r0
	mlh	r1,#8000h                ; r0 /= 2
	stm	(r10,#fdd_C-R10_BASE),r1 ; Cylinder
	mov	r1,r0
	and	r1,#1:8
	stm	(r10,#fdd_H-R10_BASE),r1 ; Head
;SECTOR increment
	ldm	r2,(r10,#fdd_sec_ptr-R10_BASE)
	add	r2,#1:8
	cmp	r2,#10h:8
	blo	focus_2d1
;IP countup
	ldm	r2,(r10,#fdc_ip-r10_BASE)
	add	r2,#1:8
	stm	(r10,#fdc_ip-r10_BASE),r2
	mov	r2,#0:8    ;roll back
focus_2d1:
	stm	(r10,#fdd_sec_ptr-R10_BASE),r2
	add	r2,#1:8
	stm	(r10,#fdd_R-R10_BASE),r2  ;1 to 16
	sub	r2,#1:8
;to recoard number
	mlt	r0,#10h:8
	add	r0,r2
;to memory offset
	mov	r1,r0
	mlt	r0,#100h
	mlh	r1,#100h
;+base address
	ldm	r2,(r10,#fdd_meml-R10_BASE)
	add	r0,r2
	ldm	r2,(r10,#fdd_memh-R10_BASE)
	adc	r1,r2
	stm	(r10,#fdd_meml-R10_BASE),r0
	stm	(r10,#fdd_memh-R10_BASE),r1
;STATUS all ready
	ldm	r0,(r10,#fdd_sts-R10_BASE)
	and	r0,#0ffh ^ STS_RECOARD_TYPE ^ STS_RECOARD_NOT_FOUND ^ STS_CRC_ERROR:8
	stm	(r10,#fdd_sts-R10_BASE),r0
;N = 1
	mov	r0,#1:8
	stm	(r10,#fdd_N-R10_BASE),r0
;
	clc
	ret
.endif
.if FDD_D88
;
;-------------------------------------
;.D88 focus sector
;-------------------------------------
focus_d88:
	jsr	fdd_focus
	mlt	r0,#4:8           ;track data size
	add	r0,#D88_TRK_TBL:8 ;header offset
	ldm	r2,(r10,#fdd_meml-R10_BASE) ;image base
	ldm	r1,(r10,#fdd_memh-R10_BASE)
	add	r0,r2
	adc	r1,#0:8
;get track data top
	jsr	read_fd_word
	mov	r3,r2
	jsr	read_fd_word
	ldm	r0,(r10,#fdd_meml-R10_BASE) ;image base
	ldm	r1,(r10,#fdd_memh-R10_BASE)
	add	r0,r3
	adc	r1,r2
;
;get number of sectors in  track
	add	r0,#D88_TRK_NUM_SEC:8
	adc	r1,#0:8
	jsr	read_fd_word
	sub	r0,#D88_TRK_NUM_SEC+2:8
	sbc	r1,#0:8
;increment SECTOR
	ldm	r3,(r10,#fdd_sec_ptr-R10_BASE)
	add	r3,#1:8
	cmp	r3,r2
	blo	d88_no_roll
;rollback sector
	ldm	r3,(r10,#fdc_ip-r10_BASE)
	add	r3,#1:8
	stm	(r10,#fdc_ip-r10_BASE),r3
	mov	r3,#0:8
d88_no_roll:
	stm	(r10,#fdd_sec_ptr-R10_BASE),r3
;
;SEARCH TARGET SECTOR
d88_skip_sec:
	sub	r3,#1:8
	blo	d88_found_sec
;
	add	r0,#D88_TRK_SIZE:8
	adc	r1,#0:8
	jsr	read_fd_word
;
	add	r0,r2
	adc	r1,#0:8
	bra	d88_skip_sec
;
d88_found_sec:
;COPY C,H,R,N
	jsr	read_fd_byte
	stm	(r10,#fdd_C-R10_BASE),r2
	jsr	read_fd_byte
	stm	(r10,#fdd_H-R10_BASE),r2
	jsr	read_fd_byte
	stm	(r10,#fdd_R-R10_BASE),r2
	jsr	read_fd_byte
	stm	(r10,#fdd_N-R10_BASE),r2
;COPY SECTOR DATA POINTER
	add	r0,#D88_TRK_DATA-4:8
	adc	r1,#0:8
	stm	(r10,#fdd_meml-R10_BASE),r0
	stm	(r10,#fdd_memh-R10_BASE),r1
;
;	stm	(r14,#SEG7_NUM-R14_BASE),r0
;	push	r0
;	mov	r0,#T1sec
;	jsr	OS_Sleep
;	pop	r0
;
	ret
;
.endif

.if FDD_AUTO
;-------------------------------------
;reset media
;-------------------------------------
reset_media:
;set track limit
;	mov	r0,#40+3:8
;	stm	(fdd_limit_trk),r0
;set 1MHz to FDC clock
;write protect off
	ret
;
;-------------------------------------
;check media
;-------------------------------------
;
;output
;   CF = .d88 found
fdd_check_d88:
	jsr	reset_media
;try to check d88 format
	ldm	r0,(r10,#fdd_meml-R10_BASE) ;image base
	ldm	r1,(r10,#fdd_memh-R10_BASE)
;WPRT
	mov	r2,#D88_WPRT:8
	add	r0,r2
	adc	r1,#0:8
	jsr	read_fd_byte
	cmp	r2,#D88_WPRT_OFF:8
	beq	fdd_cm1
;	cmp	r2,#D88_WPRT_ON:8
;	bne	fdd_dot_2d
;write proect on
	ldm	r3,(r10,#fdd_sts-R10_BASE)
	or	r3,#STS_WRITE_PROTECT:8 ; protect on
	stm	(r10,#fdd_sts-R10_BASE),r3
fdd_cm1:
;TYPE 2D/2DD/2HD
	jsr	read_fd_byte
	cmp	r2,#D88_TYPE_2D:8
	beq	d88_2d
	cmp	r2,#D88_TYPE_2DD:8
	beq	d88_2dd
	cmp	r2,#D88_TYPE_2HD:8
	beq	d88_2hd
;err
	bra	fdd_dot_2d
d88_2d:
d88_2dd:
d88_2hd:
;check to of D88_TRK_TBL
	add	r0,#4:8
	adc	r1,#0:8
	jsr	read_fd_word
	cmp	r2,#02b0h      ;check TRACK1 sector point!
	bne	fdd_dot_2d
	jsr	read_fd_word
	cmp	r2,#0:8
	bne	fdd_dot_2d
;OK
	clc
	ret
;
;if m88 format error then 2D mode
fdd_dot_2d:
	jsr	reset_media
	stc
	ret
.endif
;
;-------------------------------------
;read FD data
;-------------------------------------
;in
; r0,r1 = fd address
;output
; r2    : read byte data
read_fd_byte:
	cli
	stm	(r14,#FDM_AL-R14_BASE),r0
	or	r1,#DMAM_RFSH_REQ | DMAM_MREQ | DMAM_RD
	stm	(r14,#FDM_AH-R14_BASE),r1
;next point
	add	r0,#1:8
	adc	r1,#0:8
;wait for RFSH end
read_fd_b1:
	ldm	r2,(r14,#DMA_DATA-R14_BASE)
	tst	r2,#DMAM_BUSY
	bne	read_fd_b1
;get data
	ldm	r2,(r14,#DMA_DATA-R14_BASE)
	and	r2,#0ffh:8
;clear request
	stm	(r14,#FDM_AH-R14_BASE),r2
	sti
;
	ret
;
read_fd_word:
	push	r3
	jsr	read_fd_byte
	mov	r3,r2
	jsr	read_fd_byte
	mlt	r2,#100h
	or	r2,r3
	pop	r3
	ret
;
;-------------------------------------
;initialize
;-------------------------------------
fdd_init:
.ifdef FDC_PRESET
	mov	r0,#0h:8
	stm	(r11,#FDC_TRK-R11_BASE),r0
	mov	r0,#1h:8
	stm	(r11,#FDC_SEC-R11_BASE),r0
	mov	r0,#10h:8
	stm	(r11,#FDC_DAT-R11_BASE),r0
	mov	r0,#80h:8
	stm	(r11,#FDC_MOT-R11_BASE),r0
.endif
	mov	r0,#0:8
	stm	(r10,#fdd_sts-R10_BASE),r0
;
; drive0 base addres = 1_0000H
	mov	r2,#fd_phy0
	mov	r0,#0000h:8
	mov	r1,#01h:8
	jsr	set_phy
; drive1 base addres = 7_8000H
	mov	r2,#fd_phy1
	mov	r0,#8000h
	mov	r1,#07h:8
set_phy:
	stm	(r2,#fd_phy_ml-fd_phy0),r0
	stm	(r2,#fd_phy_mh-fd_phy0),r1
	mov	r0,#0:8
	stm	(r2,#fd_phy_trk-fd_phy0),r0
	ret
;
