;----------------------------------------------------------------------------
;  bios.s Z80 bios loader & debug monitor for NISE-X1
;
; version 050412 alpha
;
;  MONZ80.S - Z80 Debug monitor for use with NoICEZ80
;  This file may be assembled with the PROASM assembler
;
;  Based by MONZ80.S - Z80 Debug monitor for use with NoICEZ80
;
;  Copyright (c) 2004 by Tatsuyuki Satoh
;
;  included Z80 Debug monitor for use with NoICEZ80 are
;    Monz80.s V3.0
;    Copyright (c) 2001 by John Hartman
;
;  Modification History:
;       2008. 5. 2 suport SPI I/F , ori-ge ver.
;       2004. 4.12 bugfix FDC handling
;                  change to assemple on AASM 3.60(MultiPass)
;       2004. 1.14 IPL,clear text before exec
;       2004. 1.12 1st alpha release
;
;============================================================================
;
;  Hardware definitions
ROM_START       equ     0000H          ;START OF MONITOR CODE
RAM_START       equ     4000H          ;START OF MONITOR RAM
;
CFG_TOP			equ		020000H      ;XC2S200+XCF02F  ConfigROM TOP Address
;CFG_TOP			equ		02A000H      ;XC2S250E+XCF02F ConfigROM TOP Address
;
;
SERIAL_DATA	equ	08000h
SERIAL_STATUS	equ	0c000h
RXRDY		equ	0
DEBUG_ENABLE	equ	1              ; NoICE enable flag
TXRDY		equ	2
RESET_ENTRY	equ	7
;
PAGEIMAGE       equ     0c000h
;
;
CRTC_REG	equ	01800h
SUBC_REG	equ	01900h
PIA_MODE	equ	01a03h
;
IPL_BANK	equ	0eh
;
;===========================================================================
;  Reset, RST 0,  or trap vector
        ORG     0000H
;
;RESET START WHEN (SERIAL_STATUS),RESET_ENTRY == 1
;RST 00 TRAP WHEN (SERIAL_STATUS),RESET_ENTRY == 0
;
R0:     LD	(REG_A),A
        LD      A,1                     ;STATE = 1 (BREAKPOINT)
;	jp	RESET ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        JP      INT_ENTRY
;
	ORG			0008H
;
	JP	DISP_STRL
;
;===========================================================================
;  Check serial
;
;  Return CY=0 if data received
;         CY=1 if data not received
CHKCHAR:
	LD	A,(SERIAL_STATUS)
	BIT	RXRDY,A
	JR	Z,GC90
	XOR	A
	RET
;
;===========================================================================
;  Get a character to A
;
;  Return A=char, CY=0 if data received
;         CY=1 if timeout (0.5 seconds)
;
GETCHAR:
	EXX
        LD      DE,00000H               ;long timeout
GC10:   DEC     DE
        LD      A,D
        OR      E
        JR      Z,GC90                  ;exit if timeout
;
	BIT	RXRDY,(HL)
        JR      Z,GC10                  ;not ready yet.
;
;  Data received:  return CY=0. data in A
        XOR     A                       ;CY=0
        LD	A,(BC)                  ;read data
	EXX
RET_MON
RET_USR	EQU	$+3000H
        RET
;
;  Timeout:  return CY=1
GC90:   SCF                             ;cy=1
        EXX
        RET
;
;===========================================================================
;  Output character in A
;
PUTCHAR:
	EXX
PC10:
        BIT     TXRDY,(HL)              ;RX READY ?
        JR      Z,PC10
        LD	(BC),A
	EXX
        RET
;
;
;===========================================================================
;
;  Non-maskable interrupt:  bash button
;  PC is stacked, interrupts disabled, and IFF2 has pre-NMI interrupt state
;
;  At the user's option, this may vector thru user RAM at USER_CODE+66H,
;  or enter the monitor directly.  This will depend on whether or not
;  the user wishes to use NMI in the application, or to use it with
;  a push button to break into running code.
        ORG     R0+66H
NMI_ENTRY:
	LD	(REG_A),A
        LD      A,2
        JP      INT_ENTRY
;
;===========================================================================
;  Power on reset or trap
RESET:
;-------------------------------------------------------------------------
;  Initialize monitor
INIT:   LD      SP,MONSTACK
;
;INIT I/O
	LD	HL,CRTC_40
	CALL	CRTC_SET
	CALL	CLS
	LD	A,7
	LD	(COLOR),A
;	JP	BIOS ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;----- PRE-LOAD INTERNAL IPL IMAGE -----
	LD	A,IPL_BANK
	LD	(PAGEIMAGE),A
;BOOT PROGRAM
	LD	HL,IPL_TOP
	LD	DE,0000H
	LD	BC,IPL_LEN
	CALL	LDIR_DU
;DISK READ ROUTINE
	LD	HL,DRD_TOP
	LD	DE,021AH
	LD	BC,DRD_LEN
	CALL	LDIR_DU
;----- MODE SELECT -----
	LD	A,(SERIAL_STATUS)
	BIT	DEBUG_ENABLE,A
	JP	Z,BIOS
;----- NO-ICE MODE -----
	LD	HL,B1
	LD	BC,3000H
	CALL	DISP_STR
;
;	LD	HL,B1
;	CALL	SEND_STR
;
;===========================================================================
;
;  Initialize user registers
	LD      HL,TASK_REGS
	LD	DE,TASK_REGS+1
	LD	BC,TASK_REGS_SIZE-1
	LD	(HL),0
	LDIR
;
	XOR	A
        LD      (REG_STATE),A           ;set state as "RESET"
;
;  Initialize memory paging variables and hardware (if any)
        LD      (REG_PAGE),A            ;page 0
	 LD      (PAGEIMAGE),A
;;;     OUT     (PAGELATCH),A           ;set hardware page
;
;  Set function code for "GO".  Then if we reset after being told to
;  GO, we will come back with registers so user can see the crash
        LD      A,FN_RUN_TARGET
        LD      (COMBUF),A
        JP      RETURN_REGS             ;DUMP REGS, ENTER MONITOR
;
;===========================================================================
;LDIR DEBUG MEM TO USER MEM
LDIR_DU:
	LD	A,(HL)
	CALL	LD_DE_A
	INC	HL
	INC	DE
	DEC	BC
	LD	A,B
	OR	C
	JR	NZ,LDIR_DU
	RET
;
;===========================================================================
;  Response string for GET TARGET STATUS request
;  Reply describes target:
TSTG:   DB      0                       ;2: PROCESSOR TYPE = Z80
        DB      COMBUF_SIZE             ;3: SIZE OF COMMUNICATIONS BUFFER
        DB      0                       ;4: NO OPTIONS
        DW      0                       ;5,6: BOTTOM OF PAGED MEM (none)
        DW      0FFFFH                  ;7,8: TOP OF PAGED MEM (none)
        DB      B1-B0                   ;9 BREAKPOINT INSTRUCTION LENGTH
B0:     RST     00H                     ;10+ BREAKPOINT INSTRUCTION
B1:
        DB      'NoICE monitor V3.0 for NISE-X1',0              ;DESCRIPTION, ZERO

TSTG_SIZE       EQU     $-TSTG          ;SIZE OF STRING
;
;===========================================================================
;  HARDWARE PLATFORM INDEPENDENT EQUATES AND CODE
;
;  Communications function codes.
FN_GET_STATUS   EQU     0FFH    ;reply with device info
FN_READ_MEM     EQU     0FEH    ;reply with data
FN_WRITE_MEM    EQU     0FDH    ;reply with status (+/-)
FN_READ_REGS    EQU     0FCH    ;reply with registers
FN_WRITE_REGS   EQU     0FBH    ;reply with status
FN_RUN_TARGET   EQU     0FAH    ;reply (delayed) with registers
FN_SET_BYTES    EQU     0F9H    ;reply with data (truncate if error)
FN_IN           EQU     0F8H    ;input from port
FN_OUT          EQU     0F7H    ;output to port
;
FN_MIN          EQU     0F0H    ;MINIMUM RECOGNIZED FUNCTION CODE
FN_ERROR        EQU     0F0H    ;error reply to unknown op-code
;
;===========================================================================
;  Enter here via RST nn for breakpoint:  AF, PC are stacked.
;  Enter with A=interrupt code = processor state
;  Interrupt status is not changed from user program and IFF2==IFF1
INT_ENTRY:
;  INT,NMI are hardware masked, so DI,EI operate is ignore
;
        LD      (REG_STATE),A   ;save entry state
        LD      A,(REG_A)
	LD	(REG_SP),SP
	LD	SP,REG_AFX+2
;
	EX	AF,AF'
	EXX
	PUSH	AF
	PUSH	DE
	PUSH	BC
	PUSH	HL
;I,IFF
	LD	A,I
	LD	L,A
        LD      H,0
        JP      PO,BREAK10
        INC     H
BREAK10:
	PUSH	HL   ; REG_IFF,REG_I
	PUSH	HL   ; PC , DUMMY
	EXX
	EX	AF,AF'
	PUSH	AF
	PUSH	DE
	PUSH	BC
	PUSH	HL
	PUSH	IY
	PUSH	IX
;setup fixed registers
	LD	SP,MONSTACK
	LD	IY,RET_MON
	EXX
	LD	HL,SERIAL_STATUS
	LD	BC,SERIAL_DATA
	EXX
;BANK select
	XOR     A
        LD      (PAGEIMAGE),A
;
;POP PC FROM USER STACK
	LD	HL,(REG_SP)
	CALL	LD_A_HL
	INC	HL
	LD	E,A
	CALL	LD_A_HL
	INC	HL
	LD	D,A
	LD	(REG_SP),HL
;
        LD      A,(REG_STATE)
        CP      1
        JR      NZ,NOTBP        ;JIF NOT A BREAKPOINT
        DEC     DE              ;BACK UP PC TO POINT AT BREAKPOINT
;
;----------- reset entry check ---------
	LD	A,(SERIAL_STATUS)
	BIT	RESET_ENTRY,A
	JP	NZ,RESET
;----------- reset entry check ---------
;
NOTBP:	LD	(REG_PC),DE
        JP      RETURN_REGS
;
;===========================================================================
;  user memory access routine
;
; because opcode JP use normal memory access,
; Can't return to monitor with JP opcode.
;
LD_A_DE	equ	$+1000H
	LD	A,(DE)   ;user memory access
	JP 	(IY)     ;JP RET_MON
LD_DE_A	equ	$+1000H
	LD	(DE),A   ;user memory access
	JP 	(IY)     ;JP RET_MON
LD_A_HL	equ	$+1000H
	LD	A,(HL)   ;user memory access
	JP 	(IY)     ;JP RET_MON
PUSH_HL	equ	$+1000H
	PUSH	HL	;user memory access
	JP 	(IY)	;JP RET_MON
POP_HL	equ	$+1000H
	POP	HL	;user memory access
	JP 	(IY)	;JP RET_MON
;
;===========================================================================
;  Main loop:  wait for command frame from master
MAIN:   LD      SP,MONSTACK             ;CLEAN STACK IS HAPPY STACK
        LD      HL,COMBUF               ;BUILD MESSAGE HERE
;  First byte is a function code
        CALL    GETCHAR                 ;GET A FUNCTION (uses 6 bytes of stack)
        JR      C,MAIN                  ;JIF TIMEOUT: RESYNC
        CP      FN_MIN
        JR      C,MAIN                  ;JIF TIMEOUT: RESYNC
;
        LD      (HL),A                  ;SAVE FUNCTION CODE
        INC     HL
;
;  Second byte is data byte count (may be zero)
        CALL    GETCHAR                 ;GET A LENGTH BYTE
        JR      C,MAIN                  ;JIF TIMEOUT: RESYNC
        CP      COMBUF_SIZE+1
        JR      NC,MAIN                 ;JIF TOO LONG: ILLEGAL LENGTH
        LD      (HL),A                  ;SAVE LENGTH
        INC     HL
        OR      A
        JR      Z,MA80                  ;SKIP DATA LOOP IF LENGTH = 0
;
;  Loop for data
        LD      B,A                     ;SAVE LENGTH FOR LOOP
MA10:   CALL    GETCHAR                 ;GET A DATA BYTE
        JR      C,MAIN                  ;JIF TIMEOUT: RESYNC
        LD      (HL),A                  ;SAVE DATA BYTE
        INC     HL
        DJNZ    MA10
;
;  Get the checksum
MA80:   CALL    GETCHAR                 ;GET THE CHECKSUM
        JR      C,MAIN                  ;JIF TIMEOUT: RESYNC
        LD      C,A                     ;SAVE CHECKSUM
;
;  Compare received checksum to that calculated on received buffer
;  (Sum should be 0)
        CALL    CHECKSUM
        ADD     A,C
        JR      NZ,MAIN                 ;JIF BAD CHECKSUM
;
;  Process the message.
        LD      A,(COMBUF+0)            ;GET THE FUNCTION CODE
	CPL
	ADD	A,A
	ADD	A,CMD_TBL & 0FFH
	LD	L,A
	LD	H,CMD_TBL / 256
	LD	A,(HL)
	INC	HL
	LD	H,(HL)
	LD	L,A
	JP	(HL)
;
;  Error: unknown function.  Complain
ERR:
        LD      A,FN_ERROR
        LD      (COMBUF+0),A    ;SET FUNCTION AS "ERROR"
        LD      A,1
        JP      SEND_STATUS     ;VALUE IS "ERROR"
;
CMD_TBL:
	DW	TARGET_STATUS ;FN_GET_STATUS
	DW	READ_MEM      ;FN_READ_MEM
	DW	WRITE_MEM    ;FN_WRITE_MEM
        DW	READ_REGS    ;FN_READ_REGS
        DW	WRITE_REGS   ;FN_WRITE_REGS
        DW	RUN_TARGET   ;FN_RUN_TARGET
        DW	SET_BYTES    ;FN_SET_BYTES
        DW	IN_PORT      ;FN_IN
        DW	OUT_PORT     ;FN_OUT
	DW	ERR
	DW	ERR
	DW	ERR
	DW	ERR
	DW	ERR
	DW	ERR
	DW	ERR
;

;===========================================================================
;
;  Target Status:  FN, len
;
TARGET_STATUS:
;
        LD      HL,TSTG                 ;DATA FOR REPLY
        LD      DE,COMBUF+1             ;RETURN BUFFER
        LD      BC,TSTG_SIZE            ;LENGTH OF REPLY
        LD      A,C
        LD      (DE),A                  ;SET SIZE IN REPLY BUFFER
        INC     DE
        LDIR                            ;MOVE REPLY DATA TO BUFFER
;
;  Compute checksum on buffer, and send to master, then return
        JP      SEND

;===========================================================================
;
;  Read Memory:  FN, len, page, Alo, Ahi, Nbytes
;
READ_MEM:
;
;  Set page
      LD      A,(COMBUF+2)
      LD      (PAGEIMAGE),A
;;      LD      BC,PAGELATCH
;;      OUT     (BC),A
;
;  Get address
        LD      HL,(COMBUF+3)
        LD      A,(COMBUF+5)            ;NUMBER OF BYTES TO GET
;
;  Prepare return buffer: FN (unchanged), LEN, DATA
        LD      DE,COMBUF+1             ;POINTER TO LEN, DATA
        LD      (DE),A                  ;RETURN LENGTH = REQUESTED DATA
        INC     DE
        OR      A
        JR      Z,GLP90                 ;JIF NO BYTES TO GET
;
;  Read the requested bytes from local memory
        LD      B,A
GLP:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	CALL	LD_A_HL
;    LD      A,(HL)                  ;GET BYTE TO A
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	LD      (DE),A                  ;STORE TO RETURN BUFFER
        INC     HL
        INC     DE
        DJNZ    GLP
;
;  Compute checksum on buffer, and send to master, then return
GLP90:  JP      SEND

;===========================================================================
;
;  Write Memory:  FN, len, page, Alo, Ahi, (len-3 bytes of Data)
;
;  Uses 2 bytes of stack
;
WRITE_MEM:
;
;  Set page
      LD      A,(COMBUF+2)
      LD      (PAGEIMAGE),A
;;      LD      BC,PAGELATCH
;;      OUT     (BC),A
;
        LD      HL,COMBUF+5             ;POINTER TO SOURCE DATA IN MESSAGE
        LD      DE,(COMBUF+3)           ;POINTER TO DESTINATION
        LD      A,(COMBUF+1)            ;NUMBER OF BYTES IN MESSAGE
        SUB     3                       ;LESS PAGE, ADDRLO, ADDRHI
        JR      Z,WLP50                 ;EXIT IF NONE REQUESTED
;
;  Write the specified bytes to local memory
        LD      B,A
        PUSH    BC                      ;SAVE BYTE COUNTER
WLP10:  LD      A,(HL)                  ;BYTE FROM HOST
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	CALL	LD_DE_A
;        LD      (DE),A                  ;WRITE TO TARGET RAM
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        INC     HL
        INC     DE
        DJNZ    WLP10
;
;  Compare to see if the write worked
        LD      HL,COMBUF+5             ;POINTER TO SOURCE DATA IN MESSAGE
        LD      DE,(COMBUF+3)           ;POINTER TO DESTINATION
        POP     BC                      ;SIZE AGAIN
;
;  Compare the specified bytes to local memory
WLP20:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	CALL	LD_A_DE
	CP	(HL)
;	  LD      A,(DE)                  ;READ BACK WHAT WE WROTE
;        CP      (HL)                    ;COMPARE TO HOST DATA
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        JR      NZ,WLP80                ;JIF WRITE FAILED
        INC     HL
        INC     DE
        DJNZ    WLP20
;
;  Write succeeded:  return status = 0
WLP50:  XOR     A                       ;RETURN STATUS = 0
        JR      WLP90
;
;  Write failed:  return status = 1
WLP80:  LD      A,1
;
;  Return OK status
WLP90:  JP      SEND_STATUS

;===========================================================================
;
;  Read registers:  FN, len=0
;
READ_REGS:
;
;  Enter here from int after "RUN" and "STEP" to return task registers
RETURN_REGS:
        LD      HL,TASK_REGS            ;REGISTER LIVE HERE
        LD      A,TASK_REGS_SIZE        ;NUMBER OF BYTES
;
;  Prepare return buffer: FN (unchanged), LEN, DATA
        LD      DE,COMBUF+1             ;POINTER TO LEN, DATA
        LD      (DE),A                  ;SAVE DATA LENGTH
        INC     DE
;
;  Copy the registers
        LD      B,A
GRLP:   LD      A,(HL)                  ;GET BYTE TO A
        LD      (DE),A                  ;STORE TO RETURN BUFFER
        INC     HL
        INC     DE
        DJNZ    GRLP
;
;  Compute checksum on buffer, and send to master, then return
        JP      SEND

;===========================================================================
;
;  Write registers:  FN, len, (register image)
;
WRITE_REGS:
;
        LD      HL,COMBUF+2             ;POINTER TO DATA
        LD      A,(COMBUF+1)            ;NUMBER OF BYTES
        OR      A
        JR      Z,WRR80                 ;JIF NO REGISTERS
;
;  Copy the registers
        LD      DE,TASK_REGS            ;OUR REGISTERS LIVE HERE
        LD      B,A
WRRLP:  LD      A,(HL)                  ;GET BYTE TO A
        LD      (DE),A                  ;STORE TO REGISTER RAM
        INC     HL
        INC     DE
        DJNZ    WRRLP
;
;  Return OK status
WRR80:  XOR     A
        JP      SEND_STATUS

;===========================================================================
;
;  Run Target:  FN, len
;
;  Uses 4 bytes of stack
;
RUN_TARGET:
;
;reset bank page
	XOR     A
        LD      (PAGEIMAGE),A
;PUSH PC TO USER STACK
        LD      DE,(REG_SP)
	DEC	DE
        LD      A,(REG_PC+1)
	CALL	LD_DE_A
	DEC	DE
        LD      A,(REG_PC)
	CALL	LD_DE_A
	LD	(REG_SP),DE
;
;  Restore alternate registers
        LD      SP,REG_IX
	POP	IX
	POP	IY
	POP	HL
	POP	BC
	POP	DE
	POP	AF
	EXX
	EX	AF,AF'
	POP	AF   ; PC DUMMY
	POP	HL   ; I,IFF
	LD	A,L
	LD	I,A
	LD	A,H
        OR      A
        JR      Z,RUTT10                ;JIF INTS OFF: LEAVE OFF
	EI
RUTT10:
	POP	HL
	POP	BC
	POP	DE
	POP	AF
	EXX
	EX	AF,AF'
;
	LD	SP,(REG_SP)
;GOTO TARGET
	JP	RET_USR
;
;===========================================================================
;
;  Set target byte(s):  FN, len { (page, alow, ahigh, data), (...)... }
;
;  Return has FN, len, (data from memory locations)
;
;  If error in insert (memory not writable), abort to return short data
;
;  This function is used primarily to set and clear breakpoints
;
;  Uses 2 bytes of stack
;
SET_BYTES:
;
        LD      HL,COMBUF+1
        LD      B,(HL)                  ;LENGTH = 4*NBYTES
        INC     HL
        INC     B
        DEC     B
        LD      C,0                     ;C GETS COUNT OF INSERTED BYTES
        JR      Z,SB90                  ;JIF NO BYTES (C=0)
        PUSH    HL
        POP     IX                      ;IX POINTS TO RETURN BUFFER
;
;  Loop on inserting bytes
SB10:   LD      A,(HL)                  ;MEMORY PAGE
        INC     HL
        LD      (PAGEIMAGE),A
;;      PUSH    BC
;;      LD      BC,PAGELATCH
;;      OUT     (BC),A                  ;SET PAGE
;;      POP     BC
        LD      E,(HL)                  ;ADDRESS TO DE
        INC     HL
        LD      D,(HL)
        INC     HL
;
;  Read current data at byte location
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	CALL	LD_A_DE
;        LD      A,(DE)                  ;READ CURRENT DATA
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        LD      (IX),A                  ;SAVE IN RETURN BUFFER
        INC     IX
;
;  Insert new data at byte location
        LD      A,(HL)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	CALL	LD_DE_A
	CALL	LD_A_DE
;        LD      (DE),A                  ;SET BYTE
;        LD      A,(DE)                  ;READ CURRENT DATA
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        CP      (HL)                    ;COMPARE TO DESIRED VALUE
        JR      NZ,SB90                 ;BR IF INSERT FAILED: ABORT
        INC     HL
        INC     C                       ;ELSE COUNT ONE BYTE TO RETURN
;
        DEC     B
        DEC     B
        DEC     B
        DJNZ    SB10                    ;LOOP FOR ALL BYTES
;
;  Return buffer with data from byte locations
SB90:   LD      A,C
        LD      (COMBUF+1),A            ;SET COUNT OF RETURN BYTES
;
;  Compute checksum on buffer, and send to master, then return
        JP      SEND

;===========================================================================
;
;  Input from port:  FN, len, PortAddressLo, PAhi (=0)
;
IN_PORT:
;
;  Get port address
        LD      BC,(COMBUF+2)
;
;  Read port value
        IN      A,(C)           ;IN WITH A15-A8 = B; A7-A0 = C
;
;  Return byte read as "status"
        JP      SEND_STATUS

;===========================================================================
;
;  Output to port:  FN, len, PortAddressLo, PAhi (=0), data
;
OUT_PORT:
;
;  Get port address
        LD      BC,(COMBUF+2)
;
;  Get data
        LD      A,(COMBUF+4)
;
;  Write value to port
        OUT     (C),A           ;OUT WITH A15-A8 = B; A7-A0 = C
;
;  Return status of OK
        XOR     A
        JP      SEND_STATUS
;
;===========================================================================
;  Build status return with value from "A"
;
SEND_STATUS:
        LD      (COMBUF+2),A            ;SET STATUS
        LD      A,1
        LD      (COMBUF+1),A            ;SET LENGTH
        JR      SEND

;===========================================================================
;  Append checksum to COMBUF and send to master
;
;  Uses 6 bytes of stack (not including return address: jumped, not called)
;
SEND:   CALL    CHECKSUM                ;GET A=CHECKSUM, HL->checksum location
        NEG
        LD      (HL),A                  ;STORE NEGATIVE OF CHECKSUM
;
;  Send buffer to master
        LD      HL,COMBUF               ;POINTER TO DATA
        LD      A,(COMBUF+1)            ;LENGTH OF DATA
        ADD     A,3                       ;PLUS FUNCTION, LENGTH, CHECKSUM
        LD      B,A                     ;save count for loop
SND10:  LD      A,(HL)
        CALL    PUTCHAR                 ;SEND A BYTE (uses 6 bytes of stack)
        INC     HL
        DJNZ    SND10
        JP      MAIN                    ;BACK TO MAIN LOOP

;===========================================================================
;  Compute checksum on COMBUF.  COMBUF+1 has length of data,
;  Also include function byte and length byte
;
;  Returns:
;       A = checksum
;       HL = pointer to next byte in buffer (checksum location)
;       B is scratched
;
;  Uses 2 bytes of stack including return address
;
CHECKSUM:
        LD      HL,COMBUF               ;pointer to buffer
        LD      A,(COMBUF+1)            ;length of message
        ADD     A,2                       ;plus function, length
        LD      B,A                     ;save count for loop
        XOR     A                       ;init checksum to 0
CHK10:  ADD     A,(HL)
        INC     HL
        DJNZ    CHK10                   ;loop for all
        RET                             ;return with checksum in A
;


;----------------------------------------------------------------------------
; X1 BIOS MENU PROGRAM
;----------------------------------------------------------------------------
;
;----------------------------------------------------------------------------
;5x address input
ADR_INP:
	LD	HL,MSG_IA
;	CALL	DISP_STRL
	RST 08H
	LD	HL,0
	LD	DE,0500H
	PUSH	BC
	XOR	A
	CALL	OUT_HEX5
	POP	BC
AI1:
	PUSH	DE
	PUSH	HL
	LD	D,0 ;EDIT VALUE
AI2:
	LD	A,0FH
	LD	(COLOR),A
	LD	A,D
	CALL	OUT_HEX1
	DEC	BC
	CALL	GET_SWW
	BIT	0,A
	JR	Z,AI_DEC
	BIT	1,A
	JR	Z,AI_INC
	BIT	5,A
	JR	Z,AI_SET
	JR	AI2
;
AI_INC:
	INC	D
	RES	4,D
	JR	AI2
;
AI_DEC:
	DEC	D
	LD	A,D
	AND	0FH
	LD	D,A
	JR	AI2
;
AI_SET:
	LD	A,07H
	LD	(COLOR),A
	LD	A,D
	CALL	OUT_HEX1
;DHL = DHL * 16 | A
	LD	A,D
	POP	HL
	POP	DE
	ADD	HL,HL
	RL	E
	ADD	HL,HL
	RL	E
	ADD	HL,HL
	RL	E
	ADD	HL,HL
	RL	E
	OR	L
	LD	L,A
;
	DEC	D
	JR	NZ,AI1
	LD	A,E
	RET
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
WAIT_SW:
	CALL	GET_SW
	INC	A
	JR	NZ,WAIT_SW
	RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
GET_SWW:
	CALL	WAIT_SW
GET_SWW2:
	CALL	GET_SW
	INC	A
	JR	Z,GET_SWW2
	DEC	A
	RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
GET_SW:
	PUSH	BC
	LD	A,0EH
	LD	B,1CH
	OUT	(C),A
	DEC	B
	IN	A,(C)
	POP	BC
	RET
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
DISP_CHR:
	OUT	(C),A
	RES	4,B
	LD	A,(COLOR)
	OUT	(C),A
	SET	4,B
	INC	BC
	RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
DISP_STRL:
	LD	C,(HL)
	INC	HL
	LD	B,(HL)
	INC	HL
DISP_STR:
	LD	A,(HL)
	INC	HL
	OR	A
	RET	Z
	CALL	DISP_CHR
	JR	DISP_STR
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; SHOW BIOS MENU
; C = MENU NUMBER
DISP_MENU:
;7segment
	LD	B,19H
	LD	A,0F0H  ;COMMAND
	OUT	(C),A
	OUT	(C),C
	XOR	A
	OUT	(C),A
;
	LD	HL,MSG_CMD
	LD	B,0
DM1:
	PUSH	BC
	LD	A,B
	CP	C
	LD	A,07H
	JR	NZ,DM2
	LD	A,0FH
DM2:
	LD	(COLOR),A
;
;	CALL	DISP_STRL
	RST 08H
	POP	BC
	INC	B
	LD	A,B
	CP	MAX_MENU
	JR	C,DM1
	LD	A,7
	LD	(COLOR),A
	RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; MEMU SUB
;
MENU_PREV:
	DEC	C
	LD	A,C
	AND	80H
	JR	Z,MENU_MAIN
	LD	C,MAX_MENU-1
	JR	MENU_MAIN
MENU_NEXT
	INC	C
	LD	A,C
	CP	MAX_MENU
	JR	C,MENU_MAIN
	LD	C,0
	JR	MENU_MAIN
MENU_GO:
	LD	HL,MENU_RET
	PUSH	HL
;7segment
	LD	B,19H
	LD	A,0F0H  ;COMMAND
	OUT	(C),A
	OUT	(C),C
	LD	A,1
	OUT	(C),A
;JUMP TABLE
	LD	A,C
	ADD	A,A
	ADD	A,MENU_TBL
	LD	L,A
	LD	H,MENU_TBL/256
	LD	A,(HL)
	INC	HL
	LD	H,(HL)
	LD	L,A
	JP	(HL)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; X1 BIOS MENU
BIOS:
	CALL	CFG_LOAD
	JR	NC,CMD_GIPL
;
MENU_ENTER:
	LD	A,07H
	LD	(COLOR),A
	CALL	CLS
;show display
	LD	HL,MSG_MENU
;	CALL	DISP_STRL
	RST 08H
	LD	C,0
;---------------------------------------
MENU_MAIN:
	CALL	WAIT_SW
	CALL	DISP_MENU
MENU_SEL:
;JOY CHECK
	CALL	GET_SW
	BIT	0,A
	JR	Z,MENU_PREV
	BIT	1,A
	JR	Z,MENU_NEXT
	BIT	5,A
	JR	Z,MENU_GO
;SERIAL COMMAND
	LD	A,(SERIAL_STATUS)
	BIT	RXRDY,A
        JR      Z,MENU_SEL
;SERIAL CMD
	CALL	GETCHAR
       	SUB	'0'
	JR	C,MENU_SEL
	CP	MAX_MENU
	JR	NC,MENU_SEL
;GO SERIAL CMD
	LD	C,A
	CALL	DISP_MENU
	JR	MENU_GO
;
MENU_RET:
	LD	HL,MSG_DONE
;	CALL	DISP_STRL
	RST 08H
	CALL	GET_SWW
	JR	MENU_ENTER
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;COMMAND HANDLING
;
CMD_L2D0:
	LD	A,01H
	JR	DLD_HL0
;
CMD_L2D1:
	LD	A,07H
	LD	HL,8000H
	JR	DLD
;
CMD_LIPL:
	LD	A,0EH
DLD_HL0:
	LD	HL,0000H
	JR	DLD
;
CMD_LADR:
	CALL	ADR_INP
DLD:
	JP	DOWNLOAD
;
CMD_GIPL:
	LD	A,0EH
	LD	HL,0000H
	JR	EXEC_GO
;
CMD_GADR:
	CALL	ADR_INP
EXEC_GO:
	OR	A
	LD	A,1DH ;IPL SEL
	JR	NZ,EXEC1
	INC	A     ;MEM SEL
EXEC1:
	OUT	(00H),A
	LD	(REG_PC),HL ;EXEC ADDR
	LD	(REG_SP),HL
	JP	RUN_TARGET
;
;----------------------------------------------------------------------------
;LOAD DATA START
DOWNLOAD:
	PUSH	AF
	PUSH	HL
	LD	HL,MSG_SA
;	CALL	DISP_STRL
	RST 08H
	POP	HL
	POP	AF
	PUSH	AF
	PUSH	HL
	CALL	OUT_HEX5
	POP	HL
	POP	AF
	LD	C,A
	LD	(PAGEIMAGE),A
;WAIT FOR RX 1ST BYTE
BIN_L2:
	CALL	GETCHAR
	JR	C,BIN_L2
BIN_L3:
	EX	DE,HL
	CALL	LD_DE_A
	EX	DE,HL
;
	PUSH	BC
	LD	BC,3000H + 12*40
	OUT	(C),A
	POP	BC
;
	INC	L
	JR	NZ,BIN_L4
;
	INC	H
	JR	NZ,BIN_L4
	INC	C
	LD	A,C
	LD	(PAGEIMAGE),A
BIN_L4:
	CALL	GETCHAR
	JR	NC,BIN_L3
;END MESSAGE
	LD	A,C
	PUSH	AF
	PUSH	HL
	LD	HL,MSG_EA
;	CALL	DISP_STRL
	RST 08H
	POP	HL
	POP	AF
	CALL	OUT_HEX5
	RET
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; CFG_LOAD
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
CFG_LOAD:
	LD	BC,0E40H ; NOLOAD,CS=00,CNT=0
	OUT	(C),A
;DUMMY 16BIT
	CALL	CFG_BYPASS16
;SEARCH 1ST 55H
	LD	E,48+1
CFG_L1:
	DEC	E
	JR	Z,CFG_LERR
;
	LD	BC,0E51H ; NO LOAD,CS=01,CNT=1
	OUT     (C),A
	IN      A,(C)
;
	CP	055H
	JR	NZ,CFG_L1
;
	CALL	CFG_GBYTE
	CP	099H
	JR	NZ,CFG_LERR
	CALL	CFG_GBYTE
	CP	0AAH
	JR	NZ,CFG_LERR
	CALL	CFG_GBYTE
	CP	066H
	JR	NZ,CFG_LERR
;
;BYPASS CFG DATA
	LD	HL,MSG_MENU
;	CALL	DISP_STRL
	RST 08H
	LD	HL,MSG_CBP
;	CALL	DISP_STRL
	RST 08H
;readed SYNC data == 8bytes
;
BYPASS_CNT	EQU	 ((CFG_TOP-8)/2)
;
	LD	E,0FFH - (BYPASS_CNT/10000H)
	LD	HL,0   - (BYPASS_CNT&000FFFFH)
CFG_L3:
	CALL CFG_BYPASS16
	INC	L
	JR	NZ,CFG_L3
;
;CHECK JOY-IN to BREAK
	CALL	GET_SW
	INC	A
	SCF
	RET	NZ
;
	INC	H
	JR	NZ,CFG_L3
	INC	E
	JR	NZ,CFG_L3
;
;LOAD DATA TO FD0 AREA
	LD	HL,MSG_CLD
;	CALL	DISP_STRL
	RST 08H
;
	LD	L,01H   ;  ADDR   = FD0 DATA
	LD	DE,0000H
	LD	H,02H
	LD	BC,0078H ; LENGTH = 20800H
;
	LD	A,L
	LD	(PAGEIMAGE),A
CFG_L4:
CFG_L5:
	CALL	CFG_GBYTE
	CALL	LD_DE_A
	INC	E
	JR	NZ,CFG_L6
	INC	D
	JR	NZ,CFG_L6
	INC	L
	LD	A,L
	LD	(PAGEIMAGE),A
CFG_L6:
	LD	A,B
	OR	C
	JR	NZ,CFG_L7
	OR	H
	JR	Z,CFG_OK
	DEC	H
CFG_L7:
	DEC	BC
	JR	CFG_L4
CFG_OK:
	XOR	A
	RET
CFG_LERR:
	SCF
	RET
;
CFG_GBYTE:
	LD	A,0EH
	OUT	(058H),A ; NO LOAD,CS=01,CNT=8
	LD	A,0EH
	IN	A,(000H)
	RET
;
CFG_BYPASS16:
	LD	A,0EH
	OUT	(058H),A ; NO LOAD,CS=01,CNT=8
	NOP
	OUT	(058H),A ; NO LOAD,CS=01,CNT=8
	RET
;
;---------------------------------------------------------------------------
OUT_HEX5:
	CALL	OUT_HEX1
	LD	A,H
	CALL	OUT_HEX2
	LD	A,L
OUT_HEX2:
	PUSH	AF
	RRCA
	RRCA
	RRCA
	RRCA
	CALL	OUT_HEX1
	POP	AF
OUT_HEX1:
	AND	0FH
	ADD	A,'0'
	CP	'9'+1
	JP	C,OH11
	ADD	A,'A'-'0'-10
OH11:
	JP	DISP_CHR
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
MENU_TBL:
	DW	CMD_L2D0
	DW	CMD_L2D1
	DW	CMD_LIPL
	DW	CMD_LADR
	DW	CMD_GIPL
	DW	CMD_gADR
;
MAX_MENU	EQU	($-MENU_TBL)/2
;
;FIXED MENU MESSAGE
MSG_MENU:
	DW	3000H+0*40+4
	DB	'NISE-X1 SnapShot.2009.3.16',0
MSG_DONE:
	DW	3000H+20*40+0
	DB	'PUSH TRIGGER',0
;
MSG_CMD:
	DW	3000H+2*40+8
	DB	'LOAD FD-0 IMG(.D88/.2D)',0
	DW	3000H+3*40+8
	DB	'LOAD FD-1 IMG(.D88/.2D)',0
	DW	3000H+4*40+8
	DB	'LOAD IPL-ROM',0
	DW	3000H+5*40+8
	DB	'LOAD Address',0
	DW	3000H+6*40+8
	DB	'IPL-BOOT',0
	DW	3000H+8*40+8
	DB	'GOTO',0
;
;ADDRESS EDIT
MSG_IA:
	DW 3000H +  9*40
	DB 'ADDR  ',0
MSG_SA:
	DW 3000H + 10*40
	DB 'START ',0
MSG_EA:
	DW 3000H + 11*40
	DB 'END   ',0
;
MSG_CBP:
	DW 3000H + 2*40
	DB 'Bypass Config Data',0
MSG_CLD:
	DW 3000H + 3*40
	DB 'Loading FD Image',0
;
;----------------------------------------------------------------------------
; X1 internal IPL
;----------------------------------------------------------------------------

;----------------------------------------------------------------------------
;IPL:0000 : BOOT
;IPL:0003 : TIMER SET
;----------------------------------------------------------------------------
;
DISK_RD EQU	021AH
FCB	EQU	0FE00H
;
;SUBROUTINE OFFSET
IPL_OFFS EQU	0000H-$
;
IPL_TOP:
	JP	IPL_ENT+IPL_OFFS
	JP	TMR_ENT+IPL_OFFS
;----------------------------------------------------------------------------
TMR_ENT:
	RET
;----------------------------------------------------------------------------
IPL_ENT:
	DI
	LD	SP,0000H
;INIT CRTC
	LD	HL,CRTC_40+IPL_OFFS
	CALL	CRTC_SET+IPL_OFFS
;INIT BOOT DRIVE
	XOR  A
	LD  (0FF87H),A
;LOADING MSG
	CALL	CLS+IPL_OFFS
	LD	HL,IPL_MSG1
	LD	BC,3000H
	CALL	PRINT
;IPL BOOT SECTOR LOAD
	LD	A,1
	LD	HL,FCB
	LD	DE,0000H
	CALL	DISK_RD
	JR	C,IPL_ERR
;file mode == BIN check
	LD	HL,FCB
	LD	A,(HL)
	AND	07H
	DEC	A
	JR	NZ,IPL_ERR
;file type == "Sys" check

;show file name
	INC	HL
	XOR	A
	LD	(FCB+0EH),A ;ASCII-EOF
	LD	BC,300AH
	CALL	PRINT
;show loading msg
	LD	HL,IPL_MSG2
	LD	BC,3028H
	CALL	PRINT
;GET FILE INFO
	LD	HL,(FCB+16H)
	PUSH HL              ;EXEC ADDRESS
	LD	BC,(FCB+12H)
	LD	HL,(FCB+14H)
	LD	DE,(FCB+01EH)
	LD	A,C
	AND	C
	LD	A,B
	JR	Z,IPL_2
	INC	A
IPL_2:
;LOAD BODY
	CALL	DISK_RD
	JR	C,IPL_ERR
;execute BODY
	CALL	CLS+IPL_OFFS
;
	LD	A,0C9H   ; RET
	LD	(0FFF2H),A
	LD	HL,00D3H ; OUT (0),A
	LD	(0FFF0H),HL
;
	LD	HL,(FCB+16H)
	LD	A,1EH
	JP	0FFF0H ; OUT (0),A , JP (HL)
;-----
IPL_ERR:
	LD	HL,IPL_MSGE
	LD	BC,3028H
	CALL	PRINT
IPL_LOCK:
	JR	IPL_LOCK
;
;----------------------------------------------------------------------------
;----- initialize CRTC -----------
;HL = CRTC_DATA
CRTC_SET:
	LD	BC,PIA_MODE
	LD	A,082H
	OUT	(C),A
	DEC	C
	LD	A,(HL)
	INC	HL
	OUT	(C),A   ; WIDTH VALUE
;
	LD	BC,CRTC_REG
	XOR	A
CRTC_L1:
	OUT	(C),A
	INC	C
	LD	E,(HL)
	OUT	(C),E
	INC	HL
	DEC	C
	INC	A
	CP	14
	JR	C,CRTC_L1
	RET
;----- DISPLAY MESSAGE -----
CRTC_40:
	DB	70H ;8255 port data
	DB	55  ;0
	DB	40  ;1
	DB	45  ;2
	DB	52  ;3
	DB	31  ;4
	DB	2   ;5
	DB	25  ;6
	DB	28  ;7
	DB	0   ;8
	DB	7   ;9
	DB	0   ;10
	DB	0   ;11
	DB	0   ;12
	DB	0   ;13
;CRTC_80:
;	DB	30H ;8255 port data
;	DB	111 ;0
;	DB	80  ;1
;	DB	89  ;2
;	DB	56  ;3
;	DB	31  ;4
;	DB	2   ;5
;	DB	25  ;6
;	DB	28  ;7
;	DB	0   ;8
;	DB	7   ;9
;	DB	0   ;10
;	DB	0   ;11
;	DB	0   ;12
;	DB	0   ;13
;
;----- CLEAR DISPLAY -----
CLS:
	PUSH	BC
	PUSH	DE
	LD	BC,3000H
	LD	DE,2007H
C1:
	OUT	(C),D
	RES	4,B
	OUT	(C),E
	SET	4,B
	INC	BC
	BIT	3,B
	JR	Z,C1
	POP	DE
	POP	BC
	RET
;----------------------------------------------------------------------------
PRINT	EQU	$+IPL_OFFS
PR1:
	LD	A,(HL)
	INC	HL
	OR	A
	RET	Z
	OUT	(C),A
	INC	BC
	JR	PR1
;----------------------------------------------------------------------------
IPL_MSG1 EQU	$+IPL_OFFS
	DB	'NISE-IPL ',0
IPL_MSG2 EQU	$+IPL_OFFS
	DB	'LOADING  ',0
IPL_MSGE EQU	$+IPL_OFFS
	DB	'ERROR',0
;
IPL_LEN EQU $-IPL_TOP

;----------------------------------------------------------------------------
;IPL:021A : DISK READ
;IN:
;   A      = recoard size
;   DE     = start sector
;   HL     = start address
;   (FF87) = drive no.
;OUT:
;   CF     = error flag
;   (HL-)  = read data
;break
;(FF88) = STACK SAVE (original only)
;(FF8A) = ERROR RETURN ADDESS  (original only)
;----------------------------------------------------------------------------
;	ORG	021AH
;
;SUBROUTINE OFFSET
DR_OFFS	EQU	021AH-$
;
DRD_TOP:
	PUSH	AF
	PUSH	DE
;MOTOR ON
	CALL	MOTOR_ON
	JR	C,DR_E2
;RESTORE
	LD	A,02H
	CALL	TYPE1
	POP	DE
	POP	AF
;
DR1:
	PUSH	AF
	PUSH	DE
;-- D=TRACK
	LD	A,E
	RLCA
	RL  D
	RLCA
	RL  D
	RLCA
	RL  D
;-- SIDE SET
	RLCA
	LD	A,(0FF87H)
	RES	4,A
	JR	NC,DR2
	OR	10H
DR2:
	LD	(0FF87H),A
;-- E=SECTOR
	LD	A,E
	AND	0FH
  INC A
	LD	E,A
;SEEK
	CALL	SEEK
;SIDE SEL
	CALL	MOTOR_ON
	JR	C,DR_E2
;READ
	LD	A,80H
	CALL	FDC_CMD
	LD	BC,0FFBH
DR3:
	LD	A,B
	IN	A,(0F8H)
	RRCA
	JR	NC,DR4
	RRCA
	JR	NC,DR3
	IN	A,(C)
	LD	(HL),A
	INC	HL
	JR	DR3
DR4:
	RLCA
	AND	1EH
	JR	NZ,DR_E2
;
	POP	DE
	POP	AF
	INC	DE
	DEC	A
	JR	NZ,DR1
;ok return
	CALL	MOTOR_OFF
	XOR	A
	RET
;error return
DR_E2:
	POP	DE
	POP	AF
	CALL	MOTOR_OFF
	SCF
	RET
;----------------------------------------
SEEK EQU $+DR_OFFS
	LD	BC,0FFAH
	OUT	(C),E
	INC	C
	OUT	(C),D
	LD	A,01EH
TYPE1 EQU $+DR_OFFS
	CALL	FDC_CMD
SEEK_1:
	IN	A,(C)
	RRCA
	JR	C,SEEK_1
	RET
;----------------------------------------
FDC_CMD EQU $+DR_OFFS
	LD	BC,0FF8H
	OUT	(C),A
	LD	A,10H
FC1:
	DEC	A
	JR	NZ,FC1
	RET
;----------------------------------------
MOTOR_ON EQU $+DR_OFFS
	LD	E,80H
	CALL	MOTOR
;READY CHECK
	LD	B,3
	LD	DE,0
MON1:
	LD	A,0FH
	IN	A,(0F8H)
	RLCA
	RET	NC
	DEC	DE
	LD	A,D
	OR	E
	JR	NZ,MON1
	DJNZ	MON1
	SCF
	RET
;----------------------------------------
MOTOR_OFF EQU $+DR_OFFS
	LD	E,00H
MOTOR EQU $+DR_OFFS
	LD	A,(0FF87H)
	AND	1FH
	OR	E
	LD	BC,0FFCH
	OUT	(C),A
	RET
;----------------------------------------
;SUBROUTINE SIZE
DRD_LEN	EQU	$-DRD_TOP
;











;============================================================================
;  RAM definitions:  top 1K
;        ABS
        ORG     RAM_START               ; Monitor RAM
;
;  Initial user stack
;  (Size and location is user option)
        DS      64
INITSTACK:
;
;  Monitor stack
;  (Calculated use is at most 6 bytes.  Leave plenty of spare)
        DS      16
MONSTACK:
;
;  Target registers:  order must match that in TRGZ80.C
TASK_REGS:
REG_STATE:     DS      1
REG_PAGE:      DS      1
REG_SP:        DS      2
REG_IX:        DS      2
REG_IY:        DS      2
REG_HL:        DS      2
REG_BC:        DS      2
REG_DE:        DS      2
REG_AF:                        ;LABEL ON FLAGS, A AS A WORD
REG_FLAGS:     DS      1
REG_A:         DS      1
REG_PC:        DS      2
REG_I:         DS      1
REG_IFF:       DS      1
 ;
REG_HLX:       DS      2       ;ALTERNATE REGISTER SET
REG_BCX:       DS      2
REG_DEX:       DS      2
REG_AFX:                       ;LABEL ON FLAGS, A AS A WORD
REG_FLAGSX:    DS      1
REG_AX:        DS      1
TASK_REGS_SIZE  EQU     $-TASK_REGS
;
; !!! Caution:  don't put parenthesis around the above in ASM180:
; !!! The parenthesis in ($-TASK_REGS) are "remembered", such that
; !!! LD BC,TASK_REGS_SIZE is the same as LD BC,(TASK_REGS_SIZE)
; !!! It is OK to use parenthesis around the difference if the difference
; !!! is to be divided - just not around the entire expression!!!!!
;
;  Communications buffer
;  (Must be at least as long as TASK_REG_SIZE.  Larger values may improve
;  speed of NoICE memory load and dump commands)
COMBUF_SIZE     EQU     144              ;DATA SIZE FOR COMM BUFFER
COMBUF:         DS      2+COMBUF_SIZE+1 ;BUFFER ALSO HAS FN, LEN, AND CHECK
;
;
;-------------------------------------------------------------------
COLOR	DB	1
;
RAM_END         EQU     $               ;ADDRESS OF TOP+1 OF RAM
;
