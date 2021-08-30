#include <stdio.h>

int  *insertionSort(int array[], int size) {

    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;
        while (j > -1 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
    return array;
}
int main() {
    int size;
    printf("Enter the size of array you need : ");
    scanf("%d", &size);
    int array[size];
    printf("Enter the elements of the array \n");
    for (int i = 0 ; i< size; i++) {
        scanf("%d", &array[i]);
    }
    int *sortedArray;
    sortedArray = insertionSort(array, size);

    printf("Sorted array is : [ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortedArray[i]);
    }
    printf("]");
}