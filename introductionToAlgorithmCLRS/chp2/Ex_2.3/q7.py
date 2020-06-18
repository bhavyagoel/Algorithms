import math

def binarySearch(array, p, r, value):
    if (r >= p):

        q = math.floor((p + r) / 2)
        if (array[q] < value) :
            return binarySearch(array, q + 1, r, value)
        elif (array[q] > value) :
            return binarySearch(array, p, q - 1, value)
        else:
            return q
    return -1



def binarySearchSum(array, size, value):
    flag = 0
    retIndex = [-1, -1, 0]
    for i in range(size):
        subValue = value - array[i]
        otherIndex = binarySearch(array, 0, size - 1, subValue)
        if (otherIndex != -1):
            retIndex[0] = i
            retIndex[1] = otherIndex
            flag = 1
            retIndex[2] = flag

    return retIndex


if __name__ == "__main__":
    size = int(input("Enter the size of array you want : "))

    array = list(map(lambda x: int(x), input("Enter the elements of the array : ").split()))

    value = int(input("Enter the sum value : "))

    index = binarySearchSum(array, size, value)

    if (index[2] != 0):
        print("Elements are found that sum", value,  "and the elements are", array[index[0]],", " , array[index[1]])
    
    else:
        print("Summed value is not found !!!")
    