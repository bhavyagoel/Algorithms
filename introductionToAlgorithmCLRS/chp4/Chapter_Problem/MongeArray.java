import java.util.Scanner;


public class MongeArray {
    
    public static int Monge(int array[][], int size) {
        int count = 0;
        for (int i = 0 ; i < size-1; i++) {
            for(int j = 0 ; j < size-1 ; j++) {
                if ((array[i][j] + array[i+1][j+1]) <= (array[i][j+1] + array[i+1][j])) {
                    count = 1;
                }
                else {
                    return -1;
                }
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner element = new Scanner(System.in);
        System.out.print("Enter the size of array : ");
        int size = element.nextInt();
        int array[][] = new int[size][size];
        System.out.println("Enter the elements of array :");
        for (int i = 0 ; i < size ; i++) {
            System.out.print("Enter element of row (" +(i+1)+") : ");
            for(int j = 0 ; j < size ; j++) {
                array[i][j] = element.nextInt();
            }
        }
        element.close();
        int result = Monge(array, size);

        if (result == -1) {
            System.out.println("Given array is not a Monge Array. ");
        }
        else if (result == 1) {
            System.out.println("Given array is a Monge Array.");
        }
    }
}