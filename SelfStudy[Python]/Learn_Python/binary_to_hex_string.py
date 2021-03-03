conversion = {
"0000":"0",
"0001":"1",
"0010":"2",
"0011":"3",
"0100":"4",
"0101":"5",
"0110":"6",
"0111":"7",
"1000":"8",
"1001":"9",
"1010":"A",
"1011":"B",
"1100":"C",
"1101":"D",
"1110":"E",
"1111":"F"
}

def binary_to_hex(binary_string):
	fourbits = []
	hex = ['0x']

	# We split the binary string into 4 bit chunks
	while binary_string:
		fourbits.append(binary_string[:4])
		binary_string = binary_string[4:]
	
	# We then convert those chunks and store them in our hex string	
	for each_bit_pattern in fourbits:
		hex.append(conversion[each_bit_pattern])
	return ''.join(str(elem) for elem in hex)


def main():
	binary = input("Enter Binary To Convert To Hex: ")
	print(binary_to_hex(binary))

if __name__ == "__main__":
	main()
