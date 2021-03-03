#
# Add2Plus3.asm
# Keith Mehl
# adapted from programmed introduction to MIPS assembly language tutorial
# Program to add two plus three 
#

	.text
	.globl	main

main:	ori	$t0, $zero, 2	# put two into register $8 ($t0)
	ori	$t1, $zero, 3	# put three into register $9 ($t1)
	addu	$t2, $t0, $t1	# add register 8 and 9, put result in $10 ($t2)

## End of file
