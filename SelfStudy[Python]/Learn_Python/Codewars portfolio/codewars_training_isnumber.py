def isDigit(in_string):
	number = in_string.replace('.','').strip()
	return number.isdigit() or number.startswith('-')

def main(args):
	
	number = " -9.0 "
	print(isDigit(number))
	
	return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
