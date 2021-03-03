#
# Assignment2.asm
# Troy Schultz
# Second Assignment Math Exercises
# Allowed Instructions: 
# add addi addiu addu and andi div divu li lui lw mfhi mflo
# mult multu nor or ori sll sra srl sub subu sw xor xori
#

	.text
	.globl	main

main:	

# Exercise 1
	li	$t0, 0		# Macro does ori on small values, subtract positive value from 0 on negative values
	li	$t1, 456	# For operands that are 16-bits or smaller in size, li translates to a single instruction
	li	$t2, -229	# Multiple instructions are performed for negative immediate values due to their sign bit
	li	$t3, 325	# Being the High order bit of 1, extending 1s to be greater size than 16bit
	li	$t4, -552
	add	$t0, $t1, $t2
	add	$t0, $t0, $t3
	add	$t0, $t0, $t4

# Exercise 2
	ori	$t0, $zero, 0		# Reinitialize $t0 = 0 to hold a new sum
	
	addi	$t0, $t0, 0x1000	# Add 4096 to t0 16 times by repeating the instruction 16 times
	addi	$t0, $t0, 0x1000
	addi	$t0, $t0, 0x1000
	addi	$t0, $t0, 0x1000
	addi	$t0, $t0, 0x1000
	addi	$t0, $t0, 0x1000
	addi	$t0, $t0, 0x1000
	addi	$t0, $t0, 0x1000
	addi	$t0, $t0, 0x1000
	addi	$t0, $t0, 0x1000
	addi	$t0, $t0, 0x1000
	addi	$t0, $t0, 0x1000
	addi	$t0, $t0, 0x1000
	addi	$t0, $t0, 0x1000
	addi	$t0, $t0, 0x1000
	addi	$t0, $t0, 0x1000

	li	$t1, 0x1000		# Initialize $t1 = 4096
	sll	$t1, $t1, 4		# Shift Left Logical 4 places is equivalent to multiplying by 2^4 = 16	

	li	$t2, 0x1000		# Initialize $t2 = decimal 4096
	add	$t2, $t2, $t2		# Add $t2 to itself the correct number of times to get the same bit pattern as other 2
	add	$t2, $t2, $t2		# Since it is doubling each time, you would want to double it 4 times to be 2^4 = 16
	add	$t2, $t2, $t2
	add	$t2, $t2, $t2

# Exercise 3
	li	$t1, 0x7000		# $t1 = 0x7000 in hexadecimal which is base 16
	sll	$t1, $t1, 16		# $t1 = 0x70000000 after sll 16 b/c each place in hex is 4 bits, 4x4 = 16, so sll 2^16 to multiply
	addu	$t1, $t1, $t1		# Addu result to itself, is the result correct? No b/c it wraps negatives from positive addition

	li	$t2, 0x7000		# Repeat using add and determine what happens
	sll	$t2, $t2, 16
	add	$t2, $t2, $t2		# It errors out that Arithmetic overflow occurred	
	
## End of file
