import java.util.Arrays;
import java.util.Scanner; 

public class MaxSubArray {
    
    public static int[] MaxCrossingArray(int array[], int low, int mid, int high) {
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

        int result[] = {maxLeft, maxRight, leftSum+rightSum};
        return result;
    }


    public static int[] MaximumSubarray(int array[], int low, int high) {
        
        if (high == low) {
            int result[] ={low, high, array[low]};
            return result;
        }
        else {
            int mid = (low+high) / 2;
            
            int leftResult[] = MaximumSubarray(array, low, mid);
            int rightResult[] = MaximumSubarray(array, mid+1, high);

            int crossResult[] = MaxCrossingArray(array, low, mid, high);

            if (leftResult[2] >= rightResult[2] && leftResult[2] >= crossResult[2]) {
                int result[] = leftResult;
                return result;
            }
            else if (rightResult[2] >= leftResult[2] && rightResult[2] >= crossResult[2]) {
                int result[] = rightResult;
                return result;
            }
            else {
                int result[] = crossResult;
                return result;
            }

        }
    }

    public static void main(String[] args) {

        System.out.print("Enter the size of array :- ");
        Scanner element = new Scanner(System.in);
        int size = element.nextInt();

        System.out.print("Enter the elements of the array : ");

        int array[] = new int[size];
        for(int i = 0; i<size ; i++) {
            array[i] = element.nextInt();
        }
        element.close();
        int sortedArray[] = MaximumSubarray(array, 0, size-1);
        int maxSum = sortedArray[2];
        int lowIndex = sortedArray[0];
        int highIndex = sortedArray[1];

        System.out.print("Maximum Sub Array is : [ ");
        for (int i = lowIndex ; i < highIndex+1 ; i++) {
            System.out.print(array[i] + " ");
        }

        System.out.println("] , and the max Sub-array Sum is " +maxSum);
    }
}