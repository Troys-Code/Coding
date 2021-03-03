#Consider an array/list of sheep where some sheep may be missing from their place. 
#We need a function that counts the number of sheep present in the array (true means present).

#For example,

#[True,  True,  True,  False,
#  True,  True,  True,  True ,
#  True,  False, True,  False,
#  True,  False, False, True ,
#  True,  True,  True,  True ,
#  False, False, True,  True]
 
 
def count_sheeps(sheep):
	count = 0
	for each in sheep:
		if each:
			count += 1
	return count
			
def main(args):
	sheep = [
	True,  True,  True,  False,
	True,  True,  True,  True ,
	True,  False, True,  False,
	True,  False, False, True ,
	True,  True,  True,  True ,
	False, False, True,  True
	]
	
	print(count_sheeps(sheep))
	return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
