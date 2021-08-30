import java.util.Arrays;
import java.util.Scanner;


public class q2SelectionSort {

    public static int[] selectionSort(int array[], int size) {
        for (int i = 0 ; i < size; i++) {
            int smallest = array[i];
            for (int j = i; j < size; j++) {
                if (smallest > array[j]) {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                    smallest = array[j];
                }
            }
        }
        return array;
    }
    public static void main(String[] args) {
        System.out.print("Enter the size of array : ");
        Scanner element = new Scanner(System.in);
        int size  = element.nextInt();
        int array[] = new int[size];
        System.out.print("Enter elements of the array : ");
        for (int i = 0 ; i < size; i++ ) {
            array[i] = element.nextInt();
        }
        element.close();
        
        int sortedArray[] = new int[size];
        sortedArray = selectionSort(array, size);
        System.out.println("Sorted Array is : " + Arrays.toString(sortedArray));

    }
}