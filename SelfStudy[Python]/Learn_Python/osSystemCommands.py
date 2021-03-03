import os																# Import os to use system commands os.system()

def main(args):
	os.system("clear")
	print('CURRENT USER IS: ', os.getlogin())
	
	os.chdir("..")														# Changes current working directory like cd in linux
	print('Current Working Directory Is: ', os.getcwd(), '\n')					# Returns string representing working directory
	os.system("ls")
	
	#os.mkdir('Folder123')
	os.system("ls")
	
	#os.rmdir('Folder123')
	os.system("ls")
	
	#print("Hello World!")
	return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
