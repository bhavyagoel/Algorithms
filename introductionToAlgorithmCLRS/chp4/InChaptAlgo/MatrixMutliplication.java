import java.util.Arrays;
import java.util.Scanner; 


public class MatrixMutliplication {
    
    public static int[][] ArrayMulti(int arrayA[][], int arrayB[][], int size) {
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
        Scanner element = new Scanner(System.in);
        System.out.print("Enter the size of array : ");
        int size = element.nextInt();

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
    }
}