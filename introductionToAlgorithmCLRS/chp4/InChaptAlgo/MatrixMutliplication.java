import java.util.Arrays;
import java.util.Scanner; 


public class MatrixMutliplication {
    
    public static int[][] ArrayMulti(int arrayA[], int arrayB[], int size) {
        int result[][] = new int[size][size];
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

    public static void main(String[] args) {

    }
}