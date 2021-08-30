#include <stdio.h>

int BinarySearch(int array[], int p, int r, int value) {
    if (r<p) {
        return -1;
    }

    int q = (p + r) / 2;
    int index = -1;

    if (array[q] > value) {
        return BinarySearch(array, p, q-1, value);
    }

    else if (array[q] < value) {
        return BinarySearch(array, q+1, r, value);
    }

    else {
        index = q;
    }

    return index;
}

void main() {
    int size;
    printf("Enter the size of Array :- ");
    scanf("%d", &size);
    int array[size];
    printf("Enter the elements of the array : ");
    for(int i = 0 ; i < size; i++) {
        scanf("%d", &array[i]);
    }
    printf("Enter the value to be searched for : ");
    int value;
    scanf("%d", &value);
    int index = BinarySearch(array, 0, size -1 , value);

    if (index != -1){
        printf( "Your value is found at %d", (index+1));
    }
    else {
        printf("Value not found !!!");
    }
}