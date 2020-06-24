import java.util.Scanner; 
import java.util.Arrays; 


public class MaxHeapify {


    public static int Parent(int i) {
        return (Math.floor(i/2));
    }

    public static int Left(int i) {
        return (2*i);
    }

    public static int Right(int i) {
        return (2i+1);
    }

    public static int[] MaxHeapify(int array[], int i, int size) {

        int l = Left(i);
        int r = Right(i);
        int largest;

        if (l<=size and array[l]>array[i]) {
            largest = l;
        }
        else {
            largest = i;
        }

        


    }
    
    public static void main(String[] args) {

    }




}