from binary_search import *
from selection_sort import *
from insertion_sort import *


def binary_search_example():
    arr = [13, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28]
    value = int(input("Enter a number to find within the list: "))
    index = binary_search(arr, value)
    print(str(value) + " Found at index " + str(index))


def selection_sort_example():
    array = [10, 20, 30, 4, 5, 1]
    print("Unsorted:", end="\t")
    print(array)
    print("Sorted:\t", end="\t")
    print(selection_sort(array))


def insertion_sort_example():
    array = [10, 20, 30, 4, 5, 1]
    print("Unsorted:", end="\t")
    print(array)
    print("Sorted:\t", end="\t")
    print(insertion_sort(array))



def main():
    # binary_example()
    # selection_sort_example()
    insertion_sort_example()

main()