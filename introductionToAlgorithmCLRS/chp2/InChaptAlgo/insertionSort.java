import java.util.Scanner;
import java.util.Arrays;

public class insertionSort {


    public static int[] sorting (int[] array) {
        int sortedArray[] = array;
        for(int j = 1; j < sortedArray.length; j++) {
            int key = sortedArray[j];
            int i = j - 1 ;
            while (i >-1 && sortedArray[i] > key ) {
                sortedArray[i + 1] = sortedArray[i];
                i = i - 1;
            }
            sortedArray[i+1] = key;
        }
        
        return(sortedArray);
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

        int sortedArray[] = sorting(array);

        System.out.println("New Sorted array is : " + Arrays.toString(sortedArray));

    }
}