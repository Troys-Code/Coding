food = ["tacos", "burritos", "sushi", "ramen"]  # Create a [LIST] of Food

original = food.copy()                          # Creates a copy of the original [LIST] called original

print("Original:")
print(original)                                 # Print Entire List

print("\nCapitalize First Element in List:")
food[0] = food[0].upper()                       # Change First Element in List to uppercase
print(food)                                     # Print Entire List with changed first element

print("\nTitle Format Last element in the List:")
food[-1] = food[-1].title()                     # Change Last Element in List to Title format (Capitalize first char)
print(food)                                     # Print Entire List with changed last element

print('\nAdded Boba to the list of Food')
food.append('milk tea')                             # Adds Boba to the food list for fun
print(food)

search_item = 'milk tea'
if search_item in food:
    print("\nFound '" + search_item.title() + "' in the list")

print('\nBackup of Original Food List')
print(original)

# ******************************************************************************************************************** #

print("\n\n\n\nTime For A List Of Numbers:")
numbers = list(range(10))
print(numbers)

while True:
    search_item = int(input("\nEnter A number to search for in the list?: "))
    if search_item in numbers:
        print("\n'" + str(search_item) + "' Was in the list")
    else:
        print(search_item in numbers)
        print("\n'" + str(search_item) + "' Was NOT in the list")
        break

random_nums = [10, 5, 11, 3, 2, 12, 6, 15, 20, 11, 42, -6]
highest = lowest = random_nums[0]

print("\n\nRandom Numbers List")
print(random_nums)

for number in random_nums:
    if number > highest:
        highest = number
    if number < lowest:
        lowest = number
print(f"Highest number is {highest}")
print(f"Lowest number is {lowest}")