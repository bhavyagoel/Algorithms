import java.util.Scanner;

public class BruteForceMaxSubarray {
    

    public static int MaxSubarray(int array[], int size) {
        int sum = 0;
        int maxSum = -99999999;

        for (int i = 0 ; i < size-1 ; i++) {
            sum = 0;
            for (int j = i+1 ; j < size ; j++) {
                sum += array[j];
            }
            if (sum > maxSum) {
                maxSum = sum;
            }
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
        element.close();
        int MaxSum = MaxSubarray(array, size);

        System.out.println("Maximum SubArray sum is : " +MaxSum);
        
    }
}