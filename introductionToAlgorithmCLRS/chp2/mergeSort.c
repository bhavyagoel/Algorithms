#include <stdio.h>

int *merge(int array[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int left[n1 + 1];
    int right[n2 + 1];

    for(int i = 0 ; i<n1; i++) {
        left[i] = array[p + i];
    }

    for(int j = 0 ; j<n2; j++) {
        right[j] = array[q + j + 1];
    }

    left[n1] = 99999; //Representing infinity
    right[n2] = 99999; //Representing infinity
    int i = 0;
    int j = 0;

    for (int k = p; k < r+1 ; k++) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i+=1;
        }
        else {
            array[k] = right[j];
            j+=1;
        }
    }
    return array;
}

int *mergeSort(int array[], int p, int r) {
    if (p < r) {
        int q = (p + r)/2;
        array = mergeSort(array, p, q);
        array = mergeSort(array, q+1, r);
        merge(array, p, q, r);
    }

    return array;
}

int main() {
    int size;
    printf("Enter the size of Array :- ");
    scanf("%d", &size);
    int array[size];
    printf("Enter the elements of the array : ");
    for(int i = 0 ; i < size; i++) {
        scanf("%d", &array[i]);
    }
    int *sortedArray;
    sortedArray = mergeSort(array, 0, size-1);
    printf("Sorted array is : [ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortedArray[i]);
    }
    printf("]");
}