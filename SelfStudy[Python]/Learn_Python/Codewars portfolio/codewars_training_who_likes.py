def likes(names):
	num_names = len(names)
	
	if num_names == 0:
		return "no one likes this"
	if num_names == 1:
		return names[0] + " likes this"
	if num_names == 2:
		return names[0] + " and " + names[1] + " like this"
	if num_names == 3:
		return names[0] + ", " + names[1] + " and " + names[2] + " like this"
	if num_names > 3:
		return names[0] + ", " + names[1] + " and "  + str(num_names-2) + " others like this"

def main(args):
	#liked_names = ["sam"]
	#liked_names = ["sam", "tom"]
	#liked_names = ["sam", "tom", "david"]
	#liked_names = ["sam", "tom", "david", "andy"]
	liked_names = ["sam", "tom", "david", "andy", "ina"]
	print(likes(liked_names))
	return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
