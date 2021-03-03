def d_order(num):
    num_str = str(num)
    
    
    number_list = []
    
    for x in num_str:
        number_list.append(int(x))
    
    number_list.sort(reverse = True)
    
    new_int = "".join(map(str, number_list))
    return(int(new_int))
    
	
	
	
def main(args):
	print(d_order(123))
	return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
