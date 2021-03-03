motorcycles = []

motorcycles.append('wr250x')
motorcycles.append('r6')
motorcycles.append('cbr')
motorcycles.append('zx6r')
motorcycles.append('hypermotard')
motorcycles.append('gsxr')

print("\nMotorcycle List:")
print(motorcycles)

#popped_motorcycle = motorcycles.pop() # Pop removes the last item in the list while returning its value
									  # This allows the value to be used after removal for various uses
									  
# print("\nPopped Motorcycle: " + popped_motorcycle + ".")

print("\nPopped Motorcycle: " + motorcycles.pop() + ".") # removes the need for the extra variable

print("\nStill Currently In The List:")
print(motorcycles)

print("\nMy Favorite motorcycle was: " + motorcycles.pop(0) + ", but its sold to keep me out of trouble\n")
						# Pop can be used like del to pop items anywhere in the list but pop returns its value



print("Current List:")
print(motorcycles)

too_expensive = 'hypermotard'
motorcycles.remove(too_expensive) # remove(value) will remove the first instance of the value in parameters

print("\nA " + too_expensive.title() + " is too expensive to maintain, so we removed it from the list.")
print(motorcycles)
