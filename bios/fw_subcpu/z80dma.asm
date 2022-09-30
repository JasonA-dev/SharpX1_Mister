;******************************************************************************
; Z80DMA emulator for mr16
;
; 2005. 4.14
;
; 2005. 5. 6 DMA enable flag fix
;
;******************************************************************************
;
;1.src address
;2.src MEM/IO , num cycle , ealy end , ce/wait
;3.dst address
;4.dst MEM/IO , num cycle , ealy start , ealy end
;
;DMA_SA
;DMA_DA
;DMA_TMG
;DMA_TMG_SCYC	equ 0003h ;bit1,0
;DMA_TMG_SMREQ	equ 0004h
;DMA_TMG_SIORQ	equ 0008h
;
PRE_CYC equ	1   ;now coding!
PRE_DIR equ	1   ;
IRQ_LOCK equ	1   ;lockup when IRQ enable
;
;-------------- 7SEG SHOW OPTION -----------------------
;SHOW_DMA_TRAP equ 1
;SHOW_DMA_WR equ 1 
;SHOW_DMA_DST_ADDR equ 1 
SHOW_DMA_BC equ 1 
;SHOW_DMA_LEN equ 1 
;
;PRESET_DMA   equ 1 
;
;    +-----+-----+-----+-----+-----+-----+-----+-----+
;WR0 |  0  | [LH]| [LL]|[AAH]|[AAL]|AtoB |SEARC|TRANS|
;    +-----+-----+-----+-----+-----+-----+-----+-----+
WR0_TRANS  equ 01h ;TRANSFER bit
WR0_SEARCH equ 02h ;SEARCH bit
WR0_ATOB   equ 04h ;direction A->B
WR0_AAL    equ 08h ;[A Address L]
WR0_AAH    equ 10h ;[A Address H]
WR0_LL     equ 20h ;[Length L]
WR0_LH     equ 40h ;[Length H]

;    +-----+-----+-----+-----+-----+-----+-----+-----+
;WR1 |  0  |[TMG]|AFIX |AINC | AIO |  1  |  0  |  0  |
;    +-----+-----+-----+-----+-----+-----+-----+-----+
WR1_A_IO	equ 08h ; PortA Mem / IO select
WR1_A_INC	equ 10h ; PortA DEC / INC select
WR1_A_FIX	equ 10h ; PortA FIX / INC,DEC select

;    +-----+-----+-----+-----+-----+-----+-----+-----+
;WR2 |  0  |[TMG]|BFIX |BINC | BIO |  1  |  0  |  0  |
;    +-----+-----+-----+-----+-----+-----+-----+-----+
WR2_B_IO	equ 08h ; PortB Mem / IO select
WR2_B_INC	equ 10h ; PortB DEC / INC select
WR2_B_FIX	equ 10h ; PortB FIX / INC,DEC select

;    +-----+-----+-----+-----+-----+-----+-----+-----+
;WR3 |  1  | ENA | ENI |[MAT]|[MSK]| SOM |  0  |  0  |
;    +-----+-----+-----+-----+-----+-----+-----+-----+
WR3_STOP_ON_MAT	equ 08h
WR3_EN_INT	equ 20h ;enable INT
WR3_EN_DMA	equ 40h ;enable DMA
;
;    +-----+-----+-----+-----+-----+-----+-----+-----+
;WR4 |  1  |BM/CT/BS/x |[IRQ]|[BAH]|[BAL]|  0  |  1  |
;    +-----+-----+-----+-----+-----+-----+-----+-----+
;
;    +-----+-----+-----+-----+-----+-----+-----+-----+
;TMG |-WR  |-RD  |  0  |  0  |-MREQ|-IORQ| 4/3/2/x   |
;    +-----+-----+-----+-----+-----+-----+-----+-----+
;*ealy end, 0=nagate last fall,1=nagate next raise
;
;    +-----+-----+-----+-----+-----+-----+-----+-----+
;WR5 |  1  |  0  | RST | CWT | RDY |  0  |  1  |  0  |
;    +-----+-----+-----+-----+-----+-----+-----+-----+
;
;additional
WR5_RDY_DIR	equ 08h ;RDY active level 0=Low,1=High
WR5_CE_WAIT	equ 10h ;CE/WAIT 0=CE , 1=CE/WAIT
WR5_AUTO_RESTART equ 20h ;0=END , 1=RESTART
;aditional
WR5_FORCE_RDY	equ 01h ;ForceReady
;
;
;vector[2:1]
; 00 RDY
; 01 MATCH
; 10 EOF
; 11 EOF & MATCH
;
;

;-------------------------------------------------------------------------
	DSEG
;
DMA_BASE_T:
;
DMA_RR0	ds	2
DMA_BC	ds	2 ;RR1,RR2 Byte Counter
DMA_AAC	ds	2 ;RR3,RR4 Port A Counter
DMA_BAC	ds	2 ;RR5,RR6 Port B Counter
.if PRE_CYC
DMA_CTA ds	2 ;controll port of portA
DMA_CTB ds	2 ;controll port of portB
DMA_DFA ds	2 ;fix/inc/dec
DMA_DFB ds	2 ;fix_inc_dec
.endif
;
.if PRE_DIR
DMA_SRC_B ds	2 ;base pointer of source
DMA_DST_B ds	2 ;base pointer of distination
.endif
DMA_BASE: ;
;
DMA_ENT	ds	2	;DMA WR entry point
;
DMA_WR0	ds	2
DMA_WR1	ds	2
DMA_WR2	ds	2
DMA_WR3	ds	2
DMA_WR4	ds	2
DMA_WR5	ds	2
DMA_WR6	ds	2
;
DMA_AA	ds	2
DMA_BA	ds	2
DMA_LEN	ds	2
DMA_AT	ds	2
DMA_BT	ds	2
DMA_MSK	ds	2
DMA_MAT	ds	2
DMA_IRQ	ds	2
DMA_PLS	ds	2
DMA_VEC	ds	2
DMA_RM	ds	2
DMA_RP	ds	2
;
	CSEG
;
;-----------------------------------------
; Z80DMA Write Entry
;-----------------------------------------
;r0 = write byte
dma_isr:
	push	flag
	push	r0
	push	r1
	push	r7
;CMD Write
	ldm	r0,(r11,#DMA_WD-R11_BASE)
	or	r0,r0
	bmi	dma_no_cmd
.ifdef SHOW_DMA_TRAP
	stm	(r14,#SEG7_NUM-R14_BASE),r0
.endif
	mov	r1,#8000h
	stm	(r11,#DMA_WD-R11_BASE),r1
;
	mov	r7,#DMA_BASE
	ldm	r1,(r7,#DMA_ENT-DMA_BASE)
;
	jsr	r1
dma_no_cmd:
;RDY IRQ
	ldm	r0,(r14,#DMA_DATA-R14_BASE)
	tst	r0,#DMAM_RDY
	beq	dma_no_rdy
	jsr	dma_rdy_pole
dma_no_rdy:
	pop	r7
	pop	r1
	pop	r0
	pop	flag
	ret	sti
;
;-----------------------------------------
; Wr6 COMMAND
;-----------------------------------------

dma_cmd_83: ; Disable DMA
dma_cmd_8b:
dma_cmd_8f
dma_cmd_a3:
dma_cmd_a7:
dma_cmd_ab:
dma_cmd_af
dma_cmd_b7:
dma_cmd_bf
dma_cmd_c3:
dma_cmd_c7:
dma_cmd_cb:
;
dma_cmd_na:
dma_disable:
;clear force ready
	ldm	r1,(r7,#DMA_WR5-DMA_BASE)
	and	r1,#0ffh ^ WR5_FORCE_RDY:8
dma_disable2:
	stm	(r7,#DMA_WR5-DMA_BASE),r1
;disable dma
	ldm	r1,(r7,#DMA_WR3-DMA_BASE)
	and	r1,#0ffh ^ WR3_EN_DMA:8
	stm	(r7,#DMA_WR3-DMA_BASE),r1
	ret

;--------------------------------------
dma_cmd_87: ; Enable DMA
	ldm	r1,(r7,#DMA_WR3-DMA_BASE)
	or	r1,#WR3_EN_DMA:8
	stm	(r7,#DMA_WR3-DMA_BASE),r1
enable_dma:
;RDY IRQ controll port
	ldm	r0,(r7,#DMA_WR5-DMA_BASE)
	ldm	r1,(r7,#DMA_WR3-DMA_BASE)
	or	r0,r1
	stm	(r14,#DMA_RDY-R14_BASE),r0 ;bit0=force,bit3=dir,bit6=enable
	ret
;
;--------------------------------------
dma_cmd_b3: ; Force Ready
;set force ready
	ldm	r1,(r7,#DMA_WR5-DMA_BASE)
	or	r1,#WR5_FORCE_RDY:8
	bra	dma_disable2
;
;--------------------------------------
dma_cmd_bb: ; READ MASK FOLLOWS
	mov	r1,#dma_cmd_bbw
	stm	(r7,#DMA_ENT-DMA_BASE),r1
	bra	dma_disable2
;
dma_cmd_bbw:
;	stm	(r7,DMA_RR_MASK),r0
;	choise 1st RR
	bra	dma_idle
;
;--------------------------------------
dma_cmd_cf: ; Load
	mov	r1,#DMA_BASE_T
	ldm	r0,(r7,#DMA_AA-DMA_BASE)
	stm	(r1,#DMA_AAC-DMA_BASE_T),r0
	ldm	r0,(r7,#DMA_BA-DMA_BASE)
	stm	(r1,#DMA_BAC-DMA_BASE_T),r0
;through to dma_cmd_d3

;--------------------------------------
dma_cmd_d3: ;continue
.if PRE_DIR
;source / direction select
	push	r2
	push	r3
	mov	r1,#DMA_BASE_T    ;portA = src
	mov	r2,#DMA_BASE_T+2  ;portB = dst
	mov	r3,r1
;
	ldm	r0,(r7,#DMA_WR0-DMA_BASE)
	tst	r0,#WR0_ATOB:8
	bne	dma_atob
;BtoA
	add	r1,#2:8
	sub	r2,#2:8
dma_atob:
	stm	(r3,#DMA_SRC_B-DMA_BASE_T),r1 ;src
	stm	(r3,#DMA_DST_B-DMA_BASE_T),r2 ;dst
;
.if PRE_CYC
;source
	push	r2
	mov	r2,r1
	jsr	dma_setup_cyc
	or	r0,#DMAM_RD
	stm	(r2,#DMA_CTA-DMA_BASE_T),r0
;dst
	pop	r2
	jsr	dma_setup_cyc
	or	r0,#DMAM_WR ;;;;;;;;;;;;;; if kahen cycle ;;;;;;;;;;;;;;;;;;;;
	stm	(r2,#DMA_CTA-DMA_BASE_T),r0
.endif
	pop	r3
	pop	r2
.endif
;



	mov	r1,#DMA_BASE_T
	ldm	r0,(r7,#DMA_LEN-DMA_BASE)
;0000 -> 10000h
;0001 -> 00002h
;ffff -> 10000h
	or	r0,r0
	bne	dma_bc_not0
	sub	r0,#1:8 ;0000h -> 0ffffh
dma_bc_not0:
	stm	(r1,#DMA_BC-DMA_BASE_T),r0
	bra	dma_disable
;
;-----------------------------------------
; Wr6 write
;-----------------------------------------
dma_wr6w:
	stm	(r7,#DMA_WR6-DMA_BASE),r0
.ifdef SHOW_DMA_WR
	or	r0,#6000h
	stm	(r14,#SEG7_NUM-R14_BASE),r0
	and	r0,#0ffh:8
.endif
;command branch
	cmp	r0,#0d3h+1:8
	bcc	dma_cmd_na
	mlh	r0,#8000h
	and	r0,#03eh:8
	add	r0,#DMA_CMD_TBL
	ldm	r0,(r0)
	jmp	r0
;
;
DMA_CMD_TBL:
	dw	dma_cmd_83,dma_cmd_87,dma_cmd_8b,dma_cmd_8f
	dw	dma_cmd_na,dma_cmd_na,dma_cmd_na,dma_cmd_na
	dw	dma_cmd_a3,dma_cmd_a7,dma_cmd_ab,dma_cmd_af
	dw	dma_cmd_b3,dma_cmd_b7,dma_cmd_bb,dma_cmd_bf
	dw	dma_cmd_c3,dma_cmd_c7,dma_cmd_cb,dma_cmd_cf
	dw	dma_cmd_d3
;
;-----------------------------------------
; Write IDLE (new WR)
;-----------------------------------------
;r0 = write byte
dma_wi:
	tst	r0,#87h:8
	beq	dma_wr2c
	tst	r0,#83h:8
	beq	dma_wr1c
	tst	r0,#80h:8
	beq	dma_wr0c
;80-ff
	tst	r0,#03h:8
	beq	dma_wr3c
	tst	r0,#02h:8
	beq	dma_wr4c
	tst	r0,#01h:8

	jne	dma_wr6w
;;;;;	bne	dma_wr6w
;wr5
.ifdef SHOW_DMA_WR
	or	r0,#5000h
	stm	(r14,#SEG7_NUM-R14_BASE),r0
.endif	
	mov	r1,#dma_wr2w
	stm	(r7,#DMA_WR5-DMA_BASE),r0
	ret
;
;-----------------------------------------------------------------------------
;check wr exit or continue
;-----------------------------------------------------------------------------
dma_wr1c:
	stm	(r7,#DMA_WR1-DMA_BASE),r0
.ifdef SHOW_DMA_WR
	or	r0,#1000h
	stm	(r14,#SEG7_NUM-R14_BASE),r0
.endif
	mov	r1,#dma_wr1w
dma_chk_40:
	tst	r0,#40h:8
dma_chk:
	bne	dma_sub
dma_idle:
.ifdef SHOW_DMA_WR
	or	r0,#0e00h
	stm	(r14,#SEG7_NUM-R14_BASE),r0
.endif
	mov	r1,#dma_wi
dma_sub:
	stm	(r7,#DMA_ENT-DMA_BASE),r1
	ret
;
dma_wr0c:
	stm	(r7,#DMA_WR0-DMA_BASE),r0
.ifdef SHOW_DMA_WR
	stm	(r14,#SEG7_NUM-R14_BASE),r0
.endif
	mov	r1,#dma_wr0w
	tst	r0,#78h:8
	bra	dma_chk
;
dma_wr2c:
	stm	(r7,#DMA_WR2-DMA_BASE),r0
.ifdef SHOW_DMA_WR
	or	r0,#2000h
	stm	(r14,#SEG7_NUM-R14_BASE),r0
.endif
	mov	r1,#dma_wr2w
	bra	dma_chk_40
;
dma_wr3c:
	stm	(r7,#DMA_WR3-DMA_BASE),r0
.ifdef SHOW_DMA_WR
	or	r0,#3000h
	stm	(r14,#SEG7_NUM-R14_BASE),r0
.endif
.if PRE_DIR
	tst	r0,#WR3_EN_DMA:8
	beq	wr3_dis_dma
	jsr	enable_dma
wr3_dis_dma:
.endif
	mov	r1,#dma_wr3w
	tst	r0,#18h:8
	bra	dma_chk
;
dma_wr4c:
	stm	(r7,#DMA_WR4-DMA_BASE),r0
.ifdef SHOW_DMA_WR
	or	r0,#4000h
	stm	(r14,#SEG7_NUM-R14_BASE),r0
.endif
	mov	r1,#dma_wr4w
	tst	r0,#1ch:8
	bra	dma_chk
;
;-----------------------------------------------------------------------------
;wr0 sub reg
;-----------------------------------------------------------------------------
dma_wr0w:
	mov	r1,r0
	ldm	r0,(r7,#DMA_WR0-DMA_BASE)
	tst	r0,#08h:8
	beq	dma_wr0_1
;PortA Address Low
	xor	r0,#08h:8
	ldm	r2,(r7,#DMA_AA-DMA_BASE)
	and	r2,#0ff00h
dma_aa_w:
	or	r2,r1
	stm	(r7,#DMA_AA-DMA_BASE),r2
	bra	dma_wr0c
dma_wr0_1:
	tst	r0,#10h:8
	beq	dma_wr0_2
;PortA Address High
	xor	r0,#10h:8
	ldm	r2,(r7,#DMA_AA-DMA_BASE)
	and	r2,#0ffh:8
	mlt	r1,#100h
	bra	dma_aa_w
dma_wr0_2:
	tst	r0,#20h:8
	beq	dma_wr0_3
;Length L
	xor	r0,#20h:8
	ldm	r2,(r7,#DMA_LEN-DMA_BASE)
	and	r2,#0ff00h
	or	r2,r1
	stm	(r7,#DMA_LEN-DMA_BASE),r2
.ifdef SHOW_DMA_LEN
	stm	(r14,#SEG7_NUM-R14_BASE),r2
.endif
	bra	dma_wr0c
dma_wr0_3:
;PortA Address High
	ldm	r2,(r7,#DMA_LEN-DMA_BASE)
	and	r2,#0ffh:8
	mlt	r1,#100h
	or	r2,r1
	stm	(r7,#DMA_LEN-DMA_BASE),r2
.ifdef SHOW_DMA_LEN
	stm	(r14,#SEG7_NUM-R14_BASE),r2
.endif
	bra	dma_idle
;-----------------------------------------------------------------------------
;wr1
;-----------------------------------------------------------------------------
dma_wr1w:
	stm	(r7,#DMA_AT-DMA_BASE),r0
	bra	dma_idle
;-----------------------------------------------------------------------------
;wr2
;-----------------------------------------------------------------------------
dma_wr2w:
	stm	(r7,#DMA_BT-DMA_BASE),r0
	bra	dma_idle
;-----------------------------------------------------------------------------
;wr3
;-----------------------------------------------------------------------------
dma_wr3w:
	mov	r1,r0
	ldm	r0,(r7,#DMA_WR3-DMA_BASE)
	tst	r0,#08h:8
	beq	dma_wr3_1
;Mask
	xor	r0,#08h:8
	stm	(r7,#DMA_MSK-DMA_BASE),r1
	bra	dma_wr3c
dma_wr3_1:
;match
	stm	(r7,#DMA_MAT-DMA_BASE),r1
	bra	dma_idle
;-----------------------------------------------------------------------------
;wr4
;-----------------------------------------------------------------------------
dma_wr4w:
	mov	r1,r0
	ldm	r0,(r7,#DMA_WR4-DMA_BASE)
	tst	r0,#04h:8
	beq	dma_wr4_1
;PortB Address Low
	xor	r0,#04h:8
	ldm	r2,(r7,#DMA_BA-DMA_BASE)
	and	r2,#0ff00h
dma_ba_w:
	or	r2,r1
	stm	(r7,#DMA_BA-DMA_BASE),r2
	bra	dma_wr4c
dma_wr4_1:
	tst	r0,#08h:8
	beq	dma_wr4_2
;PortA Address High
	xor	r0,#08h:8
	ldm	r2,(r7,#DMA_BA-DMA_BASE)
	and	r2,#0ffh:8
	mlt	r1,#100h
	bra	dma_ba_w
dma_wr4_2:
;IRQ
	mov	r0,r1
dma_wr4_2c:
	stm	(r7,#DMA_IRQ-DMA_BASE),r0
.ifdef SHOW_DMA_WR
	or	r0,#4100h
	stm	(r14,#SEG7_NUM-R14_BASE),r0
.endif
.ifdef IRQ_LOCK
	tst	r0,#63h:8
	beq	dma_no_irq
	mov	r0,#0eee0h
	stm	(r14,#SEG7_NUM-R14_BASE),r0
	cli
	bra	$
dma_no_irq:

.endif
	mov	r1,#dma_wr4sw
	tst	r0,#18h:8
	bra	dma_chk
;-----------------------------------------------------------------------------
;wr4 IRQ sub
;-----------------------------------------------------------------------------
dma_wr4sw:
	mov	r1,r0
	ldm	r0,(r7,#DMA_IRQ-DMA_BASE)
	tst	r0,#08h:8
	beq	dma_wr4s_1
;PULSE
	xor	r0,#08h:8
	stw	(r7,#DMA_PLS-DMA_BASE),r1
	bra	dma_wr4_2c
dma_wr4s_1:
;VECTOR
	stw	(r7,#DMA_VEC-DMA_BASE),r1
	bra	dma_idle
;
;-----------------------------------------------------------------------------
;wr6 cmd BB
;-----------------------------------------------------------------------------
dma_wr6_bb:
	stw	(r7,#DMA_RM-DMA_BASE),r1
	bra	dma_idle
;
;-----------------------------------------------------------------------------
;FDD RDY TRAP
;-----------------------------------------------------------------------------
;r0 = temporaly work
;r1 = source       base pointer
;r2 = distination  base pointer
;
dma_rdy_pole:
	push	r1
	push	r2
;BUSRQ ON and wait BUSAK
	jsr	get_bus
;----- burst/continus mode loop -----
dma_poll_loop:
.if PRE_DIR
	mov	r2,#DMA_BASE_T
	ldm	r2,(r2,#DMA_SRC_B-DMA_BASE_T)
.else
;direction
	mov	r2,#DMA_BASE_T
	mov	r0,#DMA_BASE_T+2 ;dst base
	ldm	r1,(r2,#DMA_WR0-DMA_BASE_T)
	tst	r1,#04h:8        ;WR0
	bne	dma_atob
;swap B to A
	add	r2,#2:8 ;src = PortB
	sub	r0,#2:8 ;dst = PortA
dma_atob:
	push	r0
.endif
;---------------------
;source cycle
;---------------------
.if PRE_CYC
;set ADDR
	ldm	r0,(r2,#DMA_AAC-DMA_BASE_T) ; DMA_AAC or DMA_BAC
	stm	(r14,#FDM_AL-R14_BASE),r0  ; 0:T1 raise
	ldm	r0,(r2,#DMA_CTA-DMA_BASE_T); 2
	stm	(r14,#FDM_AH-R14_BASE),r0  ; 4:T1 fall
;increment address
	push	r1                         ; 6
	ldm	r0,(r2,#DMA_AAC-DMA_BASE_T); 8:T2 Raise
	ldm	r1,(r2,#DMA_DFA-DMA_BASE_T);10
	add	r0,r1                      ;11
	add	r0,#0:8
	stm	(r2,#DMA_AAC-DMA_BASE_T),r0;14:T3 Raise
	pop	r1                         ;16
	mov	r0,#DMAM_BUSRQ             ;18:
	stm	(r14,#FDM_AH-R14_BASE),r0  ;20:T3 Fall
.else
	jsr	dma_set
	or	r0,#DMAM_RD
	stm	(r14,#FDM_AH-R14_BASE),r0  ; 2:T1 Fall
	jsr	wait_12clk                 ;12:
	mov	r0,#DMAM_BUSRQ             ; 2:
	stm	(r14,#FDM_AH-R14_BASE),r0  ; 2:T3 Fall
.endif
;---------------------
;read data
;---------------------
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;sorcerian break fix test
	jsr	wait_16clk
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
	ldm	r0,(r14,#DMA_DATA-R14_BASE) ;2:
	stm	(r14,#DMA_DATA-R14_BASE),r0 ;2:
.if PRE_DIR
	mov	r2,#DMA_BASE_T
	ldm	r2,(r2,#DMA_DST_B-DMA_BASE_T)
.else
	pop	r2
.endif
;---------------------
;Distination Cycle
;---------------------
.ifdef SHOW_DMA_DST_ADDR
;ADDR
	ldm	r0,(r2,#DMA_AAC-DMA_BASE_T)
	stm	(r14,#SEG7_NUM-R14_BASE),r0
.endif
.if PRE_CYC
	ldm	r0,(r2,#DMA_AAC-DMA_BASE_T)
	stm	(r14,#FDM_AL-R14_BASE),r0  ; 0:T1 raise , Assert DST
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;sorcerian break fix test
;late WR fall
	ldm	r0,(r2,#DMA_CTA-DMA_BASE_T)
	xor	r0,#DMAM_WR
	stm	(r14,#FDM_AH-R14_BASE),r0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	ldm	r0,(r2,#DMA_CTA-DMA_BASE_T); 2
	stm	(r14,#FDM_AH-R14_BASE),r0  ; 4:T1 fall  , Assert DST REQ,WR
;increment address
	push	r1                         ; 6
	ldm	r0,(r2,#DMA_AAC-DMA_BASE_T); 8:T2 Raise
	ldm	r1,(r2,#DMA_DFA-DMA_BASE_T);10
	add	r0,r1                      ;11
	add	r0,#0:8                    ;12 T2 Fall
	stm	(r2,#DMA_AAC-DMA_BASE_T),r0;14
	pop	r1                         ;16:T3 Raise
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;sorcerian break fix test
;ealy WR raise
;
	jsr	wait_16clk
;
	ldm	r0,(r2,#DMA_CTA-DMA_BASE_T)
	xor	r0,#DMAM_WR
	stm	(r14,#FDM_AH-R14_BASE),r0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	mov	r0,#DMAM_BUSRQ             ;18
	stm	(r14,#FDM_AH-R14_BASE),r0  ;20:T3 Fall , Deassert Cycle
.else
	jsr	dma_set
;T1 Fall
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	or	r0,#DMAM_WR
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	stm	(r14,#FDM_AH-R14_BASE),r0 ;2:T1 Fall
	jsr	wait_4clk                 ;4
	or	r0,#DMAM_WR               ;2
	stm	(r14,#FDM_AH-R14_BASE),r0 ;2:T2 Fall
	jsr	wait_4clk                 ;4
	mov	r0,#DMAM_BUSRQ            ;2
	stm	(r14,#FDM_AH-R14_BASE),r0 ;2 T3 Fall
;	jsr	wait_4clk
.endif
;---------------------
;byte counter
;---------------------
	mov	r2,#DMA_BASE_T
	ldm	r0,(r2,#DMA_BC-DMA_BASE_T)
	sub	r0,#1:8
.ifdef SHOW_DMA_BC
	stm	(r14,#SEG7_NUM-R14_BASE),r0
.endif
	bcc	dma_no_eob
;---------------------
;end fo block
;---------------------
;dma_eob:
	ldm	r0,(r2,#DMA_WR3-DMA_BASE_T)
	and	r0,#0ffh ^ WR3_EN_DMA:8
	stm	(r2,#DMA_WR3-DMA_BASE_T),r0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	mov	r0,#0:8
	stm	(r14,#DMA_RDY-R14_BASE),r0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	bra	dma_poll_r1
;---------------------
;not end fo block
;---------------------
dma_no_eob:
	stm	(r2,#DMA_BC-DMA_BASE_T),r0
;---------------------
;burst/continus mode check
;---------------------
	ldm	r0,(r2,#DMA_WR4-DMA_BASE_T)
	tst	r0,#60h:8
	beq	dma_poll_r1  ; byte mode
;RDY check
	ldm	r0,(r14,#DMA_DATA-R14_BASE)
	tst	r0,#DMAM_RDY
	bne	dma_poll_loop ; loop when not byte mode and RDY
;end of RDY
	ldm	r0,(r2,#DMA_WR4-DMA_BASE_T)
	tst	r0,#20h:8
	bne	dma_poll_r2 ;when continus mode , bus hook and end
dma_poll_r1:
;release BUSREQ
	mov	r0,#0:8
	stm	(r14,#FDM_AH-R14_BASE),r0
dma_poll_r2:
	pop	r2
	pop	r1
	ret
;
wait_16clk:
	push	r0
	pop	r0
wait_12clk:
	push	r0
	pop	r0
wait_8clk:
	push	r0
	pop	r0
wait_4clk:
	nop
	ret
;
.if PRE_CYC
;---------------------
;DMA port setup
;---------------------
;in
;  r2 = DMA_BASE_T = PORTA , DMA_BASE_T+2 = PORTB
;out
;  r0 = memory cycle value
dma_setup_cyc:
	ldm	r1,(r2,#DMA_WR1-DMA_BASE_T) ; DMA_WR1 or DMA_WR2
	mov	r0,#0:8    ;FIX value
	tst	r1,#20h:8  ;FIX address?
	bne	dma_setup_cyc1
	mov	r0,#1:8    ;INC value
	tst	r1,#10h:8  ;INC
	bne	dma_setup_cyc1
	sub	r0,#2:8    ;DEC value
dma_setup_cyc1:
	stm	(r2,#DMA_DFA-DMA_BASE_T),r0 ; DMA_DFA or DMA_DFB
;
	mov	r0,#DMAM_BUSRQ | DMAM_MREQ
	tst	r1,#08h:8   ;I/O or memory?
	beq	dma_setup_cyc2
	xor	r0,#DMAM_MREQ | DMAM_IORQ
dma_setup_cyc2:
	ret
.else
;---------------------
;DMA port setup
;---------------------
;r2 = DMA_BASE_T = PORTA , DMA_BASE_T+2 = PORTB
dma_set:
	ldm	r0,(r2,#DMA_AAC-DMA_BASE_T) ; DMA_AAC or DMA_BAC
	stm	(r14,#FDM_AL-R14_BASE),r0
	ldm	r1,(r2,#DMA_WR1-DMA_BASE_T) ; DMA_WR1 or DMA_WR2
	tst	r1,#20h:8  ;FIX address?
	bne	dma_rc2
	add	r0,#1:8
	tst	r1,#10h:8  ;INC ?
	bne	dma_rc1
	sub	r0,#2:8
dma_rc1:
	stm	(r2,#DMA_AAC-DMA_BASE_T),r0 ; DMA_AAC or DMA_BAC
dma_rc2:
	mov	r0,#DMAM_BUSRQ | DMAM_MREQ
	tst	r1,#08h:8   ;I/O or memory?
	beq	dma_rc3
	xor	r0,#DMAM_MREQ | DMAM_IORQ
dma_rc3:
	ret
.endif
;
.ifdef GET_BUS_BYPASS
.else
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;BUSRQ ON
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
get_bus:
	jsr	wait_rfsh_req
	bra	get_bus2
get_bus1:
	mov	r0,#DMAM_BUSRQ
	stm	(r14,#FDM_AH-R14_BASE),r0
get_bus2:
	ldm	r0,(r14,#DMA_DATA-R14_BASE)
	tst	r0,#DMAM_BUSAK
	bne	get_bus1
	ret
.endif

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;wait rfsh cycle
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
wait_rfsh_req:
	ldm	r0,(r14,#DMA_DATA-R14_BASE)
	tst	r0,#DMAM_BUSY
	bne	wait_rfsh_req
dma_bus_poff:
	mov	r0,#0:8
	stm	(r14,#FDM_AH-R14_BASE),r0
	ret
;
;-----------------------------------------------------------------------------
;FDD WRITE IRQ TRAP
;-----------------------------------------------------------------------------
dma_fdd_wr:
	ret
;
;-----------------------------------------------------------------------------
;DMA_IDLE
;-----------------------------------------------------------------------------
dma_init:
	mov	r0,#DMA_BASE
	mov	r1,#dma_wi
	stm	(r0,#DMA_ENT-DMA_BASE),r1
;
	mov	r1,#8000h
	stm	(r11,#DMA_WD-R11_BASE),r1
;
.ifdef PRESET_DMA
	mov	r1,#87h:8
	stm	(r0,#DMA_WR6-DMA_BASE),r1
	mov	r1,#3000h
;	mov	r1,#8000h
	stm	(r0,#DMA_BA-DMA_BASE),r1
.endif
	ret
;
