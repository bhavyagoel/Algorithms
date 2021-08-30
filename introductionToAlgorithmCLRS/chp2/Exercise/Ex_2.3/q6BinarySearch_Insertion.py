import math 

def BinarySearch(array, p , r, value):

    if (r<p):
        if value > array[p]:
            return p+1
        else:
            return p
    
    q = math.floor((p + r)/ 2)
    index = -1

    if (array[q] > value):
        return BinarySearch(array, p, q-1, value)
    
    elif (array[q] < value):
        return BinarySearch(array, q+1, r, value)

    else:
        index = q + 1
    
    return index

def insertionBinarySort(array = []):
    sortedArray = array
    for i in range(len(array)):
        key = sortedArray[i]
        j = i - 1

        pos = BinarySearch(array, 0, i, key)

        while (j >= pos):
            sortedArray[j + 1] = sortedArray[j]
            j = j - 1
        sortedArray[j + 1] = key
    return sortedArray

if __name__ == "__main__":
    print("Enter the size of Array : ", end="")
    size = int(input())

    print("Enter the elements of the array : ", end="")
    array = list(map(lambda x: int(x), input().split()))

    sortedArray = insertionBinarySort(array)

    print("New Sorted Array is : ", sortedArray)