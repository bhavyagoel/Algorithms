import math

def Inversion(array, size):

    count = 0
    for i in range(size-1):
        for j in range(i+1, size):
            if (array[i]>array[j]):
                count+=1

    return count



def Merge(array, p, q, r):
    n1 = q - p + 1
    n2 = r - q
    count = 0

    left = []
    right = []

    for i in range(n1):
        left.append(array[p + i])

    for j in range(n2):
        right.append(array[q + j + 1])
    

    i = 0
    j = 0
    k = p

    while(i<n1 and j <n2):
        if (left[i] <= right[j]):
            array[k] = left[i]
            i = i + 1
        
        else:
            array[k] = right[j]
            count += (q+1) - (p+i)
            j = j + 1
        
        k+=1
    

    while(i < n1):
        array[k] = left[i]
        i+=1
        k+=1
    

    while(j < n2):
        array[k] = right[j]
        k+=1
        j+=1
    

    return count



def MergeInversion(array, p, r):
    count = 0
    if (p < r):
        q = math.floor((p+r)/2)
        count += MergeInversion(array, p, q)
        count += MergeInversion(array, q+1, r)
        count += Merge(array, p, q, r)
    
    return count

if __name__ == "__main__":

    size = int(input("Enter the size of array you wish to have :- "))
    
    array = list(map(lambda x: int(x), input("Enter the elements of the array : ").split()))

    count = Inversion(array, size)
    count2 = MergeInversion(array, 0, size-1)
    print("Count of inversion(s) is(are)(Using Merge Sort) \t: " ,count2)
    print("Count of inversion(s) is(are)(Using Basic Approach) \t: " ,count)

