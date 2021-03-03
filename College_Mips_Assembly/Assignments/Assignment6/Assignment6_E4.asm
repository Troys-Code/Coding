#
# Assignment6_E4.asm
# Troy Schultz
# Nov/10/2020
#				Exercise #4
# Mips Program Prompt the user for a string
# Then parse the string exchanging the case of each character.
# Then prints the string again. 
# Change all upper-case letters to lower case and all lower-case letters to
# upper case.
# Data comprises only lower-and upper-case alphabetic characters and spaces, 
# with no punctuation, however if you enter non alphabetic it will be ignored
#
# Variable Usage Below:
# Using $t0 as the index
# Using $t1 as current character
# Using $t2 as a space to compare against
# Using $t3 as a: Top of lowercase range to be converted to uppercase
# Using $t4 as z: End of lowercase range to be converted to uppercase
# Using $t5 as A: Top of uppercase range to be converted to lowercase
# Using $t6 as Z: End of uppercase range to be converted to lowercase

	.data
prompt:	.asciiz	"Enter A String Of 100 Characters Or Less: "
input:	.space	100
newln:	.asciiz	"\n"
	.text
	.globl	main
	
main:
	li	$t0, 0			# $t0 = index
	li	$t2, ' '		# $t2 = space
	li	$t3, 'a'		# $t3 = a : Top of lowercase range
	li	$t4, 'z'		# $t4 = z : End of lowercase range
	li	$t5, 'A'		# $t5 = A : Top of uppercase range
	li	$t6, 'Z'		# $t6 = Z : End of uppercase range

	li	$v0, 4			# 
	la	$a0, prompt		# Prompt user to enter a string 
	syscall				# 
	
	li	$v0, 8			#
	la	$a0, input		# Store user entered string 
	li	$a1, 100			# Max Length 100 char text = 100 bytes
	syscall				#
	
	li	$v0, 4			#
	la	$a0, newln		# Print a new line character
	syscall				#

	li	$v0, 4			#
	la	$a0, input		# Print the Users string
	syscall				#
	
while:
	lb	$t1, input($t0)		# $t1 = currentCharacter[Index]
	nop
	beqz	$t1, exit		# If (current char == NULL) {Exit loop}
	nop
	beq	$t1, $t2, continue	# If (current char == ' ') {continue}
	nop
	bge	$t1, $t3, lowrange	# If (current char >= 'a') {j low range}
	nop
	bge	$t1, $t5, highrange	# If (current char >= 'A') {j highrange}
	nop
continue:
	addi	$t0, $t0, 1		# Increment index + 1
	j	while			# Return to beggining of the loop
	nop
lowrange:
	ble	$t1, $t4, lowercase	# If (current char <= 'z' {is a-z} 
	nop
	j	continue		# If (not a-z) {continue loop}
	nop
highrange:
	ble	$t1, $t6, uppercase	# If (current char <= 'Z') {its A-Z}
	nop
	j	continue		# If (not A-Z) {continue loop}
	nop
lowercase:				
	addiu	$t1, -0x20		# Conv current char in $t1 to uppercase
	sb	$t1, input($t0)		# Store uppercase back in the string
	nop
	j	continue		# Continue loop
	nop
uppercase:
	addiu	$t1, 0x20		# Conv current char in $t1 to lowercase
	sb	$t1, input($t0)		# Store lowercase char back in string
	nop
	j	continue		# Continue loop
	nop
exit:
	
	li	$v0, 4			#
	la	$a0, newln		# Print a new line character
	syscall				#

	li	$v0, 4			#
	la	$a0, input		# Print the Users string
	syscall				#

	li	$v0, 10			# Code "10" to end program
	syscall			
	
## End of file
