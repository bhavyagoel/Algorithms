import java.util.Scanner;
import java.util.Arrays; 


public class StrassenMatrixMulti {

    public void split(int[][] p, int[][] c, int iB, int jB) {
        for (int i1=0, i2=iB ; i1 < c.length ; i1++, i2++) {
            for (int j1=0,j2=jB; j1<c.length ; j1++, j2++) {
                c[i1][j1] = p[i2][j2];
            }
        }
    }

    public int[][] Sub(int[][] A, int[][] B) {
        int n = A.length;
        int[][] C = new int[n][n];
        for (int i = 0; i < n ; i ++) {
            for (int j = 0 ; j < n; j ++) {
                C[i][j] = A[i][j] - B[i][j];
            }
        }

        return C;
    }

    public int[][] Add(int[][] A, int[][] B) {
        int n = A.length;
        int[][] C = new int[n][n];
        for (int i = 0; i < n ; i ++) {
            for (int j = 0 ; j < n; j ++) {
                C[i][j] = A[i][j] + B[i][j];
            }
        }

        return C;
    }
    
    public int[][] Multiply(int[][] arrayA, int [][] arrayB) {
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

            

        }
    }

    public static void main(String[] args) {

    }
}