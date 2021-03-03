#
# Add2Plus3.asm
# Keith Mehl
# adapted from programmed introduction to MIPS assembly language tutorial
# Program to add two plus three 
#	
	.data
Prompt:	.asciiz	"\nPlease Enter A Value to be added to 42 "
Result:	.asciiz	"The Sum of N + 42 is "
	.globl	main
	.text

main:
	li	$v0, 4		# System call code (4) to print string
	la	$a0, Prompt	# Load address of Label string "Prompt" in $a0
	syscall			# Prints String

	li	$v0, 5		# System call code (5) to read in an integer
	syscall			# Reads in an integer ad stores in $v0
	
	li	$t0, 42		# Loads 42 into $t0 to be added to (usersNumber)
	add	$t0, $t0, $v0	# $t0 = 42 + (usersNumber)
	
	li	$v0, 4		# System call code (4) to print string
	la	$a0, Result	# Load address of Label string "Result" in $a0
	syscall			# Prints Result String

	li	$v0, 1		# System call code (1) to print an integer
	move	$a0, $t0	# Copies value in $t0 into $a0
	syscall			# Prints sum stored in $a0 = $t0 = N + 4
	
	li	$v0, 10		# System call code (10) to Exit Program
	syscall

## End of file
