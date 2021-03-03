def list_unique(a, b): 
	# Returns a list of only the unique items out of the two list
    result = []
    for element in a:
        if not element in b:
            result.append(element)
    for element in b:
        if not element in a and not element in result:
            result.append(element)
    return result
	
def array_diff(a, b):
	# Returns a list of items in list a not found in list b
    result = []
    for element in a:
        if not element in b:
            result.append(element)
    return result


def main(args):
	# Your goal in this kata is to implement a difference function, 
	# which subtracts one list from another and returns the result.
	# It should remove all values from list a, which are present in list b.
	# array_diff([1,2],[1]) == [2]
	# If a value is present in b, all of its occurrences must be removed from the other:
	# array_diff([1,2,2,2,3],[2]) == [1,3]
	
	list_a = [0, 3]
	list_b = [1, 1, 3]
	
	list_c = array_diff(list_a, list_b)
	
	print(list_c)
	
	
	return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
