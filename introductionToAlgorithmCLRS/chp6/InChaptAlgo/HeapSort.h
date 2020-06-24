#include "BuildMaxHeap.h"
void Sort(int array[], int size) {
    int heapSize = Build(array, size);
    for (int i = size-1; i>0; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        heapSize = heapSize - 1;
        Max(array, 0, heapSize);
        
        
    }
}