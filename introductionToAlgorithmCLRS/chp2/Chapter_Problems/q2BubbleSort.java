import java.util.Scanner;
import java.util.Arrays;

public class q2BubbleSort {
    public static int[] BubbleSort(int array[], int size) {

        for (int i = 0 ; i < size-1; i++) {
            for (int j = size-1; j > i; j--) {
                if (array[j] < array[j-1]) {
                    int temp = array[j];
                    array[j] = array[j-1];
                    array[j-1] = temp;
                }
            }
        }
        return array;
    }

    public static void main(String[] args){

        int size;
        System.out.print("Enter the size of array you wish to have :- ");
        Scanner element = new Scanner(System.in);
        size = element.nextInt();
        int array[] = new int[size];

        System.out.print("Enter the elements of the array : ");

        for (int i = 0; i < size; i++) {
            array[i] = element.nextInt();
        }

        element.close();

        int sortedArray[] = BubbleSort(array, size);

        System.out.println("New Sorted array is : " + Arrays.toString(sortedArray));


    }
}