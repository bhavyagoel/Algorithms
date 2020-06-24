#include <stdio.h>


int MaxSubarray(int *array, int size) {
    int sum = 0;
    int maxSum = -99999999;

    for (int i = 0 ; i < size-1 ; i++) {
        sum = array[i];
        for (int j = i+1 ; j < size ; j++) {
            sum += array[j];
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
        
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
    int MaxSum = MaxSubarray(array, size);

    printf("Maximum SubArray sum is : %d\n" ,MaxSum);
    
}