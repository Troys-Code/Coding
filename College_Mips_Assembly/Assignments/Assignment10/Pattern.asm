#
# Pattern.asm
# Troy Schultz
# Create Pattern with one 1 set bit and logical bit operations
#

	.text
	.globl	main

main:	ori	$t0, $zero, 1	# $t0 = 0001	= 1
	sll	$t1, $t0, 4	# $t1 = 0001 0000
	sll	$t2, $t0, 1	
	or	$t2, $t2, $t0
	sll	$t2, $t2, 1
	or	$t2, $t2, $t0	
	sll	$t2, $t2, 1	# $t2 = E
	
	or	$t2, $t1, $t2	# $t2 = 1E	
	or	$t1, $t2, $t1	# $t1 = 1e
	sll	$t1, $t1, 8	# $t1 = 0x1e00
	or	$t2, $t1, $t2	# $t2 = 0x1e1e
	sll	$t1, $t2, 16	# $t1 = 0x 1E1E0000
	or	$t1, $t1, $t2	# $t1 = 0x 1E1E1E1E
	
	


		

	

## End of file
