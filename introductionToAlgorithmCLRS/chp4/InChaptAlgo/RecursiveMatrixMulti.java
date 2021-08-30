import java.util.Arrays;
import java.util.Scanner; 
import java.lang.Math;



public class RecursiveMatrixMulti {

    public static void sumMatrix(int[][]arrayC, int[][]arrayA, int[][]arrayB, int rowC, int colC) {
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

            sumMatrix(arrayC, MatrixMulti(arrayA, arrayB, rowA, colA, rowB, colB, newSize), MatrixMulti(arrayA, arrayB, rowA, colA+newSize, rowB+newSize, colB, newSize), 0, 0);

            sumMatrix(arrayC, MatrixMulti(arrayA, arrayB, rowA, colA, rowB, colB + newSize, newSize), MatrixMulti(arrayA, arrayB, rowA, colA+newSize, rowB+newSize, colB+newSize, newSize), 0, newSize);

            sumMatrix(arrayC, MatrixMulti(arrayA, arrayB, rowA + newSize, colA, rowB, colB, newSize), MatrixMulti(arrayA, arrayB, rowA + newSize, colA+newSize, rowB+newSize, colB, newSize), newSize, 0);
            
            sumMatrix(arrayC, MatrixMulti(arrayA, arrayB, rowA + newSize, colA, rowB, colB + newSize, newSize), MatrixMulti(arrayA, arrayB, rowA + newSize, colA+newSize, rowB+newSize, colB+newSize, newSize), newSize, newSize);

        }

        return arrayC;
    }

    public static void main(String[] args) {
        Scanner element = new Scanner(System.in);
        System.out.print("Enter the size of array : ");
        int size = element.nextInt();

        while (((int)(Math.ceil((Math.log(size) / Math.log(2)))) != (int)(Math.floor((Math.log(size) / Math.log(2)))))) {
            System.out.print("Enter size to be a power of 2 : ");
            size = element.nextInt();
        }
        int arrayA[][] = new int[size][size];
        int arrayB[][] = new int[size][size];
        System.out.println("Enter the elements for array A");
        for (int i = 0 ; i < size ; i++) {
            System.out.print("Enter element of row (" +(i+1)+") : ");
            for(int j = 0 ; j < size ; j++) {
                arrayA[i][j] = element.nextInt();
            }
        }

        System.out.println("Enter the elements for array B");
        for (int i = 0 ; i < size ; i++) {
            System.out.print("Enter element of row (" +(i+1)+") : ");
            for(int j = 0 ; j < size ; j++) {
                arrayB[i][j] = element.nextInt();
            }
        }    
        element.close();
        System.out.println("Array A is : ");
        for (int i = 0 ; i < size ; i++) {
            System.out.println("\t\t" +Arrays.toString(arrayA[i]));
        }
        
        System.out.println("Array B is : ");
        for (int i = 0 ; i < size ; i++) {
            System.out.println("\t\t" +Arrays.toString(arrayB[i]));
        }

        int arrayC[][] = MatrixMulti(arrayA, arrayB, 0, 0, 0, 0, size);
        System.out.println("Array C is : ");
        for (int i = 0 ; i < size ; i++) {
            System.out.println("\t\t" +Arrays.toString(arrayC[i]));
        }
    }
}

