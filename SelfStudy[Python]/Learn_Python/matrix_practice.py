import random
import copy

def is_land(value):                 # If the value is even it has to be land
    return not value & 0x01  # x & y : Does "bitwise and" of x and y, Here value and 0x01 compare LSB against 0x01


def update_bridge_pos(island_map, map_dimensions, bridge1_xy, bridge2_xy):
    bridge_count = 2
    row = 0
    col = 0

    # CHECK LHS EDGE (FROM TOP LEFT DOWN) FOR LAND
    while row < map_dimensions[0]:              # 0 to (row-1):
        if is_land(island_map[row][col]):       # CHECK LHS EDGE for a bridge
            if bridge_count == 2:               # if we have 2 unset bridges
                bridge1_xy[0] = row             # set bridge1
                bridge1_xy[1] = col
                bridge_count -= 1               # decrement bridge count
            else:
                bridge2_xy[0] = row             # Otherwise set bridge2
                bridge2_xy[1] = col
            bridge_count -= 1               # decrement bridge count
        row += 1                                # Increment to the next row down
    row -= 1                                    # Subtract 1 from row, to be at the bottom left corner

    # CHECK BOTTOM EDGE (FROM BOTTOM LHS EDGE TO THE BOTTOM RIGHT EDGE)
    while col < map_dimensions[1]:              # 0 to (col-1):
        if is_land(island_map[row][col]):       # CHECK LHS EDGE for a bridge
            if bridge_count == 2:               # if we have 2 unset bridges
                bridge1_xy[0] = row             # set bridge1
                bridge1_xy[1] = col
                bridge_count -= 1               # decrement bridge count
            else:
                bridge2_xy[0] = row              # Otherwise set bridge2
                bridge2_xy[1] = col
                bridge_count -= 1               # decrement bridge count
        col += 1
    col -= 1                                    # Subtract 1, to be at the bottom right corner

    # CHECK RHS EDGE (FROM BOTTOM RIGHT TO TOP RIGHT EDGE)
    while row > -1:                             # (row-1) to 0:
        if is_land(island_map[row][col]):       # CHECK RHS EDGE for a bridge
            if bridge_count == 2:               # if we have 2 unset bridges
                bridge1_xy[0] = row                # set bridge1
                bridge1_xy[1] = col
                bridge_count -= 1               # decrement bridge count
            else:
                bridge2_xy[0] = row             # Otherwise set bridge2
                bridge2_xy[1] = col
                bridge_count -= 1               # decrement bridge count
        row -= 1                                # Decrement to the next row up
    row += 1                                    # Add 1 to row, to be at the top right corner

    # CHECK TOP EDGE (FROM TOP RHS EDGE TO THE TOP LHS EDGE)
    while col > -1:                             # 0 to (col-1):
        if is_land(island_map[row][col]):       # CHECK LHS EDGE for a bridge
            if bridge_count == 2:               # if we have 2 unset bridges
                bridge1_xy[0] = row             # set bridge1
                bridge1_xy[1] = col
                bridge_count -= 1               # decrement bridge count
            else:
                bridge2_xy[0] = row             # Otherwise set bridge2
                bridge2_xy[1] = col
                bridge_count -= 1               # Decrement bridge count
        col -= 1                                # Decrement column to the next column left
    col += 1                                    # Add 1, to be at the top left corner


def get_mouse_pos(island_map):
    row = 0
    position = []

    for line in island_map:
        col = 0
        for element in line:
            element = int(element)
            if element > 0:
                position.append(row)
                position.append(col)
                # print(f"mouse position: {position}")
                return position
            col += 1
        row += 1


def update_mouse_pos(mouse_map, mouse_xy):
    dir_ = random.randint(0, 3)

    if dir_ == 0:
        mouse_xy[0] -= 1        # Move Up a Row
    elif dir_ == 1:
        mouse_xy[1] += 1        # Move Right a Column
    elif dir_ == 2:
        mouse_xy[0] += 1        # Move Down a Row
    elif dir_ == 3:
        mouse_xy[1] -= 1        # Move Left a Column

    mouse_map[mouse_xy[0]][mouse_xy[1]] += 1


def found_bridge(mouse_xy, br1_xy, br2_xy): # Pass in mouse position, and bridge1 and bridge2 pos
    if mouse_xy[0] == br1_xy[0] and mouse_xy[1] == br1_xy[1]:    # if the mouse is on bridge1 (x and y values match)
        # print(f'\nFound A Bridge #1 At {br1_xy}')
        return True
    elif mouse_xy[0] == br2_xy[0] and mouse_xy[1] == br2_xy[1]:  # if the mouse is on bridge2 (x and y values match)
        # print(f'\nFound A Bridge #2 At {br2_xy}')
        return True
    else:
        return False


def print_matrix(matrix_):  # It's good practice to put _ on parameters to avoid local and globals having the same name
    for row in matrix_:
        print("")                   # Prints a new line for each Row displayed
        for item in row:
            print(item, end="\t")   # Adds a space after each item printed
    print("")                        # Prints a new line at the end to seperate map displays


def clear_matrix(matrix_, map_dim):      # Takes in a matrix [list of row][list of col], and 2 element list [x,y]
    for row in range(0, map_dim[0]):
        for col in range(0, map_dim[1]):
            matrix_[row][col] = 0
    # print("Cleared Map!")
    # print_matrix(matrix_)


def print_stats(escaped,starved,drowned):
    print(f'\nNumber Of Lives: {escaped + drowned + starved}')
    print(f'Escaped: {escaped} times')
    print(f'Drowned: {drowned} times')
    print(f'Starved: {starved} times')


def get_map_dim(map_txt):        # Pass in a string for text file name
    dim = []
    with open(map_txt, 'r') as map_file:
        line1 = map_file.readline()
        dim.append(int(line1[0]))
        dim.append(int(line1[2]))
    # print(dim)
    map_file.close()                    # Close file after open to reset file pointer
    return dim


def load_map(map_txt, dim):        # Pass in a string for text file name, 2 element array for dimensions
    input_map = []                # List of list
    line = []
    row = 0
    col = 0
    negative = False

    with open(map_txt, 'r') as map_file:
        map_file.readline()             # Skip first line
        while row < dim[0]:
            line_str = map_file.readline()
            row += 1
            line.clear()
            for element in line_str.replace(' ', ''):       # Go through each column of the string
                if element == '-':
                    negative = True
                    continue
                if negative and element == '1':
                    line.append(-1)                         # Assumes -1 because its previous element was -
                    negative = False
                    continue
                if element == '0':                          # If its a 0 append 0 to integer map
                    line.append(0)
                elif element == '1':
                    line.append(1)
            input_map.append(line.copy())
        # print(input_map)
    map_file.close()                                        # Close file after open to reset file pointer
    return input_map


def create_blank_map(dim):
    # for Python 3 (no more xrange), the preferred answer
    # zeros = [ [0] * N for _ in range(M)]
    # for M x N array of zeros
    zeros = [[0] * dim[1] for _ in range(dim[0])]
    return zeros


def print_list_of_maps(map_list):
    for each_map in map_list:
        for line in each_map:
            print()
            for each_element in line:
                print(each_element, end=' ')
        print()


def main():
    bridge1_xy = [0, 0]         # location of bridge1
    bridge2_xy = [0, 0]         # location of bridge2

    map_dimensions = get_map_dim("map5-6.txt")   # Read text file first line has dimensions
    island_map = load_map("map5-6.txt", map_dimensions)
    update_bridge_pos(island_map, map_dimensions, bridge1_xy, bridge2_xy)  # Sets where the 2 Bridges Are on the Map
    initial_mouse_xy = get_mouse_pos(island_map)
    mouse_xy = list.copy(initial_mouse_xy)
    mouse_map = create_blank_map(map_dimensions)

    print(f"Initial Mouse Position:{mouse_xy}")

    print("\nIsland Map: ")
    print_matrix(island_map)                    # Prints The board initially
    island_map[mouse_xy[0]][mouse_xy[1]] = 0    # Clear initial mouse position on island map

    escaped_count = 0
    starved_count = 0
    drowned_count = 0

    escaped_maps = []
    starved_maps = []
    drowned_maps = []

    lives = 10
    while lives > 0:
        steps = (map_dimensions[0] * map_dimensions[1]) >> 2    # Number of steps = (row * col) / 4 using shifting
        while steps > 0:
            update_mouse_pos(mouse_map, mouse_xy)           # Move Mouse Randomly
            steps -= 1                                      # Decrement Steps Counter

            if found_bridge(mouse_xy, bridge1_xy, bridge2_xy):
                escaped_count += 1
                escaped_maps.append(copy.deepcopy(mouse_map))
                break
            elif island_map[mouse_xy[0]][mouse_xy[1]] == -1:
                drowned_count += 1
                drowned_maps.append(copy.deepcopy(mouse_map))
                break
            elif steps == 0:
                starved_count += 1
                starved_maps.append(copy.deepcopy(mouse_map))
                break

        # print_matrix(mouse_map)  # Print Mouse Map ALL Result
        lives -= 1                                      # Decrement lives
        clear_matrix(mouse_map, map_dimensions)         # Clear matrix to all 0 for next round
        mouse_xy = list.copy(initial_mouse_xy)          # Reset mouse initial position
        mouse_map[mouse_xy[0]][mouse_xy[1]] = 1         # Set initial position on mouse map
    print_stats(escaped_count, starved_count, drowned_count)

    if escaped_count > 0:
        print(f"\nEscaped Maps: ")
        print_list_of_maps(escaped_maps)


    #if drowned_count > 0:
     #   print(f"\nDrowned Maps: ")
      #  print_list_of_maps(drowned_maps)

    if starved_count > 0:
        print(f"\nStarved Maps: ")
        print_list_of_maps(starved_maps)

main()                                      # Calls main to execute






