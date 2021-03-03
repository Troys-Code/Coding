#
# Assignment2Exercise4.asm
# Troy Schultz
# Second Assignment Math Exercises
# Allowed Instructions: 
# add addi addiu addu and andi div divu li lui lw mfhi mflo
# mult multu nor or ori sll sra srl sub subu sw xor xori
#

	.text
	.globl	main

main:	

# Exercise 4 – Expression Evaluation (for this one disallow macros!):
	
	ori	$t0, $zero, 0x00186A	# For ori 16-bit limitation remove last two 0, we must then shift left by 8 to get it back
	ori	$t1, $zero, 0x0001388	# removing last 0, we must shift left by 4 to get back
	ori	$t2, $zero, 0x00061A8	# removing last 0 we must shift left by 4 to get back
	
	sll	$t0, $t0, 8		# to get to the originally desired value we shifted appropriately 
	sll	$t1, $t1, 4
	sll	$t2, $t2, 4

	div	$t0, $t2		# x/z
	mflo	$t0			# $t0 = x/z (low order bit)
	sll	$t0, $t0, 0		# DELAY slot 1 Essentially does nothing to take up a cycle
	sll	$t0, $t0, 0		# DELAY slot 2 Essentially does nothing to take up a cycle

	mult	$t0, $t1		# (x/y) * z
	mflo	$t0			# $t0 = (x/y)*z
	sll	$t0, $t0, 0		# DELAY slot 1 Essentially does nothing to take up cycle
	sll	$t0, $t0, 0		# DELAY slot 2 Essentially does nothing to take up a cycle
					# The last 2 delay instructions are not needed as its the end of the program
## End of file
