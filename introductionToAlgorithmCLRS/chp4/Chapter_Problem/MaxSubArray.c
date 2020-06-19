#include <stdio.h>

int *MaxCrossingArray(int array[], int low, int mid, int high, int result[]) {
    int leftSum = -99999999; //Representing negative infinity
    int sum = 0;
    int maxLeft = 0;
    int maxRight = 0;

    for (int i = mid ; i >low-1 ; i-- ) {
        sum = sum + array[i];
        if (sum >leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }

    int rightSum = -99999999; //Representing negative infinity
    sum = 0;

    for (int i = mid+1 ; i < high+1 ; i++) {
        sum = sum + array[i];
        if (sum > rightSum) {
            rightSum = sum;
            maxRight = i;
        }
    }

    int res[] = {maxLeft, maxRight, leftSum+rightSum};
    result = res;
    return result;
}


int *MaximumSubarray(int array[], int low, int high, int result[]) {
    
    if (high == low) {
        int res[] = {low, high, array[low]};
        result = res;
        return result;
    }
    else {
        int mid = (low+high) / 2;
        
        int *leftResult = MaximumSubarray(array, low, mid, result);
        int *rightResult = MaximumSubarray(array, mid+1, high, result);

        int *crossResult = MaxCrossingArray(array, low, mid, high, result);

        if (leftResult[2] >= rightResult[2] && leftResult[2] >= crossResult[2]) {
            result = leftResult;
            return result;
        }
        else if (rightResult[2] >= leftResult[2] && rightResult[2] >= crossResult[2]) {
            result = rightResult;
            return result;
        }
        else {
            result = crossResult;
            return result;
        }

    }
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
    int result[3];
    int *sortedArray = MaximumSubarray(array, 0, size-1, result);
    int maxSum = sortedArray[2];
    int lowIndex = sortedArray[0];
    int highIndex = sortedArray[1];

    printf("Maximum Sub Array is : [");
    for (int i = lowIndex ; i < highIndex+1 ; i++) {
        printf(" %d", array[i]);
    }

    printf(" ] , and the max Sub-array Sum is %d\n" ,maxSum);
}