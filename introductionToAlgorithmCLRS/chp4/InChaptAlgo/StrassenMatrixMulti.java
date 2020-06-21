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

    }

    public static void main(String[] args) {

    }
}