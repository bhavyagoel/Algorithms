import java.util.Scanner;
import java.util.Arrays; 


public class q4RecursiveInsertion {

    public static int[] InsertionSort (int[] array, int n ) {

        if (n<=1) {
            return array;
        }

        array = InsertionSort(array, n-1);

        int key = array[n-1];
        int i = n-2 ;
        while (i >-1 && array[i] > key ) {
            array[i + 1] = array[i];
            i = i - 1;
        }
        array[i+1] = key;
        
        return(array);
    }

    // public static int[] Recursive (int[] array) {
    //     for (int i = 0 ; i <= array.length; i++) {
    //         array = InsertionSort(array, 0, i);
    //     }
    //     return array;
    // }
    public static void main(String[] args) {

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
        int sortedArray[] = InsertionSort(array, array.length);

        System.out.println("New Sorted array is : " + Arrays.toString(sortedArray));

    }
}