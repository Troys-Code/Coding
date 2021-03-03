#
# Assignment5_ex1.asm
# Troy Schultz
# Nov/3/2020
#
# Mips program that computes value of the following arithmetic expression: 
# 5.4xy - 12.3y + 18.23x - 8.23 for values of x and y entered by the user 
#	
	.data
Msg1:	.asciiz "\nEnter A Value for X: "
Msg2:	.asciiz "Enter A Value for Y: "
Res1:	.asciiz "\nResult of 5.4xy - 12.3y + 18.23x - 8.23 = "
	
	.text
	.globl	main
	
main:
	li.s	$f1, 5.4		# $f1 = 5.4
	li.s	$f2, 12.3		# $f2 = 12.3
	li.s	$f3, 18.23		# $f3 = 18.23
	li.s	$f4, 8.23		# $f4 = 8.23

	li	$v0, 4			# Code (4) to print string
	la	$a0, Msg1		# Load address of Label string Msg1 in $a0
	syscall				# Prints "Enter A Value for X" to prompt user

	li	$v0, 6			# Code (6) to read in float: Value stored in $f0
	syscall				# User enters value to be stored in $f0
	mov.s	$f5, $f0		# Move user entered value x in $f0 into $f5 
	
	li	$v0, 4			# Code (4) to print string
	la	$a0, Msg2		# Load address of Label string Msg2 in $a0
	syscall				# Prints "Enter A Value for Y" to prompt user
	
	li	$v0, 6			# Code (6) to read in float
	syscall				# Value entered are stored in $f0
	mov.s	$f6, $f0		# Move user entered value y in $f0 into $f6 
	
	mul.s	$f7, $f5, $f6		# $f7 = xy
	mul.s	$f7, $f1, $f7		# $f7 = 5.4xy
	mul.s	$f6, $f2, $f6		# $f6 = 12.3 * y
	mul.s	$f5, $f3, $f5		# $f5 = 18.23 * x

	sub.s	$f12, $f7, $f6		# $f12 = 5.4xy - 12.3y
	add.s	$f12, $f12, $f5		# $f12 = 5.4xy - 12.3y + 18.23x
	sub.s	$f12, $f12, $f4		# $f12 = 5.4xy - 12.3y + 18.23x - 8.23
	
	li	$v0, 4			# Code (4) to print string
	la	$a0, Res1		# Load address of Label string Res1 in $a0
	syscall				# Prints "Result 5.4xy - 12.3y + 18.23x - 8.23 = "	
	li	$v0, 2			# Code (2) to display floats stored in $f12
	syscall				# prints result stored in $f12
	
	li	$v0, 10			# Code (10) to Exit Program
	syscall

## End of file
