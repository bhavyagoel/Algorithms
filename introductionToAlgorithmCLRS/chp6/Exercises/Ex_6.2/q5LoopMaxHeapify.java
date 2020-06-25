import java.util.Arrays;

public class q5LoopMaxHeapify {
    
    public static int Parent(int i) {
        return ((i-1)/2);
    }

    public static int Left(int i) {
        return ((2*i)+1);
    }

    public static int Right(int i) {
        return ((2*i)+2);
    }

    public static void Max(int array[], int i, int size) {
        int num = 1;
        while(num==1) {
            int l = Left(i);
            int r = Right(i);
            int largest = i;
            if (l<=size && array[l]>array[i]) {
                largest = l;
            }

            int temp = array[i];
            array[i] = array[largest];
            array[largest] = temp;
            //i = largest;

            if (r <= size && array[r]>array[i]) {
                largest = r;
            }

            if (largest == i) {
                break;
            }
            temp = array[i];
            array[i] = array[largest];
            array[largest] = temp;
            i = largest;
 
        }

    }

    public static void main(String[] args) {
        int array[] = {1,2,3,4,5,6,7,8,9};
        Max(array, 0, 9);

        System.out.println(Arrays.toString(array));
    }
}
