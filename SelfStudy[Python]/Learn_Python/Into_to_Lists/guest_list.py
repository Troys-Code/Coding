invite_list = ['ina', 'deborah', 'sister', 'ina_mom', 'ina_dad', 'chris_and_gatcha']

print("\nInvite List:")
print(invite_list)

print("\nPlease Come to my party " + invite_list.pop(0))
print("\nPlease Come to my party " + invite_list.pop(0))
print("\nPlease Come to my party " + invite_list.pop(0))
print("\nPlease Come to my party " + invite_list.pop(0))
print("\nPlease Come to my party " + invite_list.pop(0))

print("Guest Who Cant Make it are: " + invite_list.pop())

print("\nInstead we invite:")
invite_list.append('dre')
invite_list.insert(0, 'jolie')
print(invite_list)

print("\nPlease Come to my party " + invite_list.pop(0))
print("\nPlease Come to my party " + invite_list.pop(0))
