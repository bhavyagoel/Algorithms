public class HeapSort extends BuildMaxHeap{

    public static int[] Sort(int array[], int size, int heapSize) {
        Build(array, size);
        for (int i = size-1; i>-1; i--) {
            int temp = array[1];
            array[1] = array[i];
            array[i] = temp;
            heapSize = heapSize - 1;
            Max(array, i, heapSize);
        }

        return array;
    }
}