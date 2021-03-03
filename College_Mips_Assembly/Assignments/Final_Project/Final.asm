#
# Final.asm
# Troy Schultz 
# Dec/10/2020
#
# Interupt Handler: General Program Flow
# 1. Copy [source] array into [display] array using a subroutine passsing in
#	the address of the arrays on the stack.
# 2. Enable Interupts.
# 3. Loop Examining [quit] variable until the user enters q to exit the program
# 4. Whenever an output is ready (transmitter) interupt occurs
#	Interupt handler will print single character from the display
#	wrapping back to the beggining after it prints the '\n'
# 5. Whenever the input interupt (receiver) interupt occurs
#	Extracts the user's input (one char) and do one of the following tasks
#		's' to sort 
#		't' toggle case 
#		'a' to restore original string
#		'r' to reverse elements except '\n'
#		'q' to quit
#
# NOTE:	Load and branch delays are off to reduce complexity
#	For my version of SPIM on MAC .ktext must start at 0x80000180 
#
# 			Memory-Mapped I/O 
#
# Receiver Control	0xffff0000	(Keyboard)
# Receiver Data		0xffff0004
# Transmitter Control	0xffff0008	(Display)
# Transmitter Data	0xffff000c
#
# Control registers contain a ready-bit and an interrupt-enable bit.
# Transmitter
# 	Ready bit:	1 - display is ready to accept another byte
#			0 - display is not ready yet
# Receiver
#	Ready bit:	1 - there is data at the keyboard
#			0 - no input yet
# Note that the ready bit is set/unset by hardware.
###############################################################################

	.data
source:	.asciiz	"Heres 1: If you listen to a UNIX shell, can you hear the C?\n"
display:.space	100
quit:	.word	0
	.text
	.globl main

main:
	la	$s0, source
	sub	$sp, $sp, 4		# Push [Source] to the stack
	sw	$s0, ($sp)

	la	$s1, display
	sub	$sp, $sp, 4		# Push [display] to the stack
	sw	$s1, ($sp)

	jal	STR_COPY		# Subcall : Copy [source] -> [display]

	addiu	$sp, $sp, 8		# Pop params

	# Enable Interupts
	li	$s0, 0xC01		# Status Register Enable Bit Mask = $s0
	mtc0	$s0, $12		# Enable I/O Interrupts on CP0
	lui	$s0, 0xFFFF		# Load base address of MemMap I/O
	li	$s1, 0x2		# Interrupt enable mask
	sw	$s1, ($s0)		# Enable read control interrupt
	sw	$s1, 8($s0)		# Enable display control interrupt

Check_q:
	lw	$t0, quit		# Check Flag : [quit]
	beqz	$t0, Check_q		# if (Flag set) Program terminates

	li	$v0, 10			# Return Control To OS
	syscall

#************************ Copy the string ***********************************#

STR_COPY:	
	sub	$sp, $sp, 4		# Prolog: Push $ra
	sw	$ra, ($sp)
	sub	$sp, $sp, 4		# Prolog: Push $fp
	sw	$fp, ($sp)
	move	$fp, $sp		# $fp == $sp

	lw	$t0, 12($fp)		# Load [source] arg from the stack
	lw	$t1, 8($fp)		# Load display arg from the stack
	li	$t2, '\n'		# $t2 = '\n' to compare against
Str_loop:
	lb	$t3, ($t0)		# Load char (1-byte) : from [source]
	sb	$t3, ($t1)		# Store char (1-byte) : into [display]
	addiu	$t0, $t0, 1		# Increment source ptr
	addiu	$t1, $t1, 1		# Increment display ptr
	bne	$t3, $t2, Str_loop	# Loop until current character = '\n'
	
	lw	$fp, ($sp)		# Pop $fp
	addiu	$sp, $sp, 4
	lw	$ra, ($sp)		# Pop $ra
	addiu	$sp, $sp, 4
	jr	$ra			# Return to Caller

#************************ Exception Handler **********************************#

# When an interupt occurs, hardware transfers control to address 0x80000180
# Save any registers it may use
# Get exception code field from Cause Register
# Jump to interupt handler routine based on the exception code
# After handler is done Restore all registers back to previous state
# Return to the interupted program as it resumes its normal execution

	.kdata
s_at:	.word	0
s_t0:	.word	0
s_t1:	.word	0
s_t2:	.word	0
s_t3:	.word	0
s_t4:	.word	0
offset:	.word	0

	.ktext	0x80000180		# My SPIM version's kernel address

	.set noat			# Prevent Assembler from using $at
	move    $k0, $at		# Move $at to kernel
	.set at				# Must save: $at b/c pseudoinstructions

	sw	$k0, s_at		# Store Registers
	sw	$t0, s_t0		# To be returned to previous
	sw	$t1, s_t1		# Values after exception handling
	sw	$t2, s_t2		# Like it never happened
	sw	$t3, s_t3		#
	sw	$t4, s_t4		#

	# Interrupts Handled Here
	mfc0	$t0, $13		# Examine cause register => $t0
	andi	$t1, $t0, 0x7C		# Reads Exception Code (bit 6:2)
	bnez	$t1, Return		# if (No Interrupt) then Exit

	# Determine If Read or Transmitter Interrupt
	lui	$k0, 0xFFFF		# Load base address of MM I/O
	andi	$k1, $t0, 0xC00		# Mask for both Read & Transmitter
	li	$s0, 0x800		# Read control bit
	beq	$k1, $s0, EXC_READ	# Branch to EXC_READ if bit is set
	srl	$s0, $s0, 1		# 0x400 = display control bit
	beq	$k1, $s0, EXC_DISPLAY	# Branch to EXC_DISPLAY if bit is set

#************************ Read Handler ***************************************#

EXC_READ:
	lw	$t0, 4($k0)		# Get char from read data (As a word)
					# Check for: 's', 't', 'r', 'q', 'a'
	li	$t1, 'a'
	beq	$t0, $t1, REPLACE	# 'a' : Restores original string

	li	$t1, 'q'
	beq	$t0, $t1, QUIT		# 'q' : Quits the program

	li	$t1, 'r'
	beq	$t0, $t1, REVERSE	# 'r' : Reverses elements of the string

	li	$t1, 's'
	beq	$t0, $t1, SORT		# 's' : Sorts string (ascending order)

	li	$t1, 't'
	beq	$t0, $t1, TOGGLE	# 't' : Toggles Character Case

	j	Return			# Any other input is ignored

#************************ Display Handler ************************************#

EXC_DISPLAY:
	li	$k1, '\n'		# $k1 = newline
	lw	$t0, offset		# Load offset : current position in str
	lbu	$t1, display($t0)	# Load char at current str position
	xor	$t2, $k1, $t1		# Set Flag: $t2 == (0  OR '\n')
	addiu	$t0, $t0, 1		# Incremement str position: Offset++
	sw	$t0, offset		# Store new offset of current char pos

	bnez	$t2, print		# checkFlag:if(char != '\n' or 0) print
	sw	$zero, offset		# Reset offset : To beginning of str
print:					
	sw	$t1, 12($k0)		# Print the char to display
	j	Return			# Exit exception

#************************ Quit ***********************************************#

QUIT:
	li	$t1, 1
	sw	$t1, quit		# Sets [Quit] flag
	j	Return

#************************ Replace ********************************************#

REPLACE:
	la	$k0, source		# Load [source]
	la	$k1, display		# Load [display]
	li	$t0, '\n'		# Load '\n' to compare against
Repl_loop:
	lbu	$t1, ($k0)		# Load byte at [source]
	sb	$t1, ($k1)		# Store byte at [display]
	addiu	$k0, $k0, 1		# Increment [source] to next position
	addiu	$k1, $k1, 1		# Increment [display] to next position
	bne	$t0, $t1, Repl_loop
	j	Return			# Exit exception

#************************ Reverse ********************************************#

REVERSE:
	li	$t0, '\n'		# Load '\n' to compare against
	li	$t1, 0			# $t1 = F_Index
	li	$t2, -1			# $t2 = B_Index
Loop_until_NL:				# Loop to find the size of the string
	addiu	$t2, $t2, 1		# B_Index++
	lbu	$t3, display($t2)	# Load char from display[B_Index]
	bne	$t3, $t0, Loop_until_NL	# Loop until current char = '\n'

	addiu	$t2, $t2, -1		# Last char: One byte back from '\n'
Rev_loop:
	# Load Front Character and Back Character To Swap
	lbu	$t3, display($t1)	# Front Char: $t3 = display[F_Index]
	lbu	$t4, display($t2)	# Back Char: $t4 = display[B_Index]

	# Swap Characters
	sb	$t3, display($t2)	# Store: Front Char => Back Char
	sb	$t4, display($t1)	# Back Char => Front Char

	addiu	$t1, $t1, 1		# F_Index++
	addiu	$t2, $t2, -1		# B_Index--
	bgt	$t2, $t1 Rev_loop	# While( B_Index > F_Index){loop}
	j	Return			# Exit exception

#************************ Sort ***********************************************#

SORT:
	move	$k0, $zero		# Initialize : Offset0 = 0
	addiu	$k1, $k0, 1		# Initialize : Offset1 = (Offset0 + 1)
	li	$t3, '\n'		# Loop ends at '\n'
S_loop:
	lbu	$t0, display($k0)	# Load char at display[offset0]
	lbu	$t1, display($k1)	# Load char at display[offset1]
	beq	$t1, $t3, Return	# Exit Exception when '\n' is reached
	bgt	$t0, $t1, swap		# If (current > next) swap
	addiu	$k0, $k0, 1		# Increment Offset0 : (index)++
	addiu	$k1, $k1, 1		# Increment Offset1 : (index+1)++
	j	S_loop
swap:
	sb	$t0, display($k1)	# Swap the bytes
	sb	$t1, display($k0)	#
	move	$k0, $zero		# Reset Offset0
	addiu	$k1, $k0, 1		# Reset Offset1
	j	S_loop

#************************ Toggle ********************************************#

TOGGLE:
	li	$t0, 'a'		# Bounds of interest [a-z] and [A-Z]
	li	$t1, 'A'
	li	$t2, 'z'
	li	$t3, 'Z'
	li	$t4, '\n'		# NewLine to compare against
	la	$k0, display		# Load [display] into $k0
	addiu	$k0, $k0, -1		# Offset = -1 : loop initial increments
T_loop:
	addiu	$k0, $k0, 1		# Increment offset
	lb	$k1, ($k0)		# Current char from [display] -> $k1
	beq	$k1, $t4, Return	# if (char == '\n') Exit
	bgt	$k1, $t2, T_loop	# if (char > 'z') ignore it and loop
	blt	$k1, $t0, UpperCase	# if (char < 'a') its an Uppercase
	sub	$k1, $k1, 0x20		# Turns lower to uppercase
	sb	$k1, ($k0)		# Store back in [display]
	j	T_loop
UpperCase:
	blt	$k1, $t1, T_loop
	addiu	$k1, $k1, 0x20		# Turns upper to lowercase
	sb	$k1, ($k0)		# Store it back in [display]
	j	T_loop			# Go back to T_loop

#************************ End Exception Handler ******************************#

Return:					# Epilog For the Kernel
	lw	$t4, s_t4		# Restore used registers
	lw	$t3, s_t3		# Back to how they were
	lw	$t2, s_t2		# Before the exception
	lw	$t1, s_t1		# Like it never happened
	lw	$t0, s_t0
	lw	$k0, s_at
	.set noat
	move	$at, $k0		# Restore $at
	.set at
	eret				# Exception Return

### End of file
