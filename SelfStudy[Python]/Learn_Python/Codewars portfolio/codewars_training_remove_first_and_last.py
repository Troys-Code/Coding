# Your goal is to create a function that removes the first and last characters of a string. 
# You're given one parameter, the original string. 
# You don't have to worry with strings with less than two characters.

def remove_char(s):
	return s[1:-1]

def main(args):
	mystr = "Hello World"
	
	print(remove_char(mystr))
	return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
