#include <stdio.h>

#include "HeapSort.h"


void main() {
    printf("Enter the size of array : ");
    int size;
    scanf("%d", &size);

    int array[size];
    printf("Enter the elements of the array : ");

    for (int i = 0 ; i < size; i++) {
        scanf("%d", &array[i]);
    }
    printf("Your given array is : [ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");

    Build(array, size);

    printf("Build Max Heap is : [ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");

    Sort(array, size);
    printf("Your sorted array is : [ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}