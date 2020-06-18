#include <stdio.h>

int BinarySearch(int array[], int p, int r, int value) {

    if (r < p) {
        return (value > array[p])? (p + 1) : p;
    }

    int q = (p + r) / 2;
    int index;

    if(array[q] > value) {
        return  BinarySearch(array, p, q-1, value);
    }
    else if (array[q] < value) {
        return BinarySearch(array, q+1, r, value);
    }

    else{
        index = q+1;
    }

    return index;
}

int *InsertionBinarySearch(int array[], int size) {

    for (int j = 1; j <size ; j++) {
        int key = array[j];
        int i = j-1;
        int pos = BinarySearch(array, 0 , i, key);

        while(i >= pos) {
            array[i+1] = array[i];
            i -= 1;
        }
        array[i+1] = key;
    }

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
    sortedArray = InsertionBinarySearch(array, size);

    printf("Sorted array is : [ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortedArray[i]);
    }
    printf("]");
}