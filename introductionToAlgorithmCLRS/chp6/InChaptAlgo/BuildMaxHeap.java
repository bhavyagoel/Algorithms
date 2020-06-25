public class BuildMaxHeap extends MaxHeapify{
    public static int Build(int array[], int size) {
        int heapSize = size - 1;
        for (int i = heapSize/2; i>-1; i--) {
            Max(array, i, heapSize);
        }

        return heapSize;
    }
}
