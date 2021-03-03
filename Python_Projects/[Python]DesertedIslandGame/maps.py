def print_list_of_maps(map_list):
    for each_map in map_list:
        for line in each_map:
            print()
            for each_element in line:
                print(each_element, end=' ')
        print()


def print_matrix(matrix_):  # It's good practice to put _ on parameters to avoid local and globals having the same name
    for row in matrix_:
        print("")                   # Prints a new line for each Row displayed
        for item in row:
            print(item, end="\t")   # Adds a space after each item printed
    print("")                        # Prints a new line at the end to seperate


def create_blank_map(dim):
    # for Python 3 (no more xrange), the preferred answer
    # zeros = [ [0] * N for _ in range(M)]
    # for M x N array of zeros
    zeros = [[0] * dim[1] for _ in range(dim[0])]
    return zeros


def clear_matrix(matrix_, map_dim):      # Takes in a matrix [list of row][list of col], and 2 element list [x,y]
    for row in range(0, map_dim[0]):
        for col in range(0, map_dim[1]):
            matrix_[row][col] = 0


def get_map_dim(map_txt):               # Pass in a string for text file name
    dim = []
    with open(map_txt, 'r') as map_file:
        line1 = map_file.readline().split()     # Read text file first line has dimensions : Strip white space
        dim.append(int(line1[0]))
        dim.append(int(line1[1]))
    map_file.close()                    # Close file after open to reset file pointer
    return dim


def load_map(map_txt, dim):             # Pass : string "text_file_name.txt", 2 element list dimensions
    input_map = []                      # List of list
    line = []
    row = 0
    negative = False

    with open(map_txt, 'r') as map_file:
        map_file.readline()             # Skip first line as the first line is map dimensions
        while row < dim[0]:
            line_str = map_file.readline()
            row += 1
            line.clear()
            for element in line_str.replace(' ', ''):       # Go through each column of the string remove spaces
                if element == '-':
                    negative = True
                    continue
                if negative and element == '1':
                    line.append(-1)                         # Assumes -1 because its previous element was -
                    negative = False
                    continue
                if element.isdigit():                       # TODO Create Other Event Element to the map
                    line.append(int(element))               # TODO Like food that recovers steps
                    continue                                # TODO We add it to the island map data to be used
            input_map.append(line.copy())
    map_file.close()                                        # Close file after open to reset file pointer
    return input_map
