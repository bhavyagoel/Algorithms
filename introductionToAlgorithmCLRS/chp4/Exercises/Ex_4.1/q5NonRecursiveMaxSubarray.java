import java.util.Arrays;
import java.util.Scanner;

public class q5NonRecursiveMaxSubarray {
    
    public static int NonRecursive(int array[], int j) {

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

    public static void main(String[] args) {

        System.out.print("Enter the size of array :- ");
        Scanner element = new Scanner(System.in);
        int size = element.nextInt();

        System.out.print("Enter the elements of the array : ");

        int array[] = new int[size];
        for(int i = 0; i<size ; i++) {
            array[i] = element.nextInt();
        }
        System.out.print("Enter the ending index for max subArray : ");
        int j = element.nextInt();
        element.close();

        if (j >= size-1) {
            j = size-2;
        }
        int MaxSum = NonRecursive(array, j);

        System.out.println("Maximum SubArray sum is : " +MaxSum);
        
    }

}