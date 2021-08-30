#include <stdio.h>

int *BubbleSort(int array[], int size) {

    for (int i = 0 ; i < size-1; i++) {
        for (int j = size-1; j > i; j--) {
            if (array[j] < array[j-1]) {
                int temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        }
    }
    return array;
}

void main(){

    int size;
    printf("Enter the size of array you wish to have :- ");
    scanf("%d", &size);
    int array[size];

    printf("Enter the elements of the array : ");

    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }


    int *sortedArray = BubbleSort(array, size);

    printf("Sorted array is : [ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortedArray[i]);
    }
    printf("]");

}