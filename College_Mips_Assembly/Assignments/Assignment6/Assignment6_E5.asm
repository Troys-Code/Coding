#
# Assignment6_E5.asm
# Troy Schultz
# Nov/10/2020
#				Exercise #5
# Mips Program Prompt the user for a series of 10 integers
# Holds them in an integer array
# After entries complete passes through array finding largest and smallest
# Prints the largest and smallest entries
# (You will have to prompt for these on seperate input lines
#
# Variable Usage Below:
# Using $t0 as the index
# Using $t1 as the index of the last element in the array
# Using $t2 as base of the array
# Using $t3 as an iterator (index * 4) then (index * 4) + base array address
# Using $t4 as current element when traversing array for largest and smallest
# Using $t5 as smallest value in the array
# Using $t6 as largest value in the array

	.data
nums:	.word	0:10		# Create a 10 element array initialized all 0
maxlen:	.word	9
msg:	.asciiz	"I require 10 integers entered one at a time.\n"
prompt:	.asciiz	"\nPlease enter an integer: "
Dsmall:	.asciiz	"\nSmallest: "
Dlarge:	.asciiz	"\nLargest: "

	.text
	.globl	main
	
main:
	li	$v0, 4			# Print string to console to
	la	$a0, msg		# Inform user of input requirements
	syscall			

	li	$t0, 0			# Initialize index to 0
	lw	$t1, maxlen		# Position of last element of the array
	nop
	la	$t2, nums		# $t2 = nums[0]
	nop
input:
	bgt	$t0, $t1, endInput	# if(index > last element){end of input}
	nop

	li	$v0, 4			# Code '4' prints string
	la	$a0, prompt		#
	syscall				# Prints prompt: "Enter an integer"
	
	li	$v0, 5			# Code '5' reads in an integer
	syscall				# from console, stores in $v0

	sll	$t3, $t0, 2		# $t3 = (index * 4) : offset
	addu	$t3, $t3, $t2		# $t3 = (index * 4) + Base addr of array
	sw	$v0, 0($t3)		# Store val entered -> (base + offset)
	nop
	addiu	$t0, 1			# incremenet index + 1

	j	input
	nop
endInput:

	lw	$t5, nums($zero)	# $t5 = lowest = first element
	li	$t0, 1			# $t0 = index = next element in array
	lw	$t6, nums($zero)	# $t6 = highest = first element
	nop	
FindExtremes:			
	bgt	$t0, $t1, endExtremes	# If (index > maxlen) {endExtremes loop}
	nop

	sll	$t3, $t0, 2		# $t3 = (index * 4) : offset
	addu	$t3, $t3, $t2		# $t3 = (offset) + base address of array
	lw	$t4, 0($t3)		# $t4 = current element
	nop

	blt	$t4, $t5, newLowest	# If (current < lowest) {a new lowest}
	nop

checkHighest:
	bgt	$t4, $t6, newHighest # If (current > highest) {a new highest}
	nop

continue:
	addiu	$t0, $t0, 1		# index = index + 1
	j	FindExtremes
	nop
endExtremes:

	li	$v0, 4			# Code '4' to print string to console
	la	$a0, Dsmall		# 
	syscall				# Prints "Smallest: "
	
	li	$v0, 1			# Code '1' to print an integer
	move	$a0, $t5		# $a0 <- $t5 
	syscall				# Prints smallest integer value
	
	li	$v0, 4			# Code '4' print a string to console
	la	$a0, Dlarge		# Prints "Largest: "
	syscall				
	
	li	$v0, 1			# Code '1' to print an integer
	move	$a0, $t6		# $a0 <- $t6 
	syscall				# Prints Largest integer value

	li	$v0, 10			# End Program
	syscall				

newLowest:
	move	$t5, $t4		# New saved lowest <- current element
	j	checkHighest		# Check if there is a new highest
	nop

newHighest:
	move	$t6, $t4		# New saved highest <- current element
	j	continue		# Continue the loop
	nop

## End of file
