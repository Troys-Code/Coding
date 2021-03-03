def xo(s):
	# Check to see if a string has the same amount of 'x's and 'o's. 
	# The method must return a boolean and be case insensitive. 
	# The string can contain any char.
	
	# 				Example
	#
	#		XO("ooxx") => true
	#		XO("xooxx") => false
	#		XO("ooxXm") => true
	#		XO("zpzpzpp") => true // when no 'x' and 'o' is present should return true
	#		XO("zzoo") => false
    
    s = s.upper()                           # Convert whole string to capitals characters 
    return s.count("X") == s.count("O")     # Compare character occurance count as bool 

def XO(s):
	s = s.upper()
	print(s)
	
	x_count = s.count('X')
	o_count = s.count('O')
	
	print("Number of X: {}, Number of O: {}".format(str(x_count), str(o_count)))
	
	return x_count == o_count
	
def main(args):
	# For xo(s) function
	inputstr = "XOoxxxxXXX"
	#print(xo(inputstr))
	print(XO(inputstr))
	#	#	#	#	#	#	#	#	#	#	#	#	#	#	#	#	#	#
	
	return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
