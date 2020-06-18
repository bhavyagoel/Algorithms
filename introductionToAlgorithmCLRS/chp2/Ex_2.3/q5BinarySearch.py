import math 

def BinarySearch(array, p , r, value):

    if (r<p):
        return -1
    
    q = math.floor((p + r)/ 2)
    index = -1

    if (array[q] > value):
        return BinarySearch(array, p, q-1, value)
    
    elif (array[q] < value):
        return BinarySearch(array, q+1, r, value)

    else:
        index = q
    
    return index


if __name__ == "__main__":
    size = int(input("Enter the size of array : "))
    array = list(map(lambda x: int(x), input("Enter the elements of array : ").split()))

    value = int(input("Enter the value to be searched for : "))

    index = BinarySearch(array, 0, size -1, value)

    if index != -1:
        print("Given value found at index : ", index)
    else:
        print("Value not found!!!!")
    


