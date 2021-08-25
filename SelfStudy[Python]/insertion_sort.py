def insertion_sort(array):
    for index in range(1, len(array)):                          # for index 1 - last element
        position = index                                            # position = current index
        temp_val = array[index]                                     # temp = array[current index]
        while position > 0 and array[position - 1] > temp_val:      # while position gtz and prev element > temp value
            array[position] = array[position - 1]                       # move current array[position] to the right one
            position -= 1                                               # move to the previous position
        array[position] = temp_val                                  # array at position 0 = temp value
    return array                                                # return the sorted

