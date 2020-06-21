import java.util.Scanner;
import java.util.Arrays; 


public class StrassenMatrixMulti {
    
    public static int[][] MatrixMultiply(int arrayA[][], int arrayB[][], int rowA, int colA, int rowB, int colB) {
        int arrayC[][] = new int[rowA][colB];

        for (int i = 0 ; i < rowA ; i++) {
            for(int j = 0 ; j < colB ; j++) {
                arrayC[i][j] = 0;
                for (int k = 0 ; k < colA ; k++) {
                    arrayC[i][j] += arrayA[i][k] * arrayB[k][j];
                }
            }
        }

        return arrayC;

    }

    public static int[][] Strassen(int arrayA[][], int arrayB[][], int rowA, int colA, int rowB, int colB) {
        if (rowA == 1 || colA == 1 || colB == 1) {
            return MatrixMultiply(arrayA, arrayB, rowA, colA, rowB, colB)
        }

        int arrayC[][] = new int[rowA][colB];

        int adjN = (rowA >> 1) + (rowA & 1);
        int adjL = (colA >> 1) + (colA & 1);
        int adjM = (colB >> 1) + (colB & 1);

        int As[][][][] = new int[2][2][adjN][adjM];

        for (int i = 0 ; i < 2 ; i++) {
            for (int j = 0 ; j < 2 ; j++) {
                for (int k = 0 ; k < adjN ; k++) {
                    for (int l = 0 ; l < adjM ; l++) {
                        int K = k + (i & 1) * adjN;
                        int L = l + (j & 1) * adjL;

                        As[i][j][k][l] = (K < rowA && L < colA) ? arrayA[K][L] : 0 ;
                    }
                }
            }
        }

        int Bs[][][][] = new int[2][2][adjN][adjM];
        



    }

    public static void main(String[] args) {

    }
}