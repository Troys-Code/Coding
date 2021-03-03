import time

time0 = time.time()

numbers = []

for value in range(1, 1000001):
	numbers.append(value)
	print(numbers[value - 1])

'''

numbers = [value for value in range(1,1000001)]

for value in range(1,1000001):
	print(numbers[value - 1])

'''

print(f"Execution Time: {time.time() - time0}")
