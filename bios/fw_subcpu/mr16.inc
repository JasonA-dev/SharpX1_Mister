;MR16 for X1 HW assign
;
;-------------------------------
GPIO	equ	2000h
;-------------------------------
PORT0	equ	GPIO+0
PORT1	equ	GPIO+2
PORT2	equ	GPIO+4
PORT3	equ	GPIO+6
PORT4	equ	GPIO+8
PORT5	equ	GPIO+10
PORT6	equ	GPIO+12
PORT7	equ	GPIO+14
PORT8	equ	GPIO+16
PORT9	equ	GPIO+18
PORTA	equ	GPIO+20
PORTB	equ	GPIO+22
;
;-------------------------------
TIMER	equ	2018h
;-------------------------------
TMR_CNT	equ	TIMER+0
TMR_INT	equ	TIMER+0
TMR_CTR	equ	TIMER+2
;
TC_IRQ	equ	 0001h
TC_RUN	equ	 0002h
TC_IEN	equ	 0004h
TC_RST	equ	 0008h
;
