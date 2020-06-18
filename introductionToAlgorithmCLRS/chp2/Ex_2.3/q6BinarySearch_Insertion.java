import java.util.Scanner;
import java.util.Arrays;


public class q6BinarySearch_Insertion {

    public static int binarySearch(int array[], int p, int r, int value) {

        if (r < p) {
            return (value > array[p])?  (p + 1): p; 
        }
            

        int q = (p + r) / 2;
        int index = -1;

        if (array[q] > value) {
            return binarySearch(array, p, q - 1 , value);
        }

        else if (array[q] < value) {
            return binarySearch(array, q + 1, r, value);
        }

        else {
            index = q+1;
        }

        return index;
        

    }
    
    public static int[] InsertionBinarySearch(int array[]) {
        int sortedArray[] = array;
        for(int j = 1; j < sortedArray.length; j++) {
            int key = sortedArray[j];
            int i = j - 1 ;

            int pos = binarySearch(array, 0, i, key);
            while (i >=pos) {
                sortedArray[i + 1] = sortedArray[i];
                i = i - 1;
            }
            sortedArray[i+1] = key;
        }
        
        return(sortedArray);
    }
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

        int sortedArray[] = InsertionBinarySearch(array);

        System.out.println("New Sorted array is : " + Arrays.toString(sortedArray));
    }
}