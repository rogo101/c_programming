; During this coding assignment, we were able to use the GETC function to
; evaluate post fix expressions. If it was an operand, we would Push it, and if
; it was not, we would pop it and evaluate the expression. The final value is
; printed in hexadecimal.
; raghavv2, ishanj2

; mp2.asm
; Implement a stack calculator that can do the following operations:
; ADD, SUBTRACT, MULTIPLY, DIVIDE

; Inputs:
;   Console - postfix expression

; Outputs:
;   Console - [0 - F]{4}, evaluation of postfix expression
;   Register R5 - [0 - F]{4}, evaluation of postfix expression

.ORIG x3000

MAIN

; INSERT CODE HERE!

NEW_CHARACTER

	GETC ;
	OUT ; Echoes input
	LD R1, EQUAL		; Loading Negative ASCII Value into R1
	ADD R1, R1, R0		;
	BRz ONE_VALUE_CHECKER	; Checking to see if only one value is left on stack
	LD R1, SPACE		;
	ADD R1, R1, R0		;
	BRnp VALIDITY_CHECKER	; Checking to see if inputs are valid
	BRz NEW_CHARACTER ;

ONE_VALUE_CHECKER

	JSR POP ;
	ST R3, SAVE_VALUE ;
	JSR POP ;
	ADD R5, R5, #0 ;
	BRp PRINT_INVALID ;
	LDI R3, SAVE_VALUE ;
	JSR PRINT_HEX		; If only one value left, print hex answer to console
	BRnzp DONE ; Halts program

VALIDITY_CHECKER

	LD R1, ZERO		;
	ADD R1, R1, R0		;
	BRz OPERAND_CHECKER	;
	LD R1, ONE		;
	ADD R1, R1, R0		;
	BRz OPERAND_CHECKER	;
	LD R1, TWO		;
	ADD R1, R1, R0		;
	BRz OPERAND_CHECKER	;
	LD R1, THREE		;
	ADD R1, R1, R0		;
	BRz OPERAND_CHECKER	;
	LD R1, FOUR		;
	ADD R1, R1, R0		;
	BRz OPERAND_CHECKER	;
	LD R1, FIVE		;
	ADD R1, R1, R0		;
	BRz OPERAND_CHECKER	;
	LD R1, SIX		;
	ADD R1, R1, R0		;
	BRz OPERAND_CHECKER	;
	LD R1, SEVEN		;
	ADD R1, R1, R0		;
	BRz OPERAND_CHECKER	;
	LD R1, EIGHT		;
	ADD R1, R1, R0		;
	BRz OPERAND_CHECKER	;
	LD R1, NINE		;
	ADD R1, R1, R0		;
	BRz OPERAND_CHECKER	;
	LD R1, ADD1		;
	ADD R1, R1, R0		;
	BRz OPERAND_CHECKER	;
	LD R1, MIN1		;
	ADD R1, R1, R0		;
	BRz OPERAND_CHECKER	;
	LD R1, MULT1		;
	ADD R1, R1, R0		;
	BRz OPERAND_CHECKER	;
	LD R1, DIV1		;
	ADD R1, R1, R0		;
	BRz OPERAND_CHECKER	;If input is valid checks if input is an operand
	BRnp PRINT_INVALID ; If input isn't valid prints to screen invalid expression

OPERAND_CHECKER ;

	LD R1, ADD1		;
	ADD R1, R1, R0		;
	BRz OPERAND_TRUE	;
	LD R1, MIN1		;
	ADD R1, R1, R0		;
	BRz OPERAND_TRUE	;
	LD R1, MULT1		;
	ADD R1, R1, R0		;
	BRz OPERAND_TRUE	;
	LD R1, DIV1		;
	ADD R1, R1, R0		;
	BRz OPERAND_TRUE	;
	BRnp OPERAND_FALSE ; If input isn't operand, input must be digit

OPERAND_TRUE

	JSR PUSH ; Pushes operand onto stack
	BRnzp NEW_CHARACTER ; Gets next character

OPERAND_FALSE

	JSR POP ; Pops digit 1 from stack
	ST R3, SAVE_VALUE ;
	JSR POP ; Pops digit two from stack
	AND R4, R4, #0 ;
	ADD R4, R3, #0 ;
	LDI R3, SAVE_VALUE ;
	ADD R5, R5, #0 ;
	BRp PRINT_INVALID ;
	BRz APPLY_OPERAND ; Gets operand for computation

PRINT_INVALID

	LEA R0, INVALID_EXPRESSION ;
	PUTS ;
	BRnzp  DONE ;

APPLY_OPERAND ; Determines which operand is used and jumps to respective subroutine

	LD R1, ADD1		;
	ADD R1, R1, R0		;
	BRz PLUS	;
	BRz OPERAND_TRUE	; Pushes operand onto stack
	LD R1, MIN1		;
	ADD R1, R1, R0		;
	BRz MIN	;
	BRz OPERAND_TRUE	;
	LD R1, MULT1	;
	ADD R1, R1, R0		;
	BRz MUL	;
	BRz OPERAND_TRUE	;
	LD R1, DIV1		;
	ADD R1, R1, R0		;
	BRz DIV	;
	BRz OPERAND_TRUE	;

DONE

    HALT ;


; PRINT_HEX
;   Description: prints out the value in R3 to the console
;   Inputs: R3 - value in register to be printed out
;   Outputs: Value printed to the console

PRINT_HEX ; implements lab1 algorithm to print value in hexadecimal

; INSERT CODE HERE!

AND R5, R5, #0 ;
ADD R5, R3, #0 ;
AND R4, R4, #0 ;
ADD R4, R4, #4 ; digit counter

OUTERLOOP

	ADD R4, R4, #0 ;
	BRz DONE1 ;
	AND R2, R2, #0 ;
	AND R3, R3, #0 ;
	ADD R3, R3, #4 ;

INNERLOOP

	ADD R3, R3, #0 ;
	BRz DIGITCHECK ;

	ADD R2, R2, R2 ;
	BRn NEG
	BRp POS

CHECKER_RETURN

	ADD R5, R5, R5 ;
	ADD R3, R3, #-1 ;
	BRnzp INNERLOOP ;

NEG

	ADD R2, R2, #1 ;
	BRnzp CHECKER_RETURN ;

POS

	ADD R2, R2, #0 ;
	BRnzp CHECKER_RETURN ;

DIGITCHECK

	AND R1, R1, #0 ;
	ADD R1, R2, #-9 ;
	BRnz TRUE
	BRp FALSE

TRUE

	LD R6, ZERO_OFFSET ;
	ADD R2, R2, R6 ;
	OUT ;
	ADD R4, R4, #-1 ;
	BRnzp OUTERLOOP ;

FALSE

	LD R6, A_OFFSET ;
	ADD R2, R2, R6 ;
	OUT ;
	ADD R4, R4, #-1 ;
	BRnzp OUTERLOOP ;

DONE1

	RET ;

; EVALUATE
;   Description: handles input from console
;   Inputs: Console - input
;   Outputs: Console - evaluation of expression or error
;	     R5 - evalution of expression
EVALUATE

; INSERT CODE HERE!


; PLUS
;   Description: adds two numbers (R0 = R3 + R4)
;   Inputs: R3 - addend
;	    R4 - addend
;   Outputs: R0 - sum
PLUS

; INSERT CODE HERE!

	AND R0, R0, #0		;
	ADD R0, R3, R4		;
	RET			;


; MIN
;   Description: subtracts two numbers (R0 = R3 - R4)
;   Inputs: R3 - minuend
;	    R4 - subtrahend
;   Outputs: R0 - difference
MIN

; INSERT CODE HERE!

	AND R0, R0, #0		;
	NOT R4, R4		;
	ADD R4, R4, #1		;
	ADD R0, R3, R4		;
	RET			;

; MUL
;   Description: multiplies two numbers (R0 = R3 * R4)
;   Inputs: R3 - factor
;	    R4 - factor
;   Outputs: R0 - product

MUL

; INSERT CODE HERE!

	AND R0, R0, #0		;
	ADD R3, R3, #0 ;
	BRz ZERO_MUL ;
	BRn NEG_MUL ;
	BRp POS_MUL ;

ZERO_MUL
		RET ;

NEG_MUL

NEXTADD1

	ADD R0, R0, R4		;
	ADD R3, R3, #1 	;
	BRp 	NEXTADD1	;
	RET			;

POS_MUL

NEXTADD

	ADD R0, R0, R4		;
	ADD R3, R3, #-1 	;
	BRp 	NEXTADD		;
	RET			;

; DIV
;   Description: divides two numbers (R0 = R3 / R4)
;   Inputs: R3 - numerator
;	    R4 - denominator
;   Outputs: R0 - quotient

DIV

; INSERT CODE HERE!

	AND R0, R0, #0		;
	NOT R4, R4        ;
	ADD R4, R4, #1    ;

RELOOP

	ADD R3, R3, R4    ;
	BRn  	GTFO        ;
	ADD R0, R0, #1    ;
	BRp 	RELOOP      ;

GTFO
        RET               ;



; PUSH
;   Description: Pushes a charcter unto the stack
;   Inputs: R0 - character to push unto the stack
;   Outputs: R5 - 0 (success) or 1 (failure/overflow)
;   Registers: R3 - stores STACK_END
;	       R4 - stores STACK_TOP
PUSH
	ST R3, PUSH_SaveR3	; save R3
	ST R4, PUSH_SaveR4	; save R4
	AND R5, R5, #0		;
	LD R3, STACK_END	;
	LD R4, STACk_TOP	;
	ADD R3, R3, #-1		;
	NOT R3, R3		;
	ADD R3, R3, #1		;
	ADD R3, R3, R4		;
	BRz OVERFLOW		; stack is full
	STR R0, R4, #0		; no overflow, store value in the stack
	ADD R4, R4, #-1		; move top of the stack
	ST R4, STACK_TOP	; store top of stack pointer
	BRnzp DONE_PUSH		;
OVERFLOW
	ADD R5, R5, #1		;
DONE_PUSH
	LD R3, PUSH_SaveR3	;
	LD R4, PUSH_SaveR4	;
	RET


PUSH_SaveR3	.BLKW #1	;
PUSH_SaveR4	.BLKW #1	;


; POP
;   Description: Pops a character off the stack
;   Inputs:
;   Outputs: R0 - character popped off the stack
;	     R5 - 0 (success) or 1 (failure/underflow)
;   Registers: R3 - stores STACK_END
;	       R4 - stores STACK_TOP

POP
	ST R3, POP_SaveR3	; save R3
	ST R4, POP_SaveR4	; save R3
	AND R5, R5, #0		; clear R5
	LD R3, STACK_START	;
	LD R4, STACK_TOP	;
	NOT R3, R3		;
	ADD R3, R3, #1		;
	ADD R3, R3, R4		;
	BRz UNDERFLOW		;
	ADD R4, R4, #1		;
	LDR R0, R4, #0		;
	ST R4, STACK_TOP	;
	BRnzp DONE_POP		;
UNDERFLOW
	ADD R5, R5, #1		;
DONE_POP
	LD R3, POP_SaveR3	;
	LD R4, POP_SaveR4	;
	RET


POP_SaveR3	.BLKW #1	;
POP_SaveR4	.BLKW #1	;
STACK_END	.FILL x3FF0	;
STACK_START	.FILL x4000	;
STACK_TOP	.FILL x4000	;

SAVE_VALUE .BLKW #1 ;
INVALID_EXPRESSION .stringz "Invalid Expression" ;

ZERO .FILL x0000 ;
ONE .FILL xFFFF ;
TWO .FILL xFFFE ;
THREE .FILL xFFFD ;
FOUR .FILL xFFFC ;
FIVE .FILL xFFFB ;
SIX .FILL xFFFA ;
SEVEN .FILL xFFF9 ;
EIGHT .FILL xFFF8 ;
NINE .FILL xFFF7 ;
ADD1 .FILL xFFC2 ;
MIN1 .FILL xFFC4 ;
MULT1 .FILL xFFC3 ;
DIV1 .FILL xFFB1 ;
EQUAL .FILL xFFCD ;
SPACE .FILL xFFC0 ;
ZERO_OFFSET .FILL x0030 ;
A_OFFSET .FILL x0067 ;
.END
