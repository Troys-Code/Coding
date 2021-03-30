#
# Assignment6_E2_and_E3.asm
# Troy Schultz
# Nov/10/2020
#				Exercise #2 and #3
# Mips Program Prints the string
# Converts string to have capitalized the first character letter of each word
# Then prints the string again. 
# This conversion is done by subtracting 0x20 (decimal 32)
#
# Variable Usage Below:
# Using $t0 as the index
# Using $t1 as the current character in the string
# Using $t2 as the previous character in the string
#	
.data	
string:	.asciiz "in a hole in the ground there lived a hobbit"
newline: .asciiz "\n"

	.text
	.globl main

main:
	li	$v0, 4			 
	la	$a0, string			# Print string
	syscall				 

	li	$t0, 0				# Index
	li	$t1, ' '			# Previous = space
while:
	nop
	lb	$t2, string($t0)		# Current = string[Index] 
	nop
	beqz	$t2, End			# if ( Current == NULL ) { End loop }
	bne	$t1, ' ', Next			# if ( Previous != space ) { Next }			
	bge	$t2, 'a', a_			# If ('a'- ?) { check if 'a' - 'z' }
Next:
	nop
	move	$t1, $t2			# Previous = Next
	addi	$t0, 1				# Index++
	j	while				# Continue looping
a_:	
	nop			
	ble	$t2, 'z', a_z			# if (Next <= 'z') {Capitalize} 
	j	Next				# else (not a-z) {continue looping}
a_z:	
	nop					# Is a-z
	addiu	$t2, -0x20			# uppercase
	sb	$t2, string($t0)		# string[i] = 'uppercase'
	nop
	j	Next				# Continue loop
End:
	nop
	li	$v0, 4
	la	$a0, newline			# Print a new line character
	syscall				

	li	$v0, 4			
	la	$a0, string			# Print New String
	syscall	

	li	$v0, 10				# Exit Program
	syscall			
	
## End of file
