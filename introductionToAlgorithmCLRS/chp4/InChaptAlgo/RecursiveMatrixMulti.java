import java.util.Arrays;
import java.util.Scanner; 


public class RecursiveMatrixMulti {
    // public static int[][] MatrixMulti(int arrayA[][], int arrayB[][], int size) {
    //     int arrayC[][] = new int[size][size];

    //     if (size==1) {
    //         arrayC[0][0] = arrayA[0][0] * array[0][0];
    //     }

    //     else {
    //         arrayC[0][0] = MatrixMulti(arrayA[0][0], arrayB[0][0], size) + MatrixMulti(arrayA[0][1], arrayB[1][0], size);

    //     }
    // }

    public static void main(String[] args) {
        int arrayA[][][][] = new int[2][2][2][2];
        Scanner element = new Scanner(System.in);
        for (int i = 0 ; i < 2 ; i++) {
            for(int j = 0 ; j < 2 ; j++) {
                for (int k = 0 ; k < 2 ; k++) {
                    for(int l = 0 ; l < 2 ; l++) {
                        arrayA[i][j][k][l] = element.nextInt();
                    }
                }  
            }
        }  
        for (int i = 0 ; i < 2 ; i++) {
            for(int j = 0 ; j < 2 ; j++) {
                for (int k = 0 ; k < 2 ; k++) {
                    for(int l= 0 ; l < 2 ; l++) {
                        System.out.println("\t\t" +(arrayA[i][j][k][l]));
                    }
                }    
            }
        }
    }
}

