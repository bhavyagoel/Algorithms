def selectionSort(array, size):
    for i in range(size):
        smallest = array[i]
        for j in range(i, size):
            if (smallest > array[j]):
                temp = array[i]
                array[i] = array[j]
                array[j] = temp
                smallest = array[j]
    return array


size = int(input("Enter the size of array : "))
array = list(map(lambda x: int(x), input("Enter elements of array : ").split()))


sortedArray = selectionSort(array, size)
print("Sorted Array is : ", sortedArray)

