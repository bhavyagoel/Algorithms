#include <stdio.h>

int *merge(int array[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int left[n1];
    int right[n2];

    for(int i = 0 ; i<n1; i++) {
        left[i] = array[p + i];
    }

    for(int j = 0 ; j<n2; j++) {
        right[j] = array[q + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = p;

    while(i<n1 && j<n2) {
        if(left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        }
        else {
            array[k] = right[j];
            j++;
        }

        k++;
    }

    while(i < n1) {
        array[k] = left[i];
        k++;
        i++;
    }

    while(j < n2) {
        array[k] = right[j];
        k++;
        j++;
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