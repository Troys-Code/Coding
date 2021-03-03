#
# Assignment5.asm
# Troy Schultz
# Nov/3/2020
#
# Mips program that computes the sum of the first part of the harmonic series
# 1/1 + 1/2 + 1/3 + 1/4 + ... 1/n
#	
	.data
Msg1:	.asciiz "\nEnter the number of terms to sum: "
Res1:	.asciiz "\nThe Harmonic series resulting sum is:  "
	
	.text
	.globl	main
	
main:
	li.s	$f1, 0.0		# $f1 = 0.0 : Initialize Sum to 0.0
	li.s	$f2, 1.0		# $f2 = 1.0 : Initialize numerator to 1.0
	li.s	$f3, 0.0		# $f3 = 0.0 : Initialize temp used for (1.0 / i) to 0.0
	li.s	$f4, 0.0		# $f4 = 0.0 : Initialize End Condition of loop to 0.0
	
	li	$v0, 4			# System call code (4) to print string
	la	$a0, Msg1		# Load address of Label string Msg1 in $a0
	syscall				# Prompts: "Enter the number of terms to sum"

	li	$v0, 5			# Code '5' used to read in ints
	syscall				# User entered value will be stored in $v0
	mtc1	$v0, $f5		# Move bit pattern $v0 -> $f5 : No conversion done
	cvt.s.w	$f5, $f5		# Convert word stored in $f5 to single float stored in $f5 : number of terms
	
WhileLoop:
	c.eq.s	$f5, $f4		# Condition Flag = (Number Of Terms == 0.0) : True or False
	bc1t	Exit			# If condition is True : Branch to Exit
	div.s	$f3, $f2, $f5		# $f3 = (1.0) / (Number Of Terms)
	add.s	$f1, $f1, $f3		# ($f1 = sum ) = sum + ( 1 / (Number Of Terms) )  
	sub.s	$f5, $f5, $f2		# ($f5 = Number Of Terms) - 1.0 terms : Decrement 
	b	WhileLoop		# Go back to the top of Loop
Exit:

	li	$v0, 4			# System call code (4) to print string
	la	$a0, Res1		# Load address of Label string Res1 in $a0
	syscall				# Prints Result Message
	
	li	$v0, 2			# System call code (2) to print Floats from $f12
	mov.s	$f12, $f1		# Copies bit pattern $f12 <- $f1 to be printed
	syscall				# Prints float value in $f12
	
	li	$v0, 10			# System call code (10) to Exit Program
	syscall

## End of file
