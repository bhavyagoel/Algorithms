#include <stdio.h>

int BinarySearch(int array[], int p, int r, int value) {
    if (r >= p){

        int q = (p + r) / 2;
        if (array[q] < value) {
            return BinarySearch(array, q + 1, r, value);
        }
        else if (array[q] > value) {
            return BinarySearch(array, p, q - 1, value);
        }
        else {
            return q;
        }
    }
    return -1;
}

int *binarySearchSum(int array[], int size, int value, int retIndex[]) {
    int flag = 0;
    for (int i = 0 ; i < size ; i++) {
        int subValue = value - array[i];
        int otherIndex = BinarySearch(array, 0, size - 1, subValue);
        if (otherIndex != -1) {
            retIndex[0] = i;
            retIndex[1] = otherIndex;
            flag = 1;
            retIndex[2] = flag;
        }
    }
    return retIndex;
}
void main() {
    printf("Enter the size of array you want : ");
    int size;
    scanf("%d", &size);
    int array[size];
    printf("Enter the elements of the array : ");
    for (int i = 0 ; i < size ; i++ ) {
        scanf("%d", &array[i]);
    }

    printf("Enter the sum value : ");
    int value;
    scanf("%d", &value);
    int retIndex[] = {-1, -1, 0};
    int *index = binarySearchSum(array, size, value, retIndex);
    if (index[2] != 0) {
        printf("Elements are found that sum %d and the elements are %d, %d ." ,value ,array[index[0]] ,array[index[1]]);
    }
    else {
        printf("Summed value is not found !!!");
    }

}
