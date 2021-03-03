
import os

def main(args):
	numbers = []
	number_to_add = 0
	loop = True
	again = True
	
	os.system("clear")

	while loop == True:
		number_to_add = input("Enter A Number: ")			
		if int(number_to_add) == -1:
			loop = False
		else:
			numbers.append(number_to_add)
			
		os.system("clear")
		
		print(numbers)
		
	
	return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
