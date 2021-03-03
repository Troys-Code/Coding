boba_order = ['milk tea', 'fruit tea', 'slush', 'yakult']


order = boba_order[:] # pass by value (iterate and coppies the list )

'''
order = boba_order  # pass by refference (what you change in one affects the other)
'''

print(f'\nOriginal Boba Order: {boba_order}')
print(f'Coppied Boba Order: {order}')

print("\n\nChanged Original Boba Order element 0 to poop\n")
boba_order[0] = 'poop'

print(f'\nOriginal Boba Order: {boba_order}')
print(f'Coppied Boba Order: {order}')
