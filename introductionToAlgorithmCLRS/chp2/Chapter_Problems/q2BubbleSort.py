def BubbleSort(array, size):

    for i in range(size-1): 
        for j in range(size-1, i, -1):
            if (array[j] < array[j-1]):
                temp = array[j]
                array[j] = array[j-1]
                array[j-1] = temp

    return array

if __name__ == "__main__":

    size = int(input("Enter the size of array you wish to have : "))
    array = list(map(lambda x: int(x), input("Enter elements of the array : ").split()))
    sortedArray = BubbleSort(array, size)

    print("Sorted Array is ", sortedArray)