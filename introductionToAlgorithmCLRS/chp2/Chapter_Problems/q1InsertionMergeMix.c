#include <stdio.h>


int *InsertionSort(int array[], int p , int q) {
    int *sortedArray = array;
    for(int j = p+1; j < q; j++) {
        int key = sortedArray[j];
        int i = j - 1 ;
        while (i >-1 && sortedArray[i] > key ) {
            sortedArray[i + 1] = sortedArray[i];
            i = i - 1;
        }
        sortedArray[i+1] = key;
    }
    
    return(sortedArray);
}

int* Merge(int array[], int p, int r) {
    if (p < r) {
        int q = (p+r)/2;
        array = Merge(array, p, q);
        array = Merge(array, q+1, r);
        array = InsertionSort(array, p, r+1);

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


    int *sortedArray = Merge(array, 0, size-1);

    printf("Sorted array is : [ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortedArray[i]);
    }
    printf("]");
}