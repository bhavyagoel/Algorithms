public class MaxHeapify {


    public static int Parent(int i) {
        return ((i)/2);
    }

    public static int Left(int i) {
        return ((2*i));
    }

    public static int Right(int i) {
        return ((2*i)+1);
    }

    public static void Max(int array[], int i, int size) {

        int l = Left(i);
        int r = Right(i);
        int largest;

        if (l<size && array[l]>array[i]) {
            largest = l;
        }
        else {
            largest = i;
        }
        
        // if (largest != i) {
        //     int temp = array[i];
        //     array[i] = array[largest];
        //     array[largest] = temp;
        //     Max(array, largest, size);
        // }
        if (r < size && array[r]>array[i]) {
            largest = r;
        }
        // else {
        //     largest = i;
        // }
        

        if (largest != i) {
            int temp = array[i];
            array[i] = array[largest];
            array[largest] = temp;
            Max(array, largest, size);
        }
    }

}