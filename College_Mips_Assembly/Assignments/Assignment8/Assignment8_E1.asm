#
# Assignment8.asm
# Troy Schultz
# Dec/1/2020
#
# Mips Program triangle recursion
# Using Frame Based Linkage convention
#

	.data
prompt:	.asciiz	"Enter an integer number "
res1:	.asciiz "\nTriangle("
res2:	.asciiz ") = "
nl:	.asciiz "\n\n"
	.text
	.globl main

main:	
	li	$v0, 4				# 
	la	$a0, prompt			# Prompt user to enter an integer number
	syscall					#

	li	$v0, 5				# Read in integer
	syscall					# Value entered will be in $v0
	move	$s1, $v0			# Saved user entered value For Print Statement to be fancy

	# - Calling a subroutine ( Done By Caller ) -
	sub	$sp, $sp, 4			# Push Return address onto the stack
	sw	$ra, 0($sp)			#
	nop
	
	sub	$sp, $sp, 4			# Push callers frame pointer onto the stack
	sw	$fp, 0($sp)			# $fp = $sp no variables added to stack
	nop
	
	# - Subroutine Call -
	move	$a0, $v0			# Put user entered value into argument $a0
	jal	triangle			# Jump and link to subroutine
	nop
	
	move	$s2, $v0			# Save sub return value into $s2 to free up $v0
	
	li	$v0, 4				# 
	la	$a0, res1			# Print First half of result message: Triangle("
	syscall					#
	
	li	$v0, 1				#  
	move	$a0, $s1			# Print user entered N value between result message
	syscall					#
	li	$v0, 4				# 
	la	$a0, res2			# Print Second half of result message: res2:	) = "
	syscall					#
	
	li	$v0, 1				# 
	move	$a0, $s2			# Print Result of Recursive Triangle Function
	syscall
	
	li	$v0, 4				# 
	la	$a0, nl				# Print new line character for beauty
	syscall					#
	
	lw	$fp, 0($sp)			# 
	nop					# Pop $fp from the stack
	addiu	$sp, $sp, 4			# 
	
	lw	$ra, 0($sp)			# 
	nop					# pop $ra from the stack To return control back to OS
	addiu	$sp, $sp, 4			# 

	li	$v0, 10				# End of program
	syscall					#
		
triangle:	
	# - Subroutine Prolog -	
	sub	$sp, $sp, 4			# 
	sw	$ra, 0($sp)			# push $ra onto the stack
	nop					#
	
	sub	$sp, $sp, 4			# 
	sw	$fp, 0($sp)			# Push callers $fp onto the stack 
	nop					#
	
	sub	$fp, $sp, 4			# $fp = $sp - space for 1 4-byte variable for N on the stack
	move	$sp, $fp			# $sp = $fp : Now $fp and $sp are at the top of the stack
	
	# - Subroutine Body -
	sw	$a0, 0($fp)			# Push arguement ($a0 = n) as a local variable onto the stack frame
	nop					#
	
	li	$t1, 1				# Initialize a temp variable to 1 for comparisons 
	bleu	$a0, $t1, return_one		# if ($a0 = n) < = 1, go to return one
	nop					#
	
	addiu	$a0, $a0, -1			# N = N - 1
	
	jal	triangle			# Recursion Magic happens here
	nop					# ONCE TRIANGLE RECURSION IS DONE : $v0 holds the result
	
	move	$t0, $v0			# Temp0 <- Subroutine Return value (N-1)
	lw	$t2, 0($fp)			# Retrieve N value from stack frame
	nop						
	add	$v0, $t0, $t2  			# Return value result in $v0 : $v0 = N + Triangle(N-1)
	
	j	epilog				# Skip over the Base Case to Pop what we put onto the stack
	nop

return_one:	
	li	$v0, 1				# Returns value = 1
	
	# - Subroutine Epilog ( Done At The End Of The Subroutine ) -
epilog:
	add	$sp, $fp, 4			# $sp = $fp + space for 1 4-byte variable N
	lw	$fp, 0($sp)			# Pop: return $fp back from stack	
	nop
	add	$sp, $sp, 4
	lw	$ra, 0($sp)			# Pop: return $ra back from stack
	nop
	add	$sp, $sp, 4			
				
	jr	$ra				# returning to the caller
	nop

# End Of File
