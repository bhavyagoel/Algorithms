#include <stdio.h>

int *InsertionSort(int array[], int n) {

    if (n<=1) {
        return array;
    }

    array = InsertionSort(array, n-1);

    int key = array[n-1];
    int i = n-2;

    while (i>-1 && array[i] > key) {
        array[i+1] = array[i];
        i -=1;
    }

    array[i+1] = key;

    return array;
}

int main() {
    int size;
    printf("Enter the size of the array : ");
    scanf("%d", &size);

    int array[size];

    printf("Enter the elements of the array : ");

    for(int i = 0 ; i < size ; i++) {
        scanf("%d", &array[i]);
    }

    int *sortedArray;
    sortedArray = InsertionSort(array, size);

    printf("Sorted array is : [ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortedArray[i]);
    }
    printf("]");
}