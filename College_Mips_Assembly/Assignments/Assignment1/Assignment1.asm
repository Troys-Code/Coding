#
# Assn1.asm
# Troy Schultz
# Sept/15/2020
# Assignment 1 
# Program can execute and,nor,or,sll,srl,xor,(ori for the originally set 0x01 for each exercise)
# Using a single 0x1 bit we come up with given pattern with bit manipulation
#

	.text
	.globl	main

main:	

# Quiz question A5A5A5A5



	ori	$t0, $zero, 0x01	
	sll	$t1, $t0, 1
	sll	$t2, $t1, 2
	or	$t1,$t1,$t2
	sll	$t1,$t1,4
	srl	$t2,$t2,1
	or 	$t2,$t2,$t0
	or	$t3, $t1, $t2
	sll	$t2,$t3,8
	or 	$t3,$t2,$t3
	sll	$t2,$t3, 16
	or $t1, $t2, $t3
## End of file
