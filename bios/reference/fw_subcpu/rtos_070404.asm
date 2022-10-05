;******************************************************************************
; MR16 Mini ReaTime OS
; Version 2007. 4. 4
;
; Copyright(C) 2005,2007 Tatsuyuki Satoh
;
; This software is provided "AS IS", with NO WARRANTY.
; NON-COMMERCIAL USE ONLY
;
; Histry:
;  2007. 4. 4 cleanup and release
;  2005. 4.12 1st release
;
; Note:
;
;******************************************************************************

;----------------------------------------------------------------------------
;SYSTEM WORK AREA
;----------------------------------------------------------------------------
	DSEG
;
OS_COMMON:
os_heap		ds	2                     ; pointer of OS heap
os_time		ds	2                     ; OS Grobal Time
os_cur_tcb	ds	2                     ; pointer of current TCB
os_end_tcb	ds	2                     ; end of active TCB
;
os_tcb		ds	MAX_TASK*OS_TCB_SIZE  ; TCB work area
os_tcb_e:
;
;----------------------------------------------------------------------------
;system routine
;----------------------------------------------------------------------------
	CSEG
;
;-------------------------------------
;OS_GetCurTask
;-------------------------------------
;TCB *OS_GetCurTask(void)
OS_GetCurTask:
	mov	r0,#os_cur_tcb
	ldm	r0,(r0)
	ret
;
;-------------------------------------
;OS_GetTick
;-------------------------------------
;TCB *OS_GetTick(void)
OS_GetTick:
	mov	r0,#OS_COMMON
	ldm	r0,(r0,#os_time-OS_COMMON)
	ret
;
;-------------------------------------
;allocate and build task
;-------------------------------------
build_task:
	mov	r0,r2
	mov	r1,r3
	mov	r2,r4
	mov	r3,#OS_COMMON
;TCB max check
	ldm	r4,(r3,#os_end_tcb-OS_COMMON)
	cmp	r4,#os_tcb_e
	blo	os_bt1
;TASK FULL
	ret
os_bt1:
	ldm	r5,(r3,#os_heap-OS_COMMON)
;save entry PC to task stack
	sub	r5,#2:8
	stm	(r5),r0 ;PC
	sub	r1,#2:8
;set task info.
	sub	r5,#SYS_ST_END+8-SYS_ST_TOP:8
	sub	r1,#SYS_ST_END+8-SYS_ST_TOP:8
	stm	(r4,#OS_TCB_SP),r5            ;SP
	stm	(r4,#OS_TCB_TMR),r2           ;timer(suspend)
;allocate task stack
	mov	r0,#5555h
os_bt2:
	sub	r5,#2:8
	stm	(r5),r0 ;for stack over check
	sub	r1,#2:8
	bne	os_bt2
;// save new stack end
	stm	(r3,#os_heap-OS_COMMON),r5
;update TCB end point
	mov	r0,r4 ;save current task point
	add	r4,#OS_TCB_SIZE:8
	stm	(r3,#os_end_tcb-OS_COMMON),r4
;
	ret
;
;-------------------------------------
;context swap
;
;note:
; choise swap register with push/pop inst.
;-------------------------------------
;input
; r0     = swap context
; (sp-8) = saved PC
; (sp-6) = saved freg
; (sp-4) = saved r0
; (sp-2) = saved r1
; (sp  ) = saved r2
;output
; none (swap task)
;
context_swap
	mov	r2,#os_cur_tcb
	ldm	r1,(r2)
	cmp	r0,r1
	beq	no_swap
;save context
	push	r3
	push	r4
	push	r5
	push	r6
	push	r7
	push	r8
	push	r9
	push	r10
	push	r11
	push	r12
;	push	r13
;	push	r14
	stm	(r1,#OS_TCB_SP),r15 ;save SP
	stm	(r2),r0             ;set new current task
context_load:
	ldm	r15,(r0,#OS_TCB_SP) ;load SP
SYS_ST_TOP:
;	pop	r14
;	pop	r13
	pop	r12
	pop	r11
	pop	r10
	pop	r9
	pop	r8
	pop	r7
	pop	r6
	pop	r5
	pop	r4
	pop	r3
SYS_ST_END:
;	ldm	r0,(r15,#6) ; // flag
;	tst	r0,#10h:8
;	bne	no_swap
;
;	pop	r2
;	pop	r1
;	pop	r0
;	pop	flag
;	ret	cli
;
no_swap:
	pop	r2
	pop	r1
	pop	r0
	pop	flag
	ret	sti  ;load PC
;
;-------------------------------------
;Initialise OS (task run)
;-------------------------------------
;input
; r2 : base task entry point (loweest can't sleep task)
; r3 : base task stack size   (task + system + isr)
; r4 : heap pointer (end of stack point)
;output
; interrupt disable
; return to r0 point , run base task
;
OS_init:
	cli
	mov	r1,#OS_COMMON
;save heap top
	stm	(r1,#os_heap-OS_COMMON),r4
	mov	r15,r4
;reset TCB table
	mov	r0,#os_tcb
	stm	(r1,#os_cur_tcb-OS_COMMON),r0 ;current task
	stm	(r1,#os_end_tcb-OS_COMMON),r0 ;current task
;adjust SP to return point
	sub	r15,#2:8 ;adjust return point
;return point = r0
	mov	r4,#OS_RUN:8
;retrun to r0 on basetask
	bra	build_task
;
;-------------------------------------
;CreateTask
;-------------------------------------
;u16 OS_CreateTask(void (*entry_point)(void),stack_size,start_state)
;
; r2 : entry point
; r3 : user stack size (byte)
; r4 : is suspend
;output
; r0 : task handle
OS_CreateTask:
	cli
	jsr	build_task
;
	cmp	r2,#OS_RUN:8
	bne	osctr
;
	push	flag
	push	r0
	push	r1
	push	r2
	bra	context_swap
osctr:
	ret	sti
;
;-------------------------------------
;suspend task
;-------------------------------------
;r2 : task handle
OS_Suspend:
	push	flag
	cli
	push	r0
	push	r1
	push	r2
;// get current task pointer
	mov	r0,r2
	mlt	r0,#OS_TCB_SIZE:8
	add	r0,#os_tcb
	mov	r1,#OS_NEVER
	stm	(r0,#OS_TCB_TMR),r1
task_out:
	mov	r1,#os_cur_tcb
	ldm	r1,(r1)
	cmp	r0,r1
	bne	no_swap

;sleep current task
to1:
	sub	r0,#OS_TCB_SIZE:8
	ldm	r1,(r0,#OS_TCB_TMR)
	cmp	r1,#OS_RUN:8
	bne	to1
	bra	context_swap
;
;-------------------------------------
;resume task
;-------------------------------------
;r2 : task number
OS_Resume:
	push	flag
	cli
	push	r0
	push	r1
	push	r2
	mlt	r2,#OS_TCB_SIZE:8
	add	r2,#os_tcb
	mov	r1,#0:8
	stm	(r2,#OS_TCB_TMR),r1
;// カレントタスクがターゲットタスクよりプライオリティーがしたの場合
;// ターゲットタスクに切り替える
	mov	r1,#os_cur_tcb
	ldm	r1,(r1)
	cmp	r1,r0
	blo	context_swap
;	jlo	context_swap
	bra	no_swap
;
;-------------------------------------
;Sleep
;-------------------------------------
;void OS_Sleep(u16 sleep_time)
; sleep_time : (0-7fffh,OS_NEVER)
OS_Sleep:
	push	flag
	cli
	push	r0
	push	r1
	push	r2
	cmp	r2,#0
	beq	no_swap
;
	mov	r0,#os_cur_tcb
	ldm	r0,(r0)
;// timser set
	stm	(r0,#OS_TCB_TMR),r2
;// swap other task
;	bra	task_out
	jmp	task_out
;
;-------------------------------------
;OS_Timer_isr
;-------------------------------------
;interrupt void OS_Timer_isr(void)
OS_Timer_isr:
	push	flag
	push	r0
	push	r1
	push	r2
	mov	r2,#OS_COMMON
;increment generic OS Timer
	ldm	r1,(r2,#os_time-OS_COMMON)
	add	r1,#1:8
	stm	(r2,#os_time-OS_COMMON),r1
;
;decrement sleep timer & search highest active task
	ldm	r2,(r2,#os_end_tcb-OS_COMMON)
osti1:
	sub	r2,#OS_TCB_SIZE:8
	ldm	r1,(r2,#OS_TCB_TMR)
	sub	r1,#1:8
	blo	OST_fond  ;found active task
	bmi	osti1
	stm	(r2,#OS_TCB_TMR),r1
	bra	osti1
;
OST_fond:
	mov	r0,r2 ;save highest active task
ostf1:
	sub	r2,#OS_TCB_SIZE:8
	cmp	r2,#os_tcb
	blo	context_swap
;	jlo	context_swap
;
	ldm	r1,(r2,#OS_TCB_TMR)
	sub	r1,#1:8
	bmi	ostf1
	stm	(r2,#OS_TCB_TMR),r1
	bra	ostf1
;
