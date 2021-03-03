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
# Using $t1 as a space to compare against
# Using $t2 as the previous character in the string
# Using $t3 as the current character in the string
# Using $t4 as 'a': Top Of Range to be converted to lowercase
# Using $t5 as 'z': End of Range to be converted to lowercase
#	
	.data
string:	.asciiz	"in   a hole   in the ground there lived a hobbit"
newln:	.asciiz	"\n"
	.text
	.globl	main
	
main:
	li	$v0, 4			# 
	la	$a0, string		# Print the original string
	syscall				# 

	li	$t0, 0			# $t0 = index
	li	$t1, ' '		# $t1 = space
	li	$t2, ' '		# $t2 = prev char : initialized as space
	li	$t4, 'a'		# $t4 = a: Top Of interested Range 
	li	$t5, 'z'		# $t5 = z: End of interested Range
	
while:
	lb	$t3, string($t0)	# Current char : $t3 = string[index] 
	nop
	beqz	$t3, exit		# If (current char == NULL) {Exit loop}
	nop
	bne	$t2, $t1, continue	# If (prev char != ' ') {continue loop}  
	nop
	bge	$t3, $t4, topRange	# If (currentchar >= 'a') {j topRange}
	nop
continue:
	move	$t2, $t3		# $t2 <- $t3 : prev char = current char
	addi	$t0, 1			# Increment offset $t0 + 1
	j	while			# Return to the top of while loop
	nop
topRange:				# Current char is Greater than 'a'
	ble	$t3, $t5, inRange	# If current char <= 'z' {in range a-z}
	nop
	j	continue		# If (not a-z) {continue loop}
	nop
inRange:				# Since its in Range a-z
	addiu	$t3, -0x20		# Conv currentchar in $t3 to uppercase
	sb	$t3, string($t0)	# Store uppercase char in string
	nop
	j	continue		# Continue loop
	nop
exit:

	li	$v0, 4			#
	la	$a0, newln		# Print a new line character
	syscall				#

	li	$v0, 4			#
	la	$a0, string		# Print converted to lowercase string
	syscall				#

	li	$v0, 10			# Code "10" to end program
	syscall			
	
## End of file
