def selection_sort(array):
    for i in range(0, len(array)-1):                    # For each element from 0->(n-2) : last index is already sorted
        # print(array, end="\tPass " + str(i) + "\n")
        min_value_index = i                             # Assume smallest is at current index of unsorted array
        for j in range(i+1, len(array)):                # For each element after current index -> end of array
            if array[j] < array[min_value_index]:       # if there is a smaller element than the current min val's index
                min_value_index = j                     # then new smaller values index is the new min value index
        if min_value_index != i:                        # If the min values index is not the current index of unsorted
            temp = array[min_value_index]               #
            array[min_value_index] = array[i]           # Swap the current unsorted index's value,
            array[i] = temp                             # with the smallest values index
    return array

