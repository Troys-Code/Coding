name = "troy schultz"
print(name.title()) # Prints Each First Letter In The String As Capitals

print(name.upper()) # Prints With All Characters Lower Case
print(name.lower()) # Prints With All Characters Upper Case

# .lower() and .upper() are useful for user inputs to validate user input with less variations 
# Troy tRoy trOy troY are all the same using these functions

# This makes it easy to not worry about the users capitalizations, so you would convert user inputs
# before storing them. Then when you want to display the information, you'll use whatever capitalization makes the most sense
# for each string
