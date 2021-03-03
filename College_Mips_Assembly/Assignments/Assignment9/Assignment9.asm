#
# Assignment9.asm
# Troy Schultz
# Dec/1/2020
#
# Mips Program recursion using a full stack frame
# Using "Real-World" Linkage convention to implement Fibonacci function
#

	.data
prompt:	.asciiz	"Enter an integer number "
res1:	.asciiz "\nFib("
res2:	.asciiz ") = "
	.text
	.globl main

main:	
	li	$v0, 4			# 
	la	$a0, prompt		# Prompt for an integer number
	syscall				#

	li	$v0, 5			# Read in integer N
	syscall				# Value entered will be in $v0
	
	sub	$sp, $sp, 12		# $sp = $sp - space
	sw	$v0, 4($sp)		# Offset|   Main Stack	|
	nop				#   8	|  $ra to OS	|
	sw	$ra, 8($sp)		#   4	|  Integer N	| 
	nop				#   0	|  Result FIB	|Top of stack
	
	jal	Fib			# Call Fib : Param popped from stack
	nop				# RETURN VALUE IN $v0
	sw	$v0, 0($sp)		# Save Return Value On the stack
	
	lw	$ra, 8($sp)		# Return $ra To give control back to OS 
	nop				# After Subroutine call
	
	li	$v0, 4			# 
	la	$a0, res1		# Print result message: "Fib("
	syscall				#
	
	li	$v0, 1			#
	lw	$a0, 4($sp)		# Print user entered N value
	nop				#
	syscall				#
	
	li	$v0, 4			# 
	la	$a0, res2		# Print result message: res2: ") = "
	syscall				#

	li	$v0, 1			#
	lw	$a0, 0($sp)		# Print the Result of Fib(N) 
	nop				#
	syscall				#

	add	$sp, $sp, 12		# Pop Mains Stack frame

	li	$v0, 10			# End of program
	syscall				#

Fib:
Fib_initial:				# Initially Trys to Avoid a stack frame
	lw	$v0, 4($sp)			
	nop
	ble	$v0, 1, Return_N	# If ( N <= 1) return N : No stackframe
	nop
	j	Fib_recurse		# Else (N > 1) Recurse 
	nop
Fib_Check:
	bgt	$v0, 1, Fib_recurse	# if (N > 1) Recurse	
	nop	
	j	Return_N		# Else return N 
	nop
Fib_recurse:
	sub	$sp, $sp, 12		# Create Space on stack : $fp, $ra, N
	sw	$v0, 0($sp)		# Push N 
	nop
	sw	$ra, 4($sp)		# Push $ra 
	nop
	sw	$fp, 8($sp)		# Push $fp
	
	sub	$fp, $sp, 4		# $sp = $sp - space : result Fib(N-1)
	move	$sp, $fp		# $sp = $fp :Both pt to bot of stack
	
	lw	$v0, 4($fp)		# Load : $v0 = N
	nop
	sub	$v0, $v0, 1		# $v0 = (N-1)
	
	jal	Fib_Check		# Confirm ( N-1 > 1) Before recursion
	nop				# Result returned in $v0
	sw	$v0, 0($fp)		# Store result of Fib(N-1)
	nop
					# We dont assume a value after a call 
	lw	$v0, 4($fp)		# Load back : $v0 = N
	nop				
	sub	$v0, $v0, 2		# $v0 = N-2
	jal	Fib_Check		# Confirm (N-2 > 1) before recursion
	nop				# Result in $v0

	lw	$t0, 0($fp)		# Restore : $t0 = Fib(N-1)
	nop				# Return Value: 
	addu	$v0, $t0, $v0		# $v0 = Fib(N-1) + Fib(N-2)

Epilog:
	add	$sp, $sp, 4		# Pop stack of Result Fib()
	lw	$fp, 8($sp)		# Restore $fp 
	nop
	lw	$ra, 4($sp)		# Restore $ra 
	nop
	add	$sp, $sp, 12		# Pop stack of $fp, $ra, N
Return_N:
	jr	$ra			# Return Value Stored in $v0
	nop

# End Of File
