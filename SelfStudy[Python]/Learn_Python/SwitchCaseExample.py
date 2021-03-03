def north(miles): return "North " + str(miles) + " Miles"
def east(miles): return "East " + str(miles) + " Miles"
def south(miles): return "South " + str(miles) + " Miles"
def west(miles): return "West " + str(miles) + " Miles"

# map the inputs to the function blocks
switch_case = {
        1: north,
        2: east,
        3: south,
        4: west
    }

# Driver program
if __name__ == "__main__":
    arguement = 1

# One way to do it
    funct = switch_case.get(arguement)

    print(funct(9000))

# Another Way         [case option] (Parameters, , , , )
    print(switch_case[arguement]("Like Hella"))
    print(switch_case[arguement + 1](5))
    print(switch_case[arguement + 2](10))
    print(switch_case[arguement + 3](15))