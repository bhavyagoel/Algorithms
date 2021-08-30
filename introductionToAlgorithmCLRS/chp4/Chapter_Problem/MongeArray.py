

def Monge(size, array):
    count = 0
    for i in range(size-1):
        for j in range(size-1):
            if ((array[i][j] + array[i+1][j+1]) <= (array[i][j+1] + array[i+1][j])):
                count = 1
            
            else:
                return -1

    return count


if __name__ == "__main__":
    
    size = int(input("Enter the size of array : "))
    
    array = []
    print("Enter the elements of array : ")
    for i in range(size):
        array.append([])
        print("Enter element of row " ,(i+1), " : ", end="" )
        array[i] = list(map(lambda x: int(x), input().split()))
        
    

    result = Monge(size, array)

    if (result == -1):
        print("Given array is not a Monge Array. ")
    

    elif (result == 1):
        print("Given array is a Monge Array. ")
    

