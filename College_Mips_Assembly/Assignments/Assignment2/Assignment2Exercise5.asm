#
# Assignment2Exercise5.asm
# Troy Schultz
# Second Assignment Math Exercises
# Allowed Instructions: 
# add addi addiu addu and andi div divu li lui lw mfhi mflo
# mult multu nor or ori sll sra srl sub subu sw xor xori
#

# Exercise 5: Evaluate the Polynomial (2x^3 - 3x^2 + 5x + 12)

	.data	
x:	.word	-1	# To represent x in the polynomial		
answer:	.word	0	# 32-bit variable answer to hold the result
	
	.text
	.globl main
	

main: 

lw	$t0, x		# Load the value in x into register $t0
li	$t1, -3		# Load immediate coefficient (-3) into register $t1
li	$t2, 5		# Load immediate coefficient (5) into register $t2

mult	$t0, $t0	# Multiply (x)(x) to get x^2, result is stored in lo
mflo	$t3		# $t3 = x^2
nop			# Delay slot 1 for mult/div instructions
nop			# Delay slot 2 for mult/div instructions

mult	$t0, $t3	# Multiply (x^2)(x) to get x^3, result is stored in lo
mflo	$t4		# $t4 = x^3
nop			# Delay slot 1 for mult/div instructions
sll	$s0, $t4, 1	# Delay Slot 2: Multiply (x^3) by 2 by shifting left 1 and store in $s0: $s0 = 2x^3

mult	$t1, $t3	# Multiply (-3) * (x^2), result is stored in lo
mflo	$s1		# $s1 = -3x^2
nop			# Delay Slot 1
nop			# Delay Slot 2

mult	$t2, $t0	# Multiply (5)*(x), result is stored in lo
mflo	$s2		# $s2 holds 5(x)
addu	$s3, $s0, $s1	# $s3 holds 2x^3 - 3x^2
addu	$s3, $s3, $s2	# $s3 holds 2x^3 - 3x^2 + 5x
addi	$s3, $s3, 12	# $s3 holds 2x^3 - 3x^2 + 5x + 12

sw	$s3, answer	# store the result in $s3 into the 32-bit word label answer
	
## End of file

	