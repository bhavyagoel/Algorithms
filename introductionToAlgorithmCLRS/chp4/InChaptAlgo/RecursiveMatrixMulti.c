#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int **MatrixMulti(int rowA, int colA, int rowB, int colB, int size, int **arrayA, int **arrayB) {

    int **arrayC;
    arrayC = malloc((size+1) * sizeof(*arrayC));
    for(int i = 0 ; i < size+1 ; i++) {
        arrayC[i] = malloc((size+1) * sizeof(*arrayC));
    }
    if(size == 1) {
        arrayC[0][0] = arrayA[rowA][colA]*arrayB[rowB][colB];
    }

    else{
        int rowC, colC;
        int newSize = size/2;

        int **newArrayA1 = MatrixMulti(rowA, colA, rowB, colB, newSize, arrayA, arrayB);
        int **newArrayB1 = MatrixMulti(rowA, colA+newSize, rowB+newSize, colB, newSize, arrayA, arrayB);
        rowC = 0;
        colC = 0;
        int n = newSize;
        for (int i = 0; i < n; i++) {
            for(int j = 0 ; j < n; j++ ) {
                arrayC[i + rowC][j+colC] = newArrayA1[i][j] + newArrayB1[i][j];
            }
        }
        int **newArrayA2 = MatrixMulti(rowA, colA, rowB, colB + newSize, newSize, arrayA, arrayB);
        int **newArrayB2 = MatrixMulti(rowA, colA+newSize, rowB+newSize, colB+newSize, newSize, arrayA, arrayB);
        rowC = 0;
        colC = newSize;

        for (int i = 0; i < n; i++) {
            for(int j = 0 ; j < n; j++ ) {
                arrayC[i + rowC][j+colC] = newArrayA2[i][j] + newArrayB2[i][j];
            }
        }


        int **newArrayA3 = MatrixMulti(rowA+newSize, colA, rowB, colB, newSize, arrayA, arrayB);
        int **newArrayB3 = MatrixMulti(rowA + newSize, colA+newSize, rowB+newSize, colB, newSize, arrayA, arrayB);
        rowC = newSize;
        colC = 0;
        for (int i = 0; i < n; i++) {
            for(int j = 0 ; j < n; j++ ) {
                 arrayC[i + rowC][j+colC] = newArrayA3[i][j] + newArrayB3[i][j];
            }
        }

        int **newArrayA4 = MatrixMulti(rowA + newSize, colA, rowB, colB + newSize, newSize, arrayA, arrayB);
        int **newArrayB4 = MatrixMulti(rowA + newSize, colA+newSize, rowB+newSize, colB+newSize, newSize, arrayA, arrayB);
        rowC = newSize;
        colC = newSize;
        for (int i = 0; i < n; i++) {
            for(int j = 0 ; j < n; j++ ) {
                arrayC[i + rowC][j+colC] = newArrayA4[i][j] + newArrayB4[i][j];
            }
        
        }

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

    int **arrayA;
    arrayA = malloc(size * sizeof(*arrayA));
    for(int i = 0 ; i < size ; i++) {
        arrayA[i] = malloc(size * sizeof(*arrayA));
    }
    printf("Enter the elements for array A \n");
    for (int i = 0 ; i < size ; i++) {
        printf("Enter element of row (%d) : " ,(i+1));
        for(int j = 0 ; j < size ; j++) {
            scanf("%d", &arrayA[i][j]);
        }
    }
    int **arrayB;
    arrayB = malloc(size * sizeof(*arrayB));
    for(int i = 0 ; i < size ; i++) {
        arrayB[i] = malloc(size * sizeof(*arrayB));
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

    int **arrayC = MatrixMulti(0, 0, 0, 0, size, arrayA, arrayB);
    printf("Array C is : \n");
    for (int i = 0 ; i < size ; i++) {
        printf("\t\t[ ");
        for(int j = 0 ; j < size ; j++) {
            printf("%d ",arrayC[i][j]);
        }
        printf("]\n");
    }
}


