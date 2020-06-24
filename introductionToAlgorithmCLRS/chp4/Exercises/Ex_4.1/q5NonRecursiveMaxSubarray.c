#include <stdio.h>

int NonRecursive(int *array, int j) {

    int sum = 0;
    int maxSum = -9999999;
    for (int i = j ; i > -1 ; i--) {
        sum += array[i];
        if (maxSum < sum) {
            maxSum = sum;
        }
        else {
            break;
        }
    }

    if ((maxSum+array[j+1]) > maxSum) {
        maxSum+= array[j+1];
    }
    return maxSum;
}

void main() {

    printf("Enter the size of array :- ");
    int size;
    scanf("%d", &size);

    printf("Enter the elements of the array : ");

    int array[size];
    for(int i = 0; i<size ; i++) {
        scanf("%d", &array[i]);
    }
    printf("Enter the ending index for max subArray : ");
    int j;
    scanf("%d", &j);

    if (j >= size-1) {
        j = size-2;
    }
    int MaxSum = NonRecursive(array, j);

    printf("Maximum SubArray sum is : %d\n" ,MaxSum);
    
}