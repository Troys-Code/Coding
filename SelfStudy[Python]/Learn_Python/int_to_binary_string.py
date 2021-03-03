def dec_to_binary(num):
	back_index = 31		# Last element in 32 bit binary <=> int
	list = [0] * 32		# Create list of size 32 init all 0
	half = num		# Half is result of division by 2 : init whole  
	while half !=  0:	# While we can still divide by 2
		list[back_index] = str(half & 1)	# Place 0 or 1 at back
		back_index -= 1				# Index of previous
		half = half >> 1			# Divide by 2
	return ''.join(str(elem) for elem in list).lstrip('0') # binary string

def main():
	number = 0
	while number >= 0:
		number = int(input("Enter An Integer To Converted To Binary: "))
		if number < 0:
			break
		print(dec_to_binary(number))
	
# Run Automatically if file is opened directly, if imported this file then it
# wont run main Because __name__ will not be main

if __name__ == "__main__":
	main() 
