desired_locations = ['japan', 'china', 'singapore', 'korea', 'hawaii']  # Think of 5 places you would like to visit

print(f'\nOriginal List: {desired_locations}\n')						# Print list of locations

print(f'Sorted List: {sorted(desired_locations)}\n')					# Print list in alphabetic order

print(f'Unchanged Original List: {desired_locations}\n')				# Print unmodified original list

desired_locations.reverse()	# Permanantly Reversed Original List

print(f'Permanantly Reversed List: {desired_locations}\n')				# Display List After Being Altered

desired_locations.reverse()	# Permanantly Reversed Original List Back							

print(f'Reversed List Back: {desired_locations}\n')						# Reversed list back to original 

desired_locations.sort()	# Permanantly Sorted Original List

print(f'Permanantly Sorted List: {desired_locations}\n')				# Sorted / Altered Original List


desired_locations.sort(reverse = True) # Permanantly Sorted Original List In Reverse Alphabetic Order

print(f'Permanantly Sorted Original List in Reverse Alphabetic Order: {desired_locations}\n')


