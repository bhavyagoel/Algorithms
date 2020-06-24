#include <stdio.h>
#include <math.h>
#include <stdlib.h>


public static void split(int[][] p, int[][] c, int iB, int jB) {
    for (int i1=0, i2=iB ; i1 < c.length ; i1++, i2++) {
        for (int j1=0,j2=jB; j1<c.length ; j1++, j2++) {
            c[i1][j1] = p[i2][j2];
        }
    }
}

public static int[][] Sub(int[][] A, int[][] B) {
    int n = A.length;
    int[][] C = new int[n][n];
    for (int i = 0; i < n ; i ++) {
        for (int j = 0 ; j < n; j ++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return C;
}

public static int[][] Add(int[][] A, int[][] B) {
    int n = A.length;
    int[][] C = new int[n][n];
    for (int i = 0; i < n ; i ++) {
        for (int j = 0 ; j < n; j ++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

public static void Join(int[][] C, int[][] P, int iB, int jB) {
    for (int i1 = 0, i2 = iB; i1 < C.length ; i1++, i2++) {
        for(int j1 =0, j2 = jB ; j1 < C.length ;j1++, j2++) {
            P[i2][j2] = C[i1][j1];
        }
    }
}

public static int[][] Multiply(int[][] arrayA, int [][] arrayB) {
    int n = arrayA.length;
    int [][] R = new int[n][n];

    if (n == 1) {
        R[0][0] = arrayA[0][0] * arrayB[0][0];
    }

    else {
        int[][] A11 = new int[n/2][n/2];
        int[][] A12 = new int[n/2][n/2];
        int[][] A21 = new int[n/2][n/2];
        int[][] A22 = new int[n/2][n/2];
        int[][] B11 = new int[n/2][n/2];
        int[][] B12 = new int[n/2][n/2];
        int[][] B21 = new int[n/2][n/2];
        int[][] B22 = new int[n/2][n/2];


        split(arrayA, A11, 0, 0);
        split(arrayA, A12, 0, n/2);
        split(arrayA, A21, n/2, 0);
        split(arrayA, A22, n/2, n/2);

        split(arrayB, B11, 0, 0);
        split(arrayB, B12, 0, n/2);
        split(arrayB, B21, n/2, 0);
        split(arrayB, B22, n/2, n/2);

        int[][] M1 = Multiply(Add(A11, A22), Add(B11, B22));
        int[][] M2 = Multiply(Add(A21, A22), B11);
        int[][] M3 = Multiply(A11, Sub(B12, B22));
        int[][] M4 = Multiply(A22, Sub(B21, B11));
        int[][] M5 = Multiply(Add(A11, A12), B22);
        int[][] M6 = Multiply(Sub(A21, A11), Add(B11, B12));
        int[][] M7 = Multiply(Sub(A12, A22), Add(B21, B22));

        int[][] C11 = Add(Sub(Add(M1, M4), M5), M7);
        int[][] C12 = Add(M3, M5);
        int[][] C21 = Add(M2, M4);
        int[][] C22 = Add(Sub(Add(M1, M3), M2), M6);


        Join(C11, R,  0, 0);
        Join(C12, R, 0, n/2);
        Join(C21, R, n/2, 0);
        Join(C22, R, n/2, n/2);

    }

    return R;
}