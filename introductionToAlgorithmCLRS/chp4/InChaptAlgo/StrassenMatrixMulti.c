#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int split(int **p, int **c, int iB, int jB, int size) {
    int n = size;
    for (int i1=0, i2=iB ; i1 < n ; i1++, i2++) {
        for (int j1=0,j2=jB; j1<n ; j1++, j2++) {
            c[i1][j1] = p[i2][j2];
        }
    }
}

int **Sub(int **A, int **B, int size) {

    int n = size;
    int **C;
    C = malloc((n) * sizeof(*C));
    for(int i = 0 ; i < n ; i++) {
        C[i] = malloc((n) * sizeof(*C));
    }
    for (int i = 0; i < n ; i ++) {
        for (int j = 0 ; j < n; j ++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return C;
}

int **Add(int **A, int **B, int size) {

    int n = size;
    int **C;
    C = malloc((n) * sizeof(*C));
    for(int i = 0 ; i < n ; i++) {
        C[i] = malloc((n) * sizeof(*C));
    }
    for (int i = 0; i < n ; i ++) {
        for (int j = 0 ; j < n; j ++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

int Join(int **C, int **P, int iB, int jB, int size) {

    int n = size;
    for (int i1 = 0, i2 = iB; i1 < n ; i1++, i2++) {
        for(int j1 =0, j2 = jB ; j1 < n ;j1++, j2++) {
            P[i2][j2] = C[i1][j1];
        }
    }
}
int **Multiply(int **arrayA, int **arrayB, int size) {

    int n = size;
    int **R;
    R = malloc((n) * sizeof(*R));
    for(int i = 0 ; i < n ; i++) {
        R[i] = malloc((n) * sizeof(*R));
    }

    if (n == 1) {
        R[0][0] = arrayA[0][0] * arrayB[0][0];
    }

    else {
        int **A11;
        A11 = malloc((n/2+1) * sizeof(*A11));
        for(int i = 0 ; i < n/2 ; i++) {
            A11[i] = malloc((n/2) * sizeof(*A11));
        }
        int **A12;
        A12 = malloc((n/2) * sizeof(*A12));
        for(int i = 0 ; i < n/2 ; i++) {
            A12[i] = malloc((n/2) * sizeof(*A12));
        }
        int **A21;
        A21 = malloc((n/2) * sizeof(*A21));
        for(int i = 0 ; i < n/2 ; i++) {
            A21[i] = malloc((n/2) * sizeof(*A21));
        }
        int **A22;
        A22 = malloc((n/2) * sizeof(*A22));
        for(int i = 0 ; i < n/2 ; i++) {
            A22[i] = malloc((n/2) * sizeof(*A22));
        }
        int **B11;
        B11 = malloc((n/2) * sizeof(*B11));
        for(int i = 0 ; i < n/2 ; i++) {
            B11[i] = malloc((n/2) * sizeof(*B11));
        }
        int **B12;
        B12 = malloc((n/2) * sizeof(*B12));
        for(int i = 0 ; i < n/2 ; i++) {
            B12[i] = malloc((n/2) * sizeof(*B12));
        }
        int **B21;
        B21 = malloc((n/2) * sizeof(*B21));
        for(int i = 0 ; i < n/2 ; i++) {
            B21[i] = malloc((n/2) * sizeof(*B21));
        }
        int **B22;
        B22 = malloc((n/2) * sizeof(*B22));
        for(int i = 0 ; i < n/2 ; i++) {
            B22[i] = malloc((n/2) * sizeof(*B22));
        }


        split(arrayA, A11, 0, 0, n/2);
        split(arrayA, A12, 0, n/2, n/2);
        split(arrayA, A21, n/2, 0, n/2 );
        split(arrayA, A22, n/2, n/2, n/2 );

        split(arrayB, B11, 0, 0, n/2 );
        split(arrayB, B12, 0, n/2, n/2 );
        split(arrayB, B21, n/2, 0, n/2 );
        split(arrayB, B22, n/2, n/2, n/2 );

        int **M1 = Multiply(Add(A11, A22, n/2 ), Add(B11, B22, n/2 ), n/2 );
        int **M2 = Multiply(Add(A21, A22, n/2 ), B11, n/2 );
        int **M3 = Multiply(A11, Sub(B12, B22, n/2 ), n/2 );
        int **M4 = Multiply(A22, Sub(B21, B11, n/2 ), n/2 );
        int **M5 = Multiply(Add(A11, A12, n/2 ), B22, n/2 );
        int **M6 = Multiply(Sub(A21, A11, n/2 ), Add(B11, B12, n/2 ), n/2 );
        int **M7 = Multiply(Sub(A12, A22, n/2 ), Add(B21, B22, n/2 ), n/2 );

        int **C11 = Add(Sub(Add(M1, M4, n/2 ), M5, n/2 ), M7, n/2 );
        int **C12 = Add(M3, M5, n/2 );
        int **C21 = Add(M2, M4, n/2 );
        int **C22 = Add(Sub(Add(M1, M3, n/2 ), M2, n/2 ), M6, n/2 );


        Join(C11, R,  0, 0, n/2 );
        Join(C12, R, 0, n/2, n/2 );
        Join(C21, R, n/2, 0, n/2 );
        Join(C22, R, n/2, n/2, n/2 );

    }

    return R;
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

    int **arrayC = Multiply(arrayA, arrayB, size);
    printf("Array C is : \n");
    for (int i = 0 ; i < size ; i++) {
        printf("\t\t[ ");
        for(int j = 0 ; j < size ; j++) {
            printf("%d ",arrayC[i][j]);
        }
        printf("]\n");
    }
}


