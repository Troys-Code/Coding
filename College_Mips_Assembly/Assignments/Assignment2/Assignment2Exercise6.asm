#
# Assignment2Exercise6.asm
# Troy Schultz
# Second Assignment Math Exercises
# Allowed Instructions: 
# add addi addiu addu and andi div divu li lui lw mfhi mflo
# mult multu nor or ori sll sra srl sub subu sw xor xori
#

# Exercise 6: Evaluate the Polynomial 18xy + 12x - 6y + 12

	.data	
x:	.word	0	# To represent x in the polynomial	
y:	.word	-1	# To represent y in the polynomial	
answer:	.word	0	# 32-bit variable answer to hold the result

	.text
	.globl main
	

main: 

lw	$t0, x		# Load the value in x into register $t0
lw	$t1, y
li	$t2, 18		# Coefficient 18 loaded into $t2
li	$t3, 12		# Coefficient 12 loaded into $t3
li	$t4, -6		# Coefficient -6 loaded into $t4

mult	$t0, $t1	# Multiply (x)(y) to get xy in low
mflo	$t5		# $t5 = xy
nop			# Delay slot 1 
nop			# Delay slot 2 

mult	$t2, $t5	# Multiply (18)*(xy), result is stored in lo
mflo	$s0		# $s0 = 18xy	
nop			# Delay slot 1 
nop			# Delay slot 2 

mult	$t3, $t0	# Multiply (12)*(x), result is stored in lo
mflo	$s1		# $s1 = 12x
nop			# Delay Slot 1
nop			# Delay Slot 2

mult	$t4, $t1	# Multiply (6)*(y), result is stored in lo
mflo	$s2		# $s2 holds 6(y)
addu	$s3, $s0, $s1	# Delay Slot 1: $s3 holds 18xy + 12x
addu	$s3, $s3, $s2	# Delay Slot 2: $s3 holds 18xy + 12x + 6y
addi	$s3, $s3, 12	# $s3 holds 18xy + 12x + 6y + 12

sw	$s3, answer	# store the 32-bit result into answer label
	
## End of file

	