

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
    
    int array[size][size];
    printf("Enter the elements of array : \n");
    for (int i = 0 ; i < size ; i++) {
        printf("Enter element of row (%d) : " ,(i+1));
        for(int j = 0 ; j < size ; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    int result = Monge(size, array);

    if (result == -1) {
        printf("Given array is not a Monge Array. \n");
    }

    else if (result == 1) {
        printf("Given array is a Monge Array. \n");
    }

}