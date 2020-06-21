#include <stdio.h>

int Monge(int size, int array[size][size]) {
    int count = 0;
    for (int i = 0 ; i < size-1; i++) {
        for(int j = 0 ; j < size-1 ; j++) {
            if ((array[i][j] + array[i+1][j+1]) <= (array[i][j+1] + array[i+1][j])) {
                count = 1;
            }
            else {
                return -1;
            }
        }
    }
    return count;
}

void main () {

    printf("Enter the size of array : ");
    int size;
    scanf("%d", &size);
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