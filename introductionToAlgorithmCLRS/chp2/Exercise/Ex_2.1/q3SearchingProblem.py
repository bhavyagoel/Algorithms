def search(array = [], value = int):
    index = []
    for i in range(len(array)):
        if (array[i] == value):
            index.append(i + 1)

    return index

print("Enter the size of Array : ", end="")
size = int(input())

print("Enter the elements of the array : ", end="")
array = list(map(lambda x: int(x), input().split()))
value = int(input("Enter the value to be searched for : "))
index = search(array, value)

if len(index)>0:
    print("Index of the searched element are : ", index)
else:
    print("No element found !!")
