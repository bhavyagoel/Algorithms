#include <stdio.h>

int *selectionSort(int array[], int size) {
    for (int i = 0 ; i < size ; i++) {
        int smallest = array[i];
        for(int j = i; j < size; j++) {
            if (smallest > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                smallest = array[j];
            }
        }
    }
    return array;
}

int main() {
    int size;
    printf("Enter the size of array : ");
    scanf("%d", &size);
    int array[size];
    printf("Enter the elements of the array : ");
    for (int i = 0 ; i < size ; i ++) {
        scanf("%d", &array[i]);
    }

    int *sortedArray = selectionSort(array, size);

    printf("Sorted array is : [ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortedArray[i]);
    }
    printf("]");
}