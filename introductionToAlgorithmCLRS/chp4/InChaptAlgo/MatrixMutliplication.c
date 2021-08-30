#include <stdio.h>


int **ArrayMulti(int size, int arrayA[size][size], int arrayB[size][size], int result[size][size]) {

    for (int i = 0 ; i < size ; i ++) {
        for (int j = 0 ; j < size ;j++) {
            result[i][j] = 0;
            for (int k = 0 ; k < size ; k++) {
                result[i][j] = result[i][j] + arrayA[i][k] * arrayB[k][j];
            }
        }
    }

    return result;
}

void main () {

    printf("Enter the size of array : ");
    int size;
    scanf("%d", &size);

    int arrayA[size][size];
    int arrayB[size][size];
    printf("Enter the elements for array A \n");
    for (int i = 0 ; i < size ; i++) {
        printf("Enter element of row (%d) : " ,(i+1));
        for(int j = 0 ; j < size ; j++) {
            scanf("%d", &arrayA[i][j]);
        }
    }

    printf("Enter the elements for array B \n");
    for (int i = 0 ; i < size ; i++) {
        printf("Enter element of row (%d) : " ,(i+1));
        for(int j = 0 ; j < size ; j++) {
            scanf("%d", &arrayB[i][j]);
        }
    }    

    printf("Array A is : \n");
    for (int i = 0 ; i < size ; i++) {
        printf("\t\t[ ");
        for(int j = 0 ; j < size ; j++) {
            printf("%d ",arrayA[i][j]);
        }
        printf("]\n");
    }
    
    printf("Array B is : \n");
    for (int i = 0 ; i < size ; i++) {
        printf("\t\t[ ");
        for(int j = 0 ; j < size ; j++) {
            printf("%d ",arrayB[i][j]);
        }
        printf("]\n");
    }
    int arrayC[size][size];
    ArrayMulti(size, arrayA, arrayB, arrayC);

    printf("Array C is : \n");
    for (int i = 0 ; i < size ; i++) {
        printf("\t\t[ ");
        for(int j = 0 ; j < size ; j++) {
            printf("%d ", arrayC[i][j]);
        }
        printf("]\n");
    }
}