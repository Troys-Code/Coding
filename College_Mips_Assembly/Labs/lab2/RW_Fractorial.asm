

#	Real world Factorial program


################# MAIN FOR REAL WORLD FACTORIAL ################################

	.data
prompt:	.asciiz "\nEnter an Integer: "
res1:	.asciiz	"\nFactorial("
res2:	.asciiz ")= "
N:	.word	0
Result:	.word	0
	.text
	.globl	main

main:

	la	$a0, prompt
	li	$v0, 4			# Prompt user to enter an integer
	syscall

	li	$v0, 5			# Read in an integer 
	syscall				# Result in $v0
	
	sw	$v0, N			# Store Users N to Named Variable
	nop

	addiu	$sp, $sp, -4		
	sw	$v0, 0($sp)		# Push N on the stack for RW Subroutine
	nop

	jal	Fact			# Sub Call to Factorial
	nop				# Result stored in $v0

	sw	$v0, Result		# Store Fact(N) Result to Named Variable 
	nop	

	la	$a0, res1
	li	$v0, 4			# Print "Factorial("
	syscall

	lw	$a0, N			# Print "Factorial(N"
	li	$v0, 1			
	syscall

	la	$a0, res2
	li	$v0, 4			# Print "Factorial(N)= "
	syscall

	lw	$a0, Result			
	li	$v0, 1			# Print "Factorial([N])= [Result]"
	syscall


	li	$v0, 10			# Code "10" to end program
	syscall			

######################### REAL WORLD FACTORIAL FUNCTION #######################

Fact:
	lw	$a0, 0($sp)		# Load N from Stack Params
	nop
Factorial:
	addiu	$fp, $sp, -16		# Make room for local variables
	move	$sp, $fp		# $sp = $fp

	sw	$a0, 0($fp)		# push N
	nop
	
	sw	$fp, 8($fp)		# push fp 
	nop

	sw	$ra, 12($fp)		# push $ra
	nop

	slti	$t0, $a0, 2		# Set $t0 = 1: if (N < 2)
	 
	beqz	$t0, recurse		# if (N > 2) {recurse}
	nop
	
	li	$v0, 1			# else {return 1}
	j	epilog
	nop

recurse:
	sub	$a0, $a0, 1		# N = (N-1)
	sw	$a0, 4($fp)		# Push (N-1)	
	nop
	
	jal	Factorial		# Call factorial(N-1)
	nop				# Return value is in $v0
	
	lw	$a0, 0($fp)		# Get N back
	nop
		
	mult	$a0, $v0		# $v0 = (N * N-1)
	mflo	$v0			# $v0 = Final result of Factorial(N)
epilog:	
	
	lw	$ra, 12($fp)		# Return $ra
	nop
	
	lw	$fp, 8($fp)		# Return $fp
	nop

	addiu	$sp, $fp, 16		# restore space used for local variables
	move	$fp, $sp
	jr	$ra			# return to caller
	nop	
	


## End of file
