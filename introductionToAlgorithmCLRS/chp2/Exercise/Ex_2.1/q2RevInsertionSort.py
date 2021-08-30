def insertionSort(array = []):
    sortedArray = array
    for i in range(len(array)):
        key = sortedArray[i]
        j = i - 1
        while (j > -1 and sortedArray[j] < key):
            sortedArray[j + 1] = sortedArray[j]
            j = j - 1
        sortedArray[j + 1] = key
    return sortedArray

print("Enter the size of Array : ", end="")
size = int(input())

print("Enter the elements of the array : ", end="")
array = list(map(lambda x: int(x), input().split()))

sortedArray = insertionSort(array)

print("New Sorted Array is : ", sortedArray)
