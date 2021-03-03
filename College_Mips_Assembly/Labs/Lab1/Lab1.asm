#
# Lab1.asm
# Troy Schultz
# Lab 1 Including Work Check for problem 1
# Program executes or,and,xor,nor on two given hex 
#

	.text
	.globl	main

main:	

# Question 1
	ori	$t0, $zero, 0x1234	# put 0x1234 into register $8 ($t0)
	ori	$t1, $zero, 0xFFFF	# put 0xFFFF into register $9 ($t1)
	or	$t2, $t0, $t1		# or register 8 and 9, put result in $10 ($t2)
	and	$t3, $t0, $t1		# and register 8 and 9, put result in $11 ($t3)
	xor	$t4, $t0, $t1		# xor register 8 and 9, put result in $12 ($t4)
	nor	$t5, $t0, $t1		# nor register 8 and 9, put result in $13 ($t5)

	ori	$t0, $zero, 0xFEDC	# put 0xFEDC into register $8 ($t0)
	ori	$t1, $zero, 0x5678	# put 0x5678 into register $9 ($t1)
	or	$t2, $t0, $t1		# or register 8 and 9, put result in $10 ($t2)
	and	$t3, $t0, $t1		# and register 8 and 9, put result in $11 ($t3)
	xor	$t4, $t0, $t1		# xor register 8 and 9, put result in $12 ($t4)
	nor	$t5, $t0, $t1		# nor register 8 and 9, put result in $13 ($t5)
	
# Question 2
	ori	$t0, $zero, 0xFFFF	# put 0x4321 into register $8 ($t0)
	nor	$t1, $t0, $zero		# nor 0x4321 against zero, put result into $14 (t1)
	
	ori	$t0, $zero, 0x0000	# put 0xCDEF into register $8 ($t0)
	nor	$t1, $t0, $zero		# nor 0xCDEF against zero, put result into register $14 (t6)
	
#Question 3
	li	$t0, 0xFFFFFFFF		# load immediate value 0xFFFFFFFF into $8 ($t0)
	sll	$t1, $t0, 2	 	# load in t1 the value of t0 shifted left 2
	sll	$t2, $t0, 3	 	# load in t1 the value of t0 shifted left 3
	sll	$t3, $t0, 4	 	# load in t1 the value of t0 shifted left 4
	sll	$t4, $t0, 5	 	# load in t1 the value of t0 shifted left 5
	
	srl	$t1, $t0, 2		# load in t1 the value of t0 shifted right logicaly 2 
	srl	$t2, $t0, 3		# load in t1 the value of t0 shifted right logicaly 3
	srl	$t3, $t0, 4		# load in t1 the value of t0 shifted right logicaly 4
	srl	$t4, $t0, 5		# load in t1 the value of t0 shifted right logicaly 5 
	
	sra	$t1, $t0, 2		# load in t1 the value of t0 shifted right arithmetic 2 
	sra	$t2, $t0, 3		# load in t1 the value of t0 shifted right arithmetic 3
	sra	$t3, $t0, 4		# load in t1 the value of t0 shifted right arithmetic 3
	sra	$t4, $t0, 5		# load in t1 the value of t0 shifted right arithmetic 3
	

	li	$t0, 0x96969696		# load immediate value 0xFFFFFFFF into $8 ($t0)
	sll	$t1,t0,2	 	# load in t1 the value of t0 shifted left 2
	sll	$t2,t0,3	 	# load in t1 the value of t0 shifted left 3
	sll	$t3,t0,4	 	# load in t1 the value of t0 shifted left 4
	sll	$t4,t0,5	 	# load in t1 the value of t0 shifted left 5qt


	li	$t0, 0x8754321		# load immediate value 0x87654321 into $8 ($t0)
	sll	$t1, $t0, 2		# load in t1 the value of t0 shifted left 2 places
	sll	$t2, $t0, 3		# load in t1 the value of t0 shifted left 3 places
	sll	$t3, $t0, 4		# load in t1 the value of t0 shifted left 4 places
	sll	$t4, $t0, 5		# load in t1 the value of t0 shifted left 5 places

	srl	$t1, $t0, 2		# load in t1 the value of t0 shifted right 2 places
	srl	$t2, $t0, 3		# load in t1 the value of t0 shifted right 3 places
	srl	$t3, $t0, 4		# load in t1 the value of t0 shifted right 4 places
	srl	$t4, $t0, 5		# load in t1 the value of t0 shifted right 5 places

	sra	$t1, $t0, 2		# load in t1 the value of t0 shifted right 2 places(preserve sign)
	sra	$t2, $t0, 3		# load in t1 the value of t0 shifted right 3 places(preserve sign)
	sra	$t3, $t0, 4		# load in t1 the value of t0 shifted right 4 places(preserve sign)
	sra	$t4, $t0, 5		# load in t1 the value of t0 shifted right 5 places(preserve sign)

## End of file
