#include <stdio.h>
#include <math.h>
#include <stdlib.h>




void sumMatrix(int rowC, int colC, int size, int arrayC[size][size], int arrayA[size][size], int arrayB[size][size]) {
    int n = size;
    //printf("%d", n);
    for (int i = 0; i < n; i++) {
        for(int j = 0 ; j < n; j++ ) {
            arrayC[i + rowC][j+colC] = arrayA[i][j] + arrayB[i][j];
        }
    }
}

int MatrixMulti(int rowA, int colA, int rowB, int colB, int size, int fixedSize, int arrayC[fixedSize][fixedSize], int arrayA[fixedSize][fixedSize], int arrayB[fixedSize][fixedSize]) {

    if(size == 1) {
        arrayC[0][0] = arrayA[rowA][colA]*arrayB[rowB][colB];
    }

    else{
        int newSize = size/2;
        //printf("hello");

        sumMatrix(0, 0, fixedSize, arrayC, 
                                        MatrixMulti(rowA, colA, rowB, colB, newSize, fixedSize, arrayC, arrayA, arrayB), 
                                        MatrixMulti(rowA, colA+newSize, rowB+newSize, colB, newSize, fixedSize, arrayC, arrayA, arrayB));

        sumMatrix(0, newSize, fixedSize, arrayC, 
                                        MatrixMulti(rowA, colA, rowB, colB + newSize, newSize, fixedSize, arrayC, arrayA, arrayB), 
                                        MatrixMulti(rowA, colA+newSize, rowB+newSize, colB+newSize, newSize, fixedSize, arrayC, arrayA, arrayB));

        sumMatrix(newSize, 0, fixedSize, arrayC, 
                                        MatrixMulti(rowA + newSize, colA, rowB, colB, newSize, fixedSize, arrayC, arrayA, arrayB), 
                                        MatrixMulti(rowA + newSize, colA+newSize, rowB+newSize, colB, newSize, fixedSize, arrayC, arrayA, arrayB));
        
        sumMatrix(newSize, newSize, fixedSize, arrayC, 
                                        MatrixMulti(rowA + newSize, colA, rowB, colB + newSize, newSize, fixedSize, arrayC, arrayA, arrayB), 
                                        MatrixMulti(rowA + newSize, colA+newSize, rowB+newSize, colB+newSize, newSize, fixedSize, arrayC, arrayA, arrayB));

    }
    return arrayC;
}

void main() {

    printf("Enter the size of array : ");
    int size;
    scanf("%d", &size);

    while (((int)(ceil((log(size) / log(2)))) != (int)(floor((log(size) / log(2)))))) {
        printf("Enter size to be a power of 2 : ");
        scanf("%d", &size);
    }
    int arrayA[size][size];
    int arrayB[size][size];
    int arrayC[size][size];
    // int **arrayA;
    // arrayA = malloc(size * sizeof(*arrayA));
    // for(int i = 0 ; i < size ; i++) {
    //     arrayA[i] = malloc(size * sizeof(*arrayA));
    // }
    printf("Enter the elements for array A \n");
    for (int i = 0 ; i < size ; i++) {
        printf("Enter element of row (%d) : " ,(i+1));
        for(int j = 0 ; j < size ; j++) {
            scanf("%d", &arrayA[i][j]);
        }
    }
    // int **arrayB;
    // arrayB = malloc(size * sizeof(*arrayB));
    // for(int i = 0 ; i < size ; i++) {
    //     arrayB[i] = malloc(size * sizeof(*arrayB));
    // }

    printf("Enter the elements for array B \n");
    for (int i = 0 ; i < size ; i++) {
        printf("Enter element of row (%d) : " ,(i+1));
        for(int j = 0 ; j < size ; j++) {
            scanf("%d", &arrayB[i][j]);
        }
    }

    // int **arrayC;
    // arrayC = malloc(size * sizeof(*arrayC));
    // for(int i = 0 ; i < size ; i++) {
    //     arrayC[i] = malloc(size * sizeof(*arrayC));
    // }

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
    // int n = 0;
    // n = sizeof(arrayA);
    // int p = 0;
    // p = sizeof(**arrayA);
    // int q = n / p;
    // printf("%d %d %d", n, p, q);
    MatrixMulti(0, 0, 0, 0, size, size, arrayC, arrayA, arrayB);
    printf("Array C is : \n");
    for (int i = 0 ; i < size ; i++) {
        printf("\t\t[ ");
        for(int j = 0 ; j < size ; j++) {
            printf("%d ",arrayC[i][j]);
        }
        printf("]\n");
    }
}


