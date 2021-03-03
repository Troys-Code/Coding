'''
cubes = [value ** 3 for value in range(1,11)] # List Comprehension 

for cubed in cubes:
	print(cubed)

'''

cubes = []
for index in range(1,11):
	cubes.append(index ** 3)
	print(cubes[index - 1])



