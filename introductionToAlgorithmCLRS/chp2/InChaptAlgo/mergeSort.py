import math

def merge(array, p, q, r):
    n1 = q-p+1
    n2 = r-q

    left = []
    right = []

    for i in range(n1):
        left.append(array[p + i])
    
    for j in range(n2):
        right.append(array[q + j + 1])
    
    left.append(99999) #Representing infinity
    right.append(99999) #Representing infinity
    i = 0
    j = 0

    for k in range(p, r+1, 1):
        if (left[i] <= right[j]):
            array[k] = left[i]
            i+=1
        else:
            array[k] = right[j]
            j+=1

    return array

def mergeSort(array, p, r):
    if (p<r):
        q = math.floor((p+r)/2)
        array = mergeSort(array, p, q)
        array = mergeSort(array, q+1, r)
        array = merge(array, p, q, r)
    return array 


size = int(input("Enter the size of array you wish to have : "))

array = list(map(lambda x: int(x), input("Enter elements of the array : ").split()))

sortedArray = mergeSort(array, 0, size-1)

print("Sorted Array is ", sortedArray)

