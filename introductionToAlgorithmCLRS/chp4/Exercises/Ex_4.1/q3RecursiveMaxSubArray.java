import java.util.Scanner;

public class q3RecursiveMaxSubArray {
    

    public static int RecursiveSubArray(int array[], int p, int r) {
        int sum = 0;
        int maxSum = -99999999;

        for (int i = p ; i <= r-1 ; i++) {
            sum = array[i];
            sum += RecursiveSubArray(array, i+1, r);
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
        int MaxSum = RecursiveSubArray(array, 0, size-1);

        System.out.println("Maximum SubArray sum is : " +MaxSum);
        
    }
}