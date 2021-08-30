import java.util.Scanner;
import java.util.Arrays;

public class mergeSort {
    public static int[] merge(int array[], int p, int q, int r) {
        int n1 = q - p + 1;
        int n2 = r - q;

        int left[] = new int[n1 + 1];
        int right[] = new int[n2 + 1];

        for (int i = 0 ; i < n1; ++i) {
            left[i] = array[p + i];
        }
        for (int j = 0; j < n2; ++j) {
            right[j] = array[q + j + 1];
        }

        left[n1] = 99999; //Representing infinity
        right[n2] = 99999; //Representing infinity
        int i = 0;
        int j = 0;

        for (int k = p; k < r+1 ; k++) {
            if (left[i] <= right[j]) {
                array[k] = left[i];
                i+=1;
            }
            else {
                array[k] = right[j];
                j+=1;
            }
        }
    
        return array;
    }

    public static int[] sorting(int array[], int p, int r) {
        if (p < r) {
            int q = (p+r)/2;
            array = sorting(array, p, q);
            array = sorting(array, q+1, r);
            array = merge(array, p, q, r);
        }
        return array;
    }
    public static void main(String[] args) {
        System.out.print("Enter the size of array :- ");
        Scanner element = new Scanner(System.in);
        int size = element.nextInt();

        System.out.print("Enter the elements of the array : ");

        int array[] = new int[size];
        for(int i = 0; i<size ; i++) {
            array[i] = element.nextInt();
        }
        element.close();
        int sortedArray[] = sorting(array, 0, size-1);
        System.out.println("Sorted Array is : " +Arrays.toString(sortedArray));

    }
}