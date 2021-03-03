

#	Capitalize all lowercase
	.data
prompt:	.asciiz "Enter a string of less than 100 characters: "
input:	.space 100
newln:	.asciiz "\n"
	.text
	.globl	main

main:
	li	$t0, 0			# $t0 = Index used to traverse string
	li	$t2, ' '		# $t2 = space
	li	$t3, 'a'		# $t3 = a : Top of lowercase range
	li	$t4, 'z'		# $t4 = z : End of lowercase range

	li	$v0, 4			# 
	la	$a0, prompt		# Prompt user to enter a string 
	syscall				# 
	
	li	$v0, 8			#
	la	$a0, input		# Store user entered string 
	li	$a1, 100		# Max Length 100 char text = 100 bytes
	syscall				#

	li	$v0, 4			#
	la	$a0, newln		# Print a new line character
	syscall				#

while:
	lb	$t1, input($t0)		# $t1 = in_string[Index]
	nop
	beqz	$t1, exit		# If (char == NUL) {Exit loop}
	nop
	beq	$t1, $t2, continue	# If (current char == ' ') {continue}
	nop
	bge	$t1, $t3, lowrange	# If (current char >= 'a') {j low range}
	nop
continue:
	addi	$t0, $t0, 1		# Increment index + 1
	j	while			# Return to beggining of the loop
	nop
lowrange:
	ble	$t1, $t4, lowercase	# If (current char <= 'z' {is a-z} 
	nop
	j	continue		# If (not a-z) {continue loop}
lowercase:				
	addiu	$t1, -0x20		# Conv current char in $t1 to uppercase
	sb	$t1, input($t0)		# Store uppercase back in the string
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
