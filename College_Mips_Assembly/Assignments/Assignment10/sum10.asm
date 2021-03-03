	.data
a:	.word 23, 2, 45, 67, 89, 12, 100, 0, 120, 6
sum:	.word 0
	.text
	.globl	main
main:	
	la	$t0, a
	li	$t1, 0		# Iterator for pointer access	
	li	$t2, 9		# end condition of loop, last element in array

while:
	bgt	$t1, $t2, exit_loop	
	sll	$t3, $t1, 2		# I = $t3 = (4 * I) each word is 4bytes
	addu	$t3, $t3, $t0		# a[i] $t0 is the address of the array
	
	lw	$t6, 0($t3)		# $t6 = a[i] 
	nop
	addu	$s7, $s7, $t6		# sum = sum + a[i]
	addi	$t1, $t1, 1		# increment $t1++
	j	while
	nop
exit_loop:
	
	sw	$s7, sum
	nop

	lw	$s5, sum
	nop
	li	$v0, 1
	move	$a0, $s5
	syscall

