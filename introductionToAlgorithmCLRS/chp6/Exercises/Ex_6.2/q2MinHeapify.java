public class q2MinHeapify {
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
        int smallest;

        if (l<=heapSize && array[l] < array[i]) {
            smallest = l;
        }
        else {
            smallest = i;
        }

        if (r <= heapSize && array[r] < array[smallest]) {
            smallest = r;
        }

        if (smallest != i) {
            int temp = array[i];
            array[i] = array[smallest];
            array[smallest] = temp;
            Max(array, smallest, heapSize);
        }
    }

}