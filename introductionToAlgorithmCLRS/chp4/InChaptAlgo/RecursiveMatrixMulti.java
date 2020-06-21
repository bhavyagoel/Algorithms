import java.util.Arrays;
import java.util.Scanner; 


public class RecursiveMatrixMulti {

    public static void sumMatrix(int[][]arrayC, int[][]arrayB, int[][]arrayA, int rowC, int colC) {
        int n = arrayA.length;
        for (int i = 0; i < n; i++) {
            for(int j = 0 ; j < n; j++ ) {
                arrayC[i + rowC][j+colC] = arrayA[i][j] + arrayB[i][j];
            }
        }
    }

    public static int[][] MatrixMulti(int[][] arrayA, int[][] arrayB, int rowA, int colA, int rowB, int colB, int size) {
        int [][] arrayC = new int[size][size];

        if(size == 1) {
            arrayC[0][0] = arrayA[rowA][colA]*arrayB[rowB][colB];
        }

        else{
            int newSize = size/2;

            sumMatrix(arrayC, MatrixMulti(arrayA, arrayB, rowA, colA, rowB, colB, newSize), MatrixMulti(arrayA, arrayB, rowA, colA+newSize, rowB+newSize, colB+newSize, newSize), 0, 0);

            sumMatrix(arrayC, MatrixMulti(arrayA, arrayB, rowA, colA, rowB, colB, newSize), MatrixMulti(arrayA, arrayB, rowA, colA+newSize, rowB+newSize, colB+newSize, newSize), 0, 0);

            sumMatrix(arrayC, MatrixMulti(arrayA, arrayB, rowA, colA, rowB, colB, newSize), MatrixMulti(arrayA, arrayB, rowA, colA+newSize, rowB+newSize, colB+newSize, newSize), 0, 0);
            
            sumMatrix(arrayC, MatrixMulti(arrayA, arrayB, rowA, colA, rowB, colB, newSize), MatrixMulti(arrayA, arrayB, rowA, colA+newSize, rowB+newSize, colB+newSize, newSize), 0, 0);

        }
    }

    public static void main(String[] args) {
        Scanner element = new Scanner(System.in);

        int size = element.nextInt();

        int arrayA[][] = new int[size][size];

    }
}

