import java.util.Scanner;
import java.util.Arrays;


public class q1InsertionMergeMix {
    
    public static int[] InsertionSort (int[] array, int p , int q) {
        int sortedArray[] = array;
        for(int j = p+1; j < q; j++) {
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

    public static int[] Merge(int array[], int p, int r) {
        if (p < r) {
            int q = (p+r)/2;
            array = Merge(array, p, q);
            array = Merge(array, q+1, r);
            array = InsertionSort(array, p, r+1);

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

        int sortedArray[] = Merge(array, 0, size-1);

        System.out.println("New Sorted array is : " + Arrays.toString(sortedArray));

    }
}