import java.util.Scanner;
import java.util.Arrays;

public class mergeSort {

    public static double[] merge(double array[], int p, int q, int r) {
        int n1 = q - p + 1;
        int n2 = r - q;

        double left[] = new double[n1];
        double right[] = new double[n2];

        for (int i = 0 ; i < n1; i++) {
            left[i] = array[p + i -1];
        }
        for (int j = 0; j < n2; j++) {
            right[j] = array[q + j];
        }
        double inf = Double.POSITIVE_INFINITY;
        left[n1 + 1] = inf;
        left[n2 + 1] = inf;

        int i = 0;
        int j = 0;

        for(int k = p; k < r; k++) {
            if (left[i] <= right[j]) {
                array[k] = left[i];
                i = i + 1;
            }
            else {
                array[k] = right[j];
                j = j + 1;
            }
        }
    
        return array;
    }

    public static double[] sorting(double array[], int p, int r) {
        if (p < r) {
            int q = (p+r)/2;
            sorting(array, p, q);
            sorting(array, q+1, r);
            merge(array, p, q, r);
        }
        return array;
    }
    public static void main(String[] args) {
        System.out.print("Enter the size of array :- ");
        Scanner element = new Scanner(System.in);

        
    }
}