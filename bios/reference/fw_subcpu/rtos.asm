;----------------------------------------------------------------------------
;	Dual thread OS ‚à‚Ç‚« for MR16
;
;	Version 050426
;
;	Copyright(C) 2005 Tatsuyuki Satoh
;
;	This software is provided "AS IS", with NO WARRANTY.
;	NON-COMMERCIAL USE ONLY
;
;	Histry:
;		2005.4.26 1st release
;
;	Note:
;
;----------------------------------------------------------------------------
;
;SHOW_FDC_TIMER EQU 1

;----------------------------------------------------------------------------
;system routine
;----------------------------------------------------------------------------
	CSEG
;
;-------------------------------------
;Initialise OS (task run)
;-------------------------------------
;input
; r0 : base task entry point (loweest can't sleep task)
; r1 : base task stack size   (task + system + isr)
; r2 : heap pointer (end of stack point)
;output
; interrupt disable
; return to r0 point , run base task
;
OS_init:
	mov	r1,#OS_NEVER
	stm	(r13,#fdc_cnt-X1_WORK_BASE),r1
	mov	r15,#STACK_END
	jmp	r0
;
;-------------------------------------
;CreateTask
;-------------------------------------
;input
; r0 : entry point
; r1 : user stack size (byte)
; r2 : is suspend
;output
; r0 : task handle
OS_CreateTask:
	cli
	push	flag
	push	r0
	push	r1
	push	r2
	push	r3
	push	r4
	push	r5
	push	r6
	push	r7
	stm	(r13,#main_sp-X1_WORK_BASE),r15
;
	mov	r15,#STACK_END-64
	push	r0       ;entry point
	mov	r0,#1:8
	bra	OS_Sleep
;
;-------------------------------------
;suspend task
;-------------------------------------
;r0 : task handle
OS_Suspend:
	mov	r0,#0ffffh
	bra	OS_Sleep
;
;-------------------------------------
;Sleep
;-------------------------------------
;input
; r0 : sleep counter (0-7fffh)
OS_Sleep:
	cli
	stm	(r13,#fdc_cnt-X1_WORK_BASE),r0
	push	flag
	push	r0
	push	r1
	push	r2
	push	r3
	push	r4
	push	r5
	push	r6
	push	r7
	stm	(r13,#fdc_sp-X1_WORK_BASE),r15
;
	ldm	r15,(r13,#main_sp-X1_WORK_BASE)
	pop	r7
	pop	r6
	pop	r5
	pop	r4
	pop	r3
	pop	r2
	pop	r1
	pop	r0
	pop	flag
	ret	sti
;
;-------------------------------------
;resume task
;-------------------------------------
OS_Resume:
	cli ;;;;;;;;;;;;;;;;;;;;;;;;
	ldm	r0,(r13,#fdc_cnt-X1_WORK_BASE)
	cmp	r0,#0:8
	bne	OS_Resume1
	ret	sti
OS_Resume1:
	mov	r0,#0:8
	stm	(r13,#fdc_cnt-X1_WORK_BASE),r0
	push	flag
	push	r0
	bra	swap_fdc
;
;-------------------------------------
;OS_Timer_isr
;-------------------------------------
;overhead 14 + TASK*9 + 2 + TASK*7 + 16clock = 94clock
;
OS_Timer_isr:
;	push	flag
	push	r0
	ldm	r0,(r13,#fdc_cnt-X1_WORK_BASE)
.ifdef SHOW_FDC_TIMER
	stm	(r14,#SEG7_NUM-R14_BASE),r0
.endif
	sub	r0,#1:8
	bmi	no_swap  ;in FDC or suspend
	stm	(r13,#fdc_cnt-X1_WORK_BASE),r0
	bne	no_swap
;swap to fdc task
swap_fdc:
;	push	flag
;	push	r0
	push	r1
	push	r2
	push	r3
	push	r4
	push	r5
	push	r6
	push	r7
	stm	(r13,#main_sp-X1_WORK_BASE),r15
;
	ldm	r15,(r13,#fdc_sp-X1_WORK_BASE)
	pop	r7
	pop	r6
	pop	r5
	pop	r4
	pop	r3
	pop	r2
	pop	r1
no_swap:
	pop	r0
	pop	flag
	ret	sti
;
