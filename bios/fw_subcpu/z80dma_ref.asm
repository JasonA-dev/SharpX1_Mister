;******************************************************************************
; Z80DMA emulator for mr16
;
; 2005. 4.14
;
;******************************************************************************
;
;SHOW_DMA_TRAP equ 1
SHOW_DMA_WR equ 1 

DMA_SPT_CMD_C3 equ 1




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

;    +-----+-----+-----+-----+-----+-----+-----+-----+
;WR4 |  1  |BM/CT/BS/x |[IRQ]|[BAH]|[BAL]|  0  |  1  |
;    +-----+-----+-----+-----+-----+-----+-----+-----+
;
;    +-----+-----+-----+-----+-----+-----+-----+-----+
;TMG |-WR  |-RD  |  0  |  0  |-MREQ|-IORQ| 4/3/2/x   |
;    +-----+-----+-----+-----+-----+-----+-----+-----+
;*ealy end, 0=nagate last fall,1=nagate next raise

;
;vector[2:1]
; 00 RDY
; 01 MATCH
; 10 EOF
; 11 EOF & MATCH
;
;
;


;------------------------------------------------------------------------

	DSEG
;
DMA_BASE:
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
DMA_LEN	ds	2
DMA_AT	ds	2
DMA_BT	ds	2
DMA_MSK	ds	2
DMA_MAT	ds	2
DMA_BA	ds	2
DMA_IRQ	ds	2
DMA_PLS	ds	2
DMA_VEC	ds	2
DMA_RM	ds	2
DMA_RP	ds	2
;
DMA_RR0	ds	2
DMA_BC	ds	2 ;RR1,RR2 Byte Counter
DMA_AAC	ds	2 ;RR3,RR4 Port A Counter
DMA_BAC	ds	2 ;RR5,RR6 Port B Counter
DMA_SM	ds	2 ;status mask
;
	CSEG
;
;-----------------------------------------
; Write Entry
;-----------------------------------------
;r0 = write byte
dma_isr:
	push	flag
	push	r0
	push	r1
	push	r7
;
	ldm	r0,(r11,#DMA_WD-R11_BASE)
.ifdef SHOW_DMA_TRAP
	stm	(r14,#SEG7_NUM-R14_BASE),r0
.endif
;	tst	r0,#100h
;	beq	dma_rd_isr
;	and	r0,#0ffh:8
;	stm	(r11,#DMA_WD-R11_BASE),r0
;
	mov	r7,#DMA_BASE
	ldm	r1,(r7,#DMA_ENT-DMA_BASE)
	jsr	r1
dma_rd_isr:
	pop	r7
	pop	r1
	pop	r0
	pop	flag
	ret	sti
;
;-----------------------------------------
; Wr6 dma commands
;-----------------------------------------
dma_cmd_83: ; Disable DMA
dma_cmd_na:
	ret

dma_cmd_87:
dma_cmd_8b:
dma_cmd_8f
dma_cmd_a3:
dma_cmd_a7:
dma_cmd_ab:
dma_cmd_af
dma_cmd_b3:
dma_cmd_b7:
dma_cmd_bb:
dma_cmd_bf
dma_cmd_c3:
dma_cmd_c7:
dma_cmd_cb:
dma_cmd_cf
dma_cmd_d3:
	ret
;reset
.ifdef DMA_SPT_CMD_C3
dma_cmd_c3:
;INT,BUSRQ disable
;clear INT latch
;clear force ready
;clear auto restart
;clear WR5.CE_WAIT
;clear variavle PORTA,B TMG
	ret
.endif

;reset port a tmg
.ifdef DMA_SPT_CMD_C7
dma_cmd_c7:
;clear port A TMG
	ret
.endif

;reset port b tmg
.ifdef DMA_SPT_CMD_CB
dma_cmd_cb:
;clear port A TMG
	ret
.endif

;load
.ifdef DMA_SPT_CMD_CF
dma_cmd_cf:
;clear force ready
;load source address
;clear byte counter
;clear RR0.0
	ret
.endif

;continue
.ifdef DMA_SPT_CMD_D3
dma_cmd_d3:
;clear byte counter
;enable DMA
	ret
.endif

;disable interrupt
.ifdef DMA_SPT_CMD_AF
dma_cmd_af:
;set interrupt mask flag
	ret
.endif

;enable interrupt
.ifdef DMA_SPT_CMD_AB
dma_cmd_ab:
;clear interrupt mask flag
	ret
.endif

;reset and disable interrupt
.ifdef DMA_SPT_CMD_A3
dma_cmd_a3:
;clear INT reserved flag (RR0.3)
;clear force ready
;set interrupt mask flag
	ret
.endif

;enable after RETI
.ifdef DMA_SPT_CMD_B7
dma_cmd_b7:
;clear INT service flag
;clear force ready
;set interrupt mask flag
	ret
.endif

;read status byte
.ifdef DMA_SPT_CMD_BF
dma_cmd_bf:
;set read pointer = RR0
	ret
.endif

;Reinitialize Status
.ifdef DMA_SPT_CMD_8B
dma_cmd_8b
;clear RR0.5(=H) , RR0,4(=H)
.endif

;Read Mask Follows
.ifdef DMA_SPT_CMD_BB
dma_cmd_bb:
;get read mask follows next byte
.endif

dma_cmd_c3:
dma_cmd_c3:
dma_cmd_c3:
dma_cmd_c3:
dma_cmd_c3:
dma_cmd_c3:



;-----------------------------------------
; Wr6 write
;-----------------------------------------
dma_wr6w:
	stm	(r7,#DMA_WR6-DMA_BASE),r0
.ifdef SHOW_DMA_WR
	or	r0,#6000h
	stm	(r14,#SEG7_NUM-R14_BASE),r0
.endif	
;disable dma
	ldm	r1,(r7,#DMA_WR3-DMA_BASE)
	and	#0ffh ^ WR3_EN_DMA
	stm	(r7,#DMA_WR3-DMA_BASE),r1
;command branch
	cmp	r0,#d3+1:8
	bcc	dma_cmd_na
	mlh	r0,#8000h
	and	r0,#3e:8
	add	r0,#DMA_CMD_TBL
	mov	r0,(r0)
	jmp	r0
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
; Wr6 mask register
;-----------------------------------------
dma_wr6s:

MASk
	stm	(r7,#DMA_LEN-DMA_BASE),r2
	bra	dma_idle




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
	bne	dma_wr6w
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
	or	r0,#0000h
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
.if DMA_SPT_CMD_C3
	cmp	r0,#0c3h:8 ;RESET
	beq	dma_cmd_c3
.endif
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
	bra	dma_wr0c
dma_wr0_3:
;PortA Address High
	ldm	r2,(r7,#DMA_LEN-DMA_BASE)
	and	r2,#0ffh:8
	mlt	r1,#100h
	or	r2,r1
	stm	(r7,#DMA_LEN-DMA_BASE),r2
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
	stmw	(r7,#DMA_PLS-DMA_BASE),r1
	bra	dma_wr4_2c
dma_wr4s_1:
;VECTOR
	stmw	(r7,#DMA_VEC-DMA_BASE),r1
	bra	dma_idle
;
;-----------------------------------------------------------------------------
;wr6 cmd BB
;-----------------------------------------------------------------------------
dma_wr6_bb:
	stmw	(r7,#DMA_SM-DMA_BASE),r0
	bra	dma_idle
;
;-----------------------------------------------------------------------------
;FDD READ IRQ TRAP
;-----------------------------------------------------------------------------
dma_fdd_rd:
	mov	r0,#DMA_WR6
	ldm	r0,(r0)
	cmp	r0,#87h:8
	beq	dma_fdd_ena
	clc
	ret
;
dma_fdd_ena:
;BA = 9E00;
;AA = 0FFB;
;
;BUSRQ ON
	mov	r0,#DMAM_BUSRQ
	stm	(r14,#FDM_AH-R14_BASE),r0
;wait BUSAK
dma_fdd_rd_2:
	ldm	r0,(r14,#FDD_DATA-R14_BASE)
	tst	r0,#DMAM_BUSAK
	bne	dma_fdd_rd_2
;
;read I/O DUMMY
;	mov	r0,#DMAM_BUSRQ | DMAM_IORQ | DMAM_RD
;	stm	(r14,#FDM_AH-R14_BASE),r0
;	jsr	wait_8clk
;	jsr	wait_8clk
;	mov	r0,#DMAM_BUSRQ
;	stm	(r14,#FDM_AH-R14_BASE),r0
;
;set WR data
	ldm	r0,(r11,#FDC_DAT-R11_BASE)
	stm	(r14,#FDD_DATA-R14_BASE),r0
;
;dst address
	push	r1
	mov	r0,#DMA_BASE
	ldm	r1,(r0,#DMA_BA-DMA_BASE)
	stm	(r14,#FDM_AL-R14_BASE),r1
	add	r1,#1:8
	stm	(r0,#DMA_BA-DMA_BASE),r1
	pop	r1
;
;write memory
	mov	r0,#DMAM_BUSRQ | DMAM_MREQ | DMAM_WR
	stm	(r14,#FDM_AH-R14_BASE),r0
	jsr	wait_8clk
	jsr	wait_8clk
	mov	r0,#DMAM_BUSRQ
	stm	(r14,#FDM_AH-R14_BASE),r0
	jsr	wait_8clk
	mov	r0,#0:8
	stm	(r14,#FDM_AH-R14_BASE),r0
	stc
	ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.ifdef XXXX
	mov	r0,#DMA_WR0
	ldm	r0,(r0)
	cmp	r0,#87h:8
	bne	dma_fdd_rd_r
;BUSRQ ON
	mov	r0,#DMAM_BUSRQ
	stm	(r14,#FDM_AH-R14_BASE),r1
;
	push	r1
	push	r2
	mov	r0,#DMA_BASE
	ldm	r1,(r0,#DMA_BA-DMA_BASE)
	ldm	r2,(r0,#DMA_AA-DMA_BASE)
	ldm	r0,(r0,#DMA_WR0-DMA_BASE)
;
	tst	r0,#4:8
	beq	dma_fdd_rd_1
;swap A,B
	mov	r0,r1
	mov	r1,r2
	mov	r2,r0
dma_fdd_rd_1:
;
;wait BUSAK
dma_fdd_rd_2:
	ldm	r1,(r14,#FDM_AH-R14_BASE)
	tst	r1,#DMAM_BUSAK
	bne	dma_fdd_rd_2
;set SRC read (dummy)
	stm	(r14,#FDM_AL-R14_BASE),r1
	mov	r0,#DMAM_BUSRQ | DMAM_IORQ | DMAM_RD
	stm	(r14,#FDM_AH-R14_BASE),r0
	jsr	wait_8clk
	jsr	wait_8clk
	mov	r0,#DMAM_BUSRQ
	stm	(r14,#FDM_AH-R14_BASE),r0
	jsr	wait_8clk
;set data
	ldm	r0,(r11,#FDC_DAT-R11_BASE)
	stm	(r14,#FDD_DATA-R14_BASE),r0
;write data to memory
	stm	(r14,#FDM_AL-R14_BASE),r2
	add	r2,#1:8





	mov	r0,#DMAM_BUSRQ | DMAM_MREQ | DMAM_WR
	stm	(r14,#FDM_AH-R14_BASE),r0
	jsr	wait_8clk
	jsr	wait_8clk
	mov	r0,#DMAM_BUSRQ
	stm	(r14,#FDM_AH-R14_BASE),r0
	jsr	wait_8clk
;
	pop	r2
	pop	r1
.endif
dma_fdd_rd_r:
	ret


wait_8clk:
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
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
	mov	r0,#dma_wi
	mov	r1,#dma_ent
	stm	(r1),r0
	ret
;
