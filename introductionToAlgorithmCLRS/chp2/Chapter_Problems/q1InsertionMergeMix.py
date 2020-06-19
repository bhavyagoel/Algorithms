import math

def InsertionSort (array, p , q):
    sortedArray = array
    for j in range(p+1, q, 1):
        key = sortedArray[j]
        i = j - 1 
        while (i >-1 and sortedArray[i] > key ):
            sortedArray[i + 1] = sortedArray[i]
            i = i - 1
        
        sortedArray[i+1] = key
    
    
    return(sortedArray)


def Merge(array, p, r):
    if (p < r):
        q = math.floor((p+r)/2)
        array = Merge(array, p, q)
        array = Merge(array, q+1, r)
        array = InsertionSort(array, p, r+1)

    
    return array

if __name__ == "__main__":

    size = int(input("Enter the size of array you wish to have : "))
    array = list(map(lambda x: int(x), input("Enter elements of the array : ").split()))
    sortedArray = Merge(array, 0, size-1)

    print("Sorted Array is ", sortedArray)
