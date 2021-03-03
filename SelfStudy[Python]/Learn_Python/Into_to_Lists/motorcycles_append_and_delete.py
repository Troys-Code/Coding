motorcycles = []

motorcycles.append('wr250x')
motorcycles.append('r6')
motorcycles.append('cbr')
motorcycles.append('zx6r')
motorcycles.append('hypermotard')
motorcycles.append('gsxr')

print("\n")
print(motorcycles)

print("\n")
motorcycles.insert(0, 'Drz400sm') # Inserts New Item At Element[0] The Beggining Of The List
								  # The Insert Method Opens A Space For The Element At The Desired Index To Be Added
print("added " + motorcycles[0] + " to the beggining of the list\n")

print("\n")
print(motorcycles)


del motorcycles[6]

print("\n Deleted Gsxr")
print(motorcycles)
