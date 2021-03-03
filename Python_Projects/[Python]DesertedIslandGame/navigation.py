import random

# Two Bridge Exits on the Map : Assign 2 Element List containing position [row, col] on the map
bridge1_xy = [0, 0]  # location of bridge1   [row, col]
bridge2_xy = [0, 0]  # location of bridge2   [row, col]

direction = {
    'up': 0,
    'right': 1,
    'down': 2,
    'left': 3,
    'last_dir': 0
}


def get_pos(island_map, event_type = 1):
    row = 0
    position = []

    for line in island_map:
        col = 0
        for element in line:
            element = int(element)
            if element == event_type:
                position.append(row)
                position.append(col)
                # print(f"position: {position}")
                # return position   # APPENDS AND RETURNS 2 ELEMENT LIST
            col += 1
        row += 1
    return position

def update_bridge_pos(island_map, map_dimensions):
    bridge_count = 2
    row = 0
    col = 0

    # CHECK LHS EDGE (FROM TOP LEFT DOWN) FOR LAND
    while row < map_dimensions[0]:              # 0 to (row-1):
        if is_even(island_map[row][col]):       # CHECK LHS EDGE for a bridge
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
        if is_even(island_map[row][col]):       # CHECK LHS EDGE for a bridge
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
        if is_even(island_map[row][col]):       # CHECK RHS EDGE for a bridge
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
        if is_even(island_map[row][col]):       # CHECK LHS EDGE for a bridge
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


def at_exit(movement_xy): # Pass in movement position, and bridge1 and bridge2 pos

    if movement_xy[0] == bridge1_xy[0] and movement_xy[1] == bridge1_xy[1]:    # if the movement is on bridge1 (x and y values match)
        # print(f'\nFound A Bridge #1 At {bridge1_xy}')
        return True
    elif movement_xy[0] == bridge2_xy[0] and movement_xy[1] == bridge2_xy[1]:  # if the movement is on bridge2 (x and y values match)
        # print(f'\nFound A Bridge #2 At {bridge2_xy}')
        return True
    else:
        return False


def on_event_type(island_map, movement_xy, type):
    # -1 Represents water
    #  2 Represents Food
    #  4 Represents Spikes
    # 'E' Represents EXIT
    if type == 'E':
        return at_exit(movement_xy)
    return island_map[movement_xy[0]][movement_xy[1]] == type


def rand_update_movement_pos(movement_map, movement_xy, smart_move = False):
    if smart_move:
        dir_ = smart_movement(direction['last_dir'])
    else:
        dir_ = random.randint(0, 3)

    if dir_ == direction['up']:
        movement_xy[0] -= 1                         # Move Up a Row
    elif dir_ == direction['right']:
        movement_xy[1] += 1                         # Move Right a Column
    elif dir_ == direction['down']:
        movement_xy[0] += 1                         # Move Down a Row
    elif dir_ == direction['left']:
        movement_xy[1] -= 1                         # Move Left a Column

    movement_map[movement_xy[0]][movement_xy[1]] += 1

    if smart_move:                  # If smart_move Enabled, we kee track of and store last direction
        direction['last_dir'] = dir_


def smart_movement(last_dir):
    dir_ = random.randint(0, 3)

    if last_dir == direction['up']:     # if we last moved up
        if dir_ == direction['down']:   # and the next intended direction is down
            dir_ = random.randint(0, 3) # we probably down wanna move back down and waste a step, try again

    if last_dir == direction['right']:  # if we last moved right
        if dir_ == direction['left']:   # and the next intended direction is left
            dir_ = random.randint(0, 3) # we probably down wanna move back left and waste a step, try again

    if last_dir == direction['down']:   # if we last moved down
        if dir_ == direction['up']:     # and the next intended direction is up
            dir_ = random.randint(0, 3) # we probably down wanna move back up and waste a step, try again

    if last_dir == direction['left']:   # if we last moved left
        if dir_ == direction['right']:  # and the next intended direction is right
            dir_ = random.randint(0, 3) # we probably down wanna move back down and waste a step try a again

    return dir_


def is_even(value):                 # If the value is even it has to be land or an event item
    return not value & 0x01  # x & y : Does "bitwise and" of x and y, Here value and 0x01 compare LSB against 0x01





