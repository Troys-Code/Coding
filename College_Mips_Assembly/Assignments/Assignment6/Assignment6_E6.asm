#
# Assignment6_E6.asm
# Troy Schultz
# Nov/10/2020
#				Exercise #6
# Mips Program Prompt the user for a series of 10 integers
# Hold them in an integer array
# Print the array with tabs between elements and a new line after last element
# Reverse the elements stored in the array (Modifies Original Array)
# Print the integers again with tabs in the resulting reversed order.
# (You will have to prompt for these on seperate input lines
#
# Variable Usage Below:
# Using $s0 as the last element of the array : It will not change from length 9
# Using $t0 as the index
# Using $t1 as base of the array
# Using $t2 as an iterator (index * 4) then ((index * 4) + base array address)
# Using $t3 as a temporary held value of current element in array
#
	.data
nums:	.word	0:10		# Creates a 10 element array initialized all 0
maxlen:	.word	9
msg:	.asciiz	"I require 10 integers entered one at a time.\n"
prompt:	.asciiz	"\nPlease enter an integer: "
newl:	.asciiz	"\n"
tab:	.asciiz	"\t"

	.text
	.globl	main
	
main:
	li	$v0, 4			# Print string to console to
	la	$a0, msg		# Inform user of input requirements
	syscall			

	li	$t0, 0			# Initialize index to 0
	lw	$s0, maxlen		# Position of last element of the array
	nop
	la	$t1, nums		# $t1 = Base of the Array = nums[0]
	nop
input:
	bgt	$t0, $s0, inputsDone	# If(index > last element){inputs done}
	nop

	li	$v0, 4			# Code '4' prints a string
	la	$a0, prompt		#
	syscall				# Prints prompt: "Enter an integer"
	
	li	$v0, 5			# Code '5' reads in an integer
	syscall				# from console, stores in $v0

	sll	$t2, $t0, 2		# $t2 = (index * 4) : offset (for words)
	addu	$t2, $t2, $t1		# $t2 = (offset) + Base address of array
	sw	$v0, 0($t2)		# Value entered -> (base array + offset)
	addiu	$t0, 1			# Incremenet index + 1 (delay slot)

	j	input			# Loop to continue user input
	nop
inputsDone:				

	jal PrintArray			# PrintArray Function (code reuse)
	nop
					
	li	$t0, 0			# Reinitialize Index = 0 
pushArray:				# Reverse array: "Push" on to the stack
	bgt	$t0, $s0, endPush	# if(index > last element){end Push}
	nop
	
	sll	$t2, $t0, 2		# $t2 = index * 4
	addu	$t2, $t2, $t1		# $t2 = (index * 4) + Array Base address
	lw	$t3, 0($t2)		# $t3 = current element in array	
	
	addi	$sp, $sp, -4		# Push : add new opening onto the stack
	sw	$t3, 0($sp)		# Store current element onto the stack
	addiu	$t0, $t0, 1		# Increment index + 1
	
	j	pushArray
	nop
endPush:

	li	$t0, 0			# Reinitialize Index = 0
popArray:				# Pop : to reload array in reverse order
	bgt	$t0, $s0, endPop	# if(index > last element){end pop}
	nop
	
	lw	$t3, 0($sp)		# $t3 <- last element on the stack
	addiu	$sp, $sp, 4		# adjust $sp in delay : next on stack
	
	sll	$t2, $t0, 2		# $t2 = index * 4
	addu	$t2, $t2, $t1		# $t2 = (index * 4) + Array Base address

	sw	$t3, 0($t2)		# item on stack -> array at index
	addiu	$t0, $t0, 1		# increment index
	
	j	popArray		# Loop Pop until all elements are loaded
	nop
endPop:
	
	jal PrintArray			# Print Array Function (Reversed Array)
	nop

	li	$v0, 10			# End Program
	syscall				

# FUNCTION TO PRINT AN ARRAY OF INTS (To avoid code duplication)

PrintArray:				
	li	$t0, 0			# Initialize : index = 0	
	move	$t2, $t0		# Iterator offset <- (index = 0)
printLoop:
	bgt	$t0, $s0, endPrint	# if(index > last element){end print}
	nop
	
	lw	$a0, nums($t2)		# Register $a0 <- (arr base + offset)
	nop
	li	$v0, 1			# Code '1' to print integer
	syscall				# Prints integer at nums[offset]
	
	li	$v0, 4			# Code '4' to print a string
	la	$a0, tab		# Loads a "\t" in to $a0
	syscall				# Prints a tab between each character
	
	addiu	$t2, $t2, 4		# Incremenet offset + 4 : to next word
	addiu	$t0, 1			# increment index + 1

	j	printLoop
	nop
endPrint:
	li	$v0, 4			# Code '4' to print a string
	la	$a0, newl		# Loads a "\n" in to $a0
	syscall
	
	jr	$ra			# Return to caller
	nop

## End of file
