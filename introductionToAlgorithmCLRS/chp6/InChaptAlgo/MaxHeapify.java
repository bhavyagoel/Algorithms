public class MaxHeapify {


    private static int Parent(int i) {
        return (i/2);
    }

    private static int Left(int i) {
        return (2*i)+1;
    }

    private static int Right(int i) {
        return (2*i)+2;
    }

    public static void Max(int array[], int i, int heapSize) {

        int l = Left(i);
        int r = Right(i);
        int largest;

        if (l<=heapSize && array[l]>array[i]) {
            largest = l;
        }
        else {
            largest = i;
        }

        if (r <= heapSize && array[r] > array[largest]) {
            largest = r;
        }

        if (largest != i) {
            int temp = array[i];
            array[i] = array[largest];
            array[largest] = temp;
            Max(array, largest, heapSize);
        }
    }
}