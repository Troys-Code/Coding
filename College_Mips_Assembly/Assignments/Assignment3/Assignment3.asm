#
# Assignment3.asm
# Troy Schultz
# Oct/26/2020
# Assignment 3 for CSCI 21
# Using branch macros to use loops for various exercises
#
	.text
	.globl	main
main:
	ori	$t0, $zero, 0		# Initialize register to contain the sum
	ori	$t1, $zero, 1		# Initialize register to be the counter
	ori	$t2, $zero, 101		# Initialize to mark end sequence

while1:
	nop
	addu	$t0, $t0, $t1		# $t0 = $t0 + $t1 : sum = sum + counter
	addiu	$t1, $t1, 1		# $t1 += 1 	  : increment counter
	blt	$t1, $t2, while1	# If ($t1 < $t2)  : if (counter < end) branch to top of loop Label

	# Exercise 2 : Compute three sums

	li	$t0,  0			# For sum of even integers
	li	$t1,  0			# For sum of odd integers
	li	$t2,  0			# For sum of all integers
	li	$t3, 101		# Initialize end of loop counter
	li	$t4, 1			# Initialize register to be a counter

while2:
	andi	$t5, $t4, 1		# $t5 = if LSB is 1 for both $t5 = 1 indicates odd, else 0 for even
	bgtz	$t5, odd		# if $t5 > 0, branch to Label odd
	nop
	addu	$t0, $t0, $t4		# $t0 += $t4 	  : Adds $t4 even value to Even sum $t0
	b	all			# branch to all
	nop
odd:
	addu	$t1, $t1, $t4		# $t1 = $t1 + $t4 : Adds Odd value in $t4 to $t1 the Odd sum

all:
	addu	$t2, $t2, $t4		# $t2 += $t4 : Adds the value odd or even in $t4 to All sum
	addiu	$t4, $t4, 1		# $t4++	     : Increment Counter
	blt	$t4, $t3, while2	# if ($t4 < $t3), if (counter < end) branch to top loop
	nop

	# Exercise 3 Fibonacci Series

	li	$t0, 0			# Fixed number for fib = 0  : for previous
	li	$t1, 1			# Fixed number for fib = 1  : for current
	li	$t2, 0			# Place holder to chain sequence together
	li	$t3, 2			# Counter : starting at 2 since first two numbers fixed 0,1
	ori	$t4, $zero, 101		# Initialize to mark end of loop counter at 101

while3:
	addiu	$t2, $t1, 0		# $t2 = $t1 		: temp = current
	addu	$t1, $t0, $t1		# $t1 = $t0 + $t1	: current = previous + current
	addiu	$t0, $t2, 0		# $t0 = $t2		: previous = current
	addiu	$t3, $t3, 1		# $t3++			: Increment Counter
	blt	$t3, $t4, while3	# if ($t3 < 101) Branch back to top of while loop
	nop

	li	$v0, 10
	syscall

	# End of file

