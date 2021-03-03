#
# Assignment6_E1.asm
# Troy Schultz
# Nov/10/2020
#				Exercise #1
# Mips Program Prints the string, Converts string to all lower case characters
# Then prints the string again. 
# This conversion is done by adding 0x20 to each character in the string.
# Data comprises only uppercase alphabetical chars, no spaces or punctuation. 
#
# Using $t0 as the index
# Using $t1 as the current character in the string
# Using $t2 as A: Top Of Range to be converted to lowercase
# Using $t3 as Z: End of Range to be converted to lowercase
#	
	.data
string:	.asciiz	"TROYBOY"
newln:	.asciiz	"\n"
	.text
	.globl	main
	
main:
	li	$v0, 4			#
	la	$a0, string		# Print the original string
	syscall				#

	li	$t0, 0			# $t0 = index
	li	$t2, 'A'		# $t2 = A: Top Of interested Range 
	li	$t3, 'Z'		# $t3 = Z: End of interested Range
	
while:
	lb	$t1, string($t0)	# $t1 = currentChar[Index]
	nop
	beqz	$t1, exit		# If (currentChar == NULL){Exit loop}
	nop
	bge	$t1, $t2, intopRange	# If (currentChar >= 'A'){its A-?}
	nop
continue:
	addi	$t0, 1			# Increment offset $t0 + 1
	j	while			# Return to the top of while loop
	nop
intopRange:				# Current char is Greater than 'A'
	ble	$t1, $t3, uppercase	# If (currentChar <= 'Z') {uppercase}
	nop
	j	continue		# If (not uppercase) {continue}
	nop
uppercase:
	addiu	$t1, 0x20		# Convert currentchar to lowercase
	sb	$t1, string($t0)	# Store lowercase char back into string
	nop
	j	continue		# Continue to increment index 
	nop
exit:

	li	$v0, 4			#
	la	$a0, newln		# Print a new line character
	syscall				#

	li	$v0, 4			#
	la	$a0, string		# Print the new lowercase string
	syscall				#

	li	$v0, 10			# Code "10" to end program
	syscall			
	
## End of file
