def binary_search(array, value):
    """    L       M        H
          [0,1,2,3,4,5,6,7,8]
    """
    low_index = 0
    high_index = len(array) - 1

    while low_index <= high_index:
        mid_index = int((low_index + high_index) / 2)
        if array[mid_index] < value:
            low_index = mid_index + 1
        elif array[mid_index] > value:
            high_index = mid_index - 1
        elif array[mid_index] == value:
            return mid_index
    return None

