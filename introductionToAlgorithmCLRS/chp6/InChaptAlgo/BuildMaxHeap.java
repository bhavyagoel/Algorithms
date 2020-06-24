public class BuildMaxHeap extends MaxHeapify{
    public static int Build(int array[], int size) {
        int heapSize = size;
        int n = size;
        for (int i = n-1; i>-1; i--) {
            Max(array, i, heapSize);
        }

        return heapSize;
    }
}
