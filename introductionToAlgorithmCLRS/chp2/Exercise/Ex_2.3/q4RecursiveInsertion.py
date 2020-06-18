def insertionSort(array, n):

    if (n <= 1):
        return array;
    
    array = insertionSort(array, n-1)

    key = array[n-1]
    i = n-2

    while (i>-1 and array[i] > key):
        array[i+1] = array[i]
        i-=1
    
    array[i+1] = key

    return array 


if __name__ == "__main__":

    size = int(input("Enter the size of array you wish to have : "))
    array = list(map(lambda x: int(x), input("Enter elements of the array : ").split()))
    sortedArray = insertionSort(array, size)

    print("Sorted Array is ", sortedArray)