#
# Assignment7.asm
# Troy Schultz
# Nov/23/2020
#
# MIPS program that prompts the user for the (x,y) coordinates of two points 
# in the real (Cartesian) plane, and then calculates and displays the distance
# between the points.
#
# - Prompt subroutine for coordinates using the simple linkage convention
# - Calculate the distance by using the Pythagorean Theorem
# - Square root subroutine follows the simple register-based linkage convention:
#
# Pass Prompt message in to subroutine using argument register $a0
# Pass Float arguments in to subroutine using $f12 and $f14
# Subroutine Returns values in $f0 only
# 
	.data
prmt_x:	.asciiz	"\nEnter an x coordinate: "
prmt_y:	.asciiz	"Enter a y coordinate: "
distan:	.asciiz	"\nThe distance between the two points = "
	.text
	.globl main

main:
	la	$a0, prmt_x		# Pass subroutine arg : $a0 <- Prompt x
	nop
	jal	get_pt			# Subcall: Get user entry : point x1
	nop				# Subcalls Return value stored in $f0
	mov.s	$f1, $f0		# $f1 <- $f0 = coordinate_x1 : (x1, )

	la	$a0, prmt_y		# Load subroutine arg : $a0 <- Prompt y
	nop				
	jal	get_pt			# Subcall: Get user entry point y1
	nop				# Subcalls Return value stored in $f0
	mov.s	$f2, $f0		# $f2 <- $f0 = coordinate_y1 : ( ,y1)
	
	la	$a0, prmt_x		# Load subroutine arg : $a0 <- Prompt x
	nop				
	jal	get_pt			# Subcall: Get user entry point x2
	nop				# Subcalls Return value in $f0
	mov.s	$f3, $f0		# $f3 <- $f0 = coordinate_x2 : (x2, )

	la	$a0, prmt_y		# Load subroutine arg : $a0 <- Prompt y
	nop				
	jal	get_pt			# Subcall: Get user entry point y2
	nop				# Subcalls Return value in $f0
	mov.s	$f4, $f0		# $f4 <- $f0 = coordinate_y2 : ( ,y2)
	
	sub.s	$f1, $f3, $f1		# $f1 = delta x = (x2 - x1) 
	sub.s	$f2, $f4, $f2		# $f2 = delta y = (y2 - y1)
	mul.s	$f1, $f1, $f1		# $f1 = (delta x)^2
	mul.s	$f2, $f2, $f2		# $f2 = (delta y)^2
	add.s	$f1, $f1, $f2		# $f1 = (delta x^2) + (delta y^2)
	
	mov.s	$f12, $f1		# Pass sub arg: $f12 <- $f1 =(x^2 + y^2)
	jal	sqrt			# Subcall: Get square root of arg $f12
	nop				# Subcalls Return value stored in $f0

	la	$a0, distan		# Load Distance Display Message
	li	$v0, 4			# System Code '4' : Print strings
	syscall				# Display: "The distance between pts = "
	
	li	$v0, 2			# System Code '2': Prints Floats
	mov.s	$f12, $f0		# $f12 <- $f0 : returned val from sqrt
	syscall				# Prints floats from arguement $f12	
	
	li	$v0, 10			# System Code '10' : Terminate program
	syscall				# Program Ends

get_pt:					# Load address of prompt from arg in $a0
	li	$v0, 4			# System Code '4' : Print a string
	syscall				# Prompt user : Enter a coordinate point
	li	$v0, 6			# System Code '6' to read in floats
	syscall				# User entered floats are stored in $f0
	jr	$ra			# Return to caller : return value = $f0
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
