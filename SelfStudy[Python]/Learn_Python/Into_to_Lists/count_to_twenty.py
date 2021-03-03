import time

time0 = time.time()							# Saves Current Time
print(f"\nStart Time: {time0}" )

numbers = [value for value in range(1,21)]	# List Comprehensive Approach
print(numbers)

print(f"\n\nEnd Time: {time.time() - time0}") # Prints Time Difference Between Start And Stop
						



'''
numbers = []

for value in range(1,21):					# Conventional Approach
	numbers.append(value)

print(numbers)
'''
