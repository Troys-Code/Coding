#
# Assignment7.asm
# Troy Schultz
# Nov/23/2020
#
# MIPS program that prompts the user for the (x,y) coordinates of two points 
# in the real (Cartesian) plane, and then calculates and displays the distance
# between the points.
#
# - Prompt for coordinates using a subroutine following the simple linkage
# convention to avoid duplicate code. (Code reausability)
#
# - Calculate the distance by using the Pythagorean Theorem:
#
# - Square root subroutine follows the simple register-based linkage convention:
# Arguements in $f12 and $f14
# Return value in $f0 only return with 1
# pass message in $a0
# 
	.data
prmt_x:	.asciiz	"\nEnter an x coordinate: "
prmt_y:	.asciiz	"\nEnter a y coordinate: "
distan:	.asciiz	"\nThe distance between the two points = "
	.text
	.globl main

main:
	jal	get_xy			# Subcall: Get user entered coordinate1
	nop				# Currently : ($f1,$f0) = (x,y)
	mov.s	$f4, $f0		# $f4 = coordinate1_x
	mov.s	$f5, $f1		# $f5 = coordinate1_y

	jal	get_xy			# Subcall: Get user entered coordinate2
	nop				# Currently : ($f1,$f0) = (x,y)
	mov.s	$f6, $f0		# $f6 = coordinate2_x
	mov.s	$f7, $f1		# $f7 = coordinate2_y
	
	sub.s	$f4, $f6, $f4		# $f4 = delta x = (x2 - x1) 
	sub.s	$f5, $f7, $f5		# $f5 = delta y = (y2 - y1)
	mul.s	$f4, $f4, $f4		# $f4 = (delta x)^2
	mul.s	$f5, $f5, $f5		# $f5 = (delta y)^2
	add.s	$f5, $f4, $f5		# $f5 = (delta x^2) + (delta y^2)
	
	mov.s	$f12, $f5		# Pass arguement: $f12<-$f5 =(x^2 + y^2)
	jal	sqrt			# Subcall: Get square root of arg $f12
	nop

	la	$a0, distan		# Load Distance Display Message
	li	$v0, 4			# System Code '4' : Print strings
	syscall				# Display: "The distance between pts = "
	
	li	$v0, 2			# System Code '2': Prints Floats
	mov.s	$f12, $f0		# $f12 <- $f0 : returned val from sqrt
	syscall				# Prints floats from arguement $f12	
	
	li	$v0, 10			# System Code '10' : Terminate program
	syscall				# Program Ends

get_xy:
	la	$a0, prmt_x		# Load addr of prompt for x coordinate
	li	$v0, 4			# System Code '4' : Print a string
	syscall				# Prompt user to enter an X-Coordinate

	li	$v0, 6			# System Code '6' to read in floats
	syscall				# User entered floats are stored in $f0
	mov.s	$f1, $f0		# Move entry into its own register $f1
	
	la	$a0, prmt_y		# Load addr of prompt for y coordinate
	li	$v0, 4			# System Code '4' : Print a string
	syscall				# Prompt user to enter a Y-Coordinate

	li	$v0, 6			# System Code '6' to read in floats
	syscall				# User entered floats are stored in $f0
	
	jr	$ra			# Return to caller : ($f1,$f0) = (x,y)
	nop				# Delay slot

sqrt:
	mov.s	$f0, $f12		# Move sub arg stored in $f12 to $f0
	li.s	$f1, 1.0
	li.s	$f2, 1.0
	li.s	$f3, 2.0		# Used for Division by 2.0
	li.s	$f4, 1.0e-5		# Min : approxation accuracy 10^-5 
loop:
	div.s	$f5, $f0, $f1		# x = (n / x)
	add.s	$f5, $f5, $f1		# x = x + (n / x)
	div.s	$f1, $f5, $f3		# x = (x + n / x) / 2
	mul.s	$f5, $f1, $f1		# $f5 = x^2
	div.s	$f5, $f5, $f0		# $f5 = n / (x^2)
	sub.s	$f5, $f5, $f2		# $f5 = ( n / (x^2) ) - 1
	abs.s	$f5, $f5		# $f5 = | ( n  / (x^2) ) - n |

	c.lt.s	$f5, $f4		# Condition | n / ((x^2) - n) | < Min
	bc1t	exitLoop		# If condition true exitLoop
	nop				# Delay Slot
	j	loop			# Continue the loop
	nop				# Delay Slot
exitLoop:
	mov.s	$f0, $f1		# Move Square root result into $f0 
	jr	$ra			# Return to caller
	nop				# Delay slot

## end of file

