#
# Lab4.asm
# Troy Schultz
# Oct/25/2020
# MIPS program to implement the multiplication by shifting and adding algorithm.
#
# Get two positive integer entries from the user from console
# Multiply using sll and srl instructions to manipulate the operands
# Using andi with 1 to check for Odd/Even and addu to add as needed
# Assume positive entries, check work using mult instruction
#	
	.data
Msg1:	.asciiz "\nEnter A First Number: "
Msg2:	.asciiz "\nEnter A Second Number: "
Res1:	.asciiz "\nResult of Multiplication Using Shift and Add: "
Res2:	.asciiz "\nResult of Multiplication Using Mult: "
	
	.text
	.globl	main
	
main:
	li	$v0, 4		# System call code (4) to print string
	la	$a0, Msg1	# Load address of Label string Msg1 in $a0
	syscall			# Prints String "Enter A Number"

	li	$v0, 5		# System call code (5) to read in an integer
	syscall			# Reads in an integer and stores in $v0
	move	$t0, $v0	# Moves First User Entered Number from $v0 into Register $t0
	
	li	$v0, 4		# System call code (4) to print string
	la	$a0, Msg2	# Load address of Label string Msg2 in $a0
	syscall			# Prints String "Enter A Second Number"	
	
	li	$v0, 5		# System call code (5) to read in an integer
	syscall			# Reads in an integer and stores in $v0
	move	$t1, $v0	# Moves Second User Entered Number from $v0 into Register $t1

	mult	$t0, $t1	# Multiply The Two Numbers
	mflo 	$t2		# Store the Product into register $t2
	nop

	li	$v0, 4		# System call code (4) to print string
	la	$a0, Res2	# Load address of Label message Result2 in $a0
	syscall			# Prints message Result of Multiplication Using Mult:

	li	$v0, 1		# System call code (1) to print an integer
	move	$a0, $t2	# Moves value in $t2 -> $a0
	syscall			# Prints integer product
	
	# Now For The Shift and Add Method
	
	li	$t2, 0		# Initialize Temp register = 0
	li	$t3, 0		# Initialize RHS Sum register = 0
WhileLoop:
	andi	$t2, $t0, 1	# If ($t2 = 1) {LHS ($t0) is Odd}, else ($t2 = 0) {LHS($t0) is even}
	beqz	$t2, Even	# If $t2 is even, Don't add RHS Value to RHS sum, so branch to skip it
	nop
	addu	$t3, $t3, $t1	# $t2 Must have been odd, add RHS to RHS sum, $t3 = $t3 + $t1
Even:
	srl	$t0, $t0, 1	# LHS = LHS / 2
	beqz	$t0, Exit	# Exit Loop when LHS = 0
	nop
	sll	$t1, $t1, 1	# RHS = RHS * 2 
	b	WhileLoop	# Return to top of loop since LHS > 0 
	nop
Exit:	
	
	li	$v0, 4		# System call code (4) to print string
	la	$a0, Res1	# Load address of Label string Msg1 in $a0
	syscall			# Prints String "Result Using Shift And Add"
	
	li	$v0, 1		# System call code (1) to print an integer
	move	$a0, $t3	# Moves value in $t3 -> $a0 to be printed
	syscall			# Prints Result stored from $t3 -> $a0

	li	$v0, 10		# System call code (10) to Exit Program
	syscall

## End of file
