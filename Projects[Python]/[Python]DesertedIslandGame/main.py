import copy
import stats
import maps
import navigation
import file_handler


def engine(debug1 = False, debug2 = False, debug3 = False):     # 7 on the map means food

    # file_handler.open_file("AboutMe.pdf")

    # Dictionary Detailing which type of event can happen
    event = {
        "Exit": 'E',            # Represented as a 0 on an edge of the map only, there should be up to 2 Exits
        "Water": -1,            # Any -1 is water
        "Land": 0,
        "Start Position": 1,    # Marked as a Single 1 on the IslandMap
        "Food": 2,              # Marked as a Single 2 on the map representing Food
        "Spikes": 4
    }

    # Dictionary Detailing which map files available to read from in the folder
    TextFile = {
        "Map1": "map5-6.txt",
        "Map2": "map15-18.txt",
        "Map3": "map20-20.txt"
    }

    # Store Maps of Traveled paths for each different Event Outcome
    escaped_maps = []
    starved_maps = []
    drowned_maps = []

    # Get Map Dimensions [row, col] : 2 Element List
    map_dimensions = maps.get_map_dim(TextFile["Map2"])     # Returns a 2 element list [row, col]

    # Populate 2D Maps: Island Layout, and movement_map to keep track of where it has traveled
    island_map = maps.load_map(TextFile["Map2"], map_dimensions)
    movement_map = maps.create_blank_map(map_dimensions)

    # Sets up to Two Bridges Position's on the Map
    navigation.update_bridge_pos(island_map, map_dimensions)

    # Store Initial Position [row, col] of the "Wanderer"
    initial_xy = navigation.get_pos(island_map, event["Start Position"])

    # This block print to console where the events are on the map or if there are any of these events
    if debug1 or debug2 or debug3:
        print(f"\nInitial Position:{initial_xy}")  # Display : Initial Position of Wanderer to the console
        # Store Position [row,col] : Food Element on the map
        food_xy = navigation.get_pos(island_map, event["Food"])
        print("Food Positions", end=':')
        stats.print_event_positions(food_xy)

        # Store Position [row,col] : Spikes Element on the map
        spikes_xy = navigation.get_pos(island_map, event["Spikes"])
        print(f"Spikes Positions", end=':')
        stats.print_event_positions(spikes_xy)

    # Begin : Set Movement Position to the Initial Position on the map
    movement_xy = copy.deepcopy(initial_xy)

    # Display : Map of the Island to the console for the user to see
    print("Island Map: ")
    maps.print_matrix(island_map)

    # Clear Initial Position on Island Map : Marking it as Land represented as 0
    island_map[movement_xy[0]][movement_xy[1]] = 0

    lives = 100
    while lives > 0:
        lives -= 1                                                  # Decrement Lives
        maps.clear_matrix(movement_map, map_dimensions)             # Clear matrix to all 0 for next round
        movement_xy = copy.deepcopy(initial_xy)                     # Reset Back to Initial position
        movement_map[movement_xy[0]][movement_xy[1]] = 1            # Set initial position on movement map
        steps = int((map_dimensions[0] * map_dimensions[1]) >> 2)   # Allowed Steps = (row * col) / 4 using shifting
        if debug3:
            print(f"Steps = {map_dimensions[0]} * {map_dimensions[1]} / 4 = {steps}")
        while steps > 0:                                                 # TODO Enable smart_move = True for better odds
            navigation.rand_update_movement_pos(movement_map, movement_xy, True)     # Move in Random Direction
            steps -= 1                                                               # Decrement Steps Counter

            if navigation.on_event_type(island_map, movement_xy, event["Food"]):
                steps += 2                                                      # Food Replenish 2 steps worth of energy
                if debug3:
                    print("Found Food Energy increased + 2")
                continue
            elif navigation.on_event_type(island_map, movement_xy, event["Spikes"]):
                steps -= 1                                                      # Spikes Lose 1 step worth of energy
                if debug3:
                    print("Oh No stepped on Spikes! Energy decreased -1")
                continue

            if navigation.on_event_type(island_map, movement_xy, event["Exit"]):
                stats.escaped_count += 1
                escaped_maps.append(copy.deepcopy(movement_map))
                break
            elif navigation.on_event_type(island_map, movement_xy, event["Water"]):
                stats.drowned_count += 1
                drowned_maps.append(copy.deepcopy(movement_map))
                break
            elif steps == 0:                                                  # Starved: When Wanderer runs out of steps
                stats.starved_count += 1
                starved_maps.append(copy.deepcopy(movement_map))
                break

    stats.print_all_stats()
    if debug1 or debug2 or debug3:
        if stats.escaped_count > 0:
            print(f"\nEscaped Maps: ")
            maps.print_list_of_maps(escaped_maps)

    if debug2 or debug3:
        if stats.starved_count > 0:
            print(f"\nStarved Maps: ")
            maps.print_list_of_maps(starved_maps)

    if debug3:
        if stats.drowned_count > 0:
            print(f"\nDrowned Maps: ")
            maps.print_list_of_maps(drowned_maps)


# engine() # Prints Island Map, and Stats Only
engine(debug1=True) # Prints everything above, plus Event Object positions on the map, and Escape Maps
# engine(debug2 = True) # Prints everything of debug1, plus Starved Maps
# engine(debug3 = True) # Prints Everything
