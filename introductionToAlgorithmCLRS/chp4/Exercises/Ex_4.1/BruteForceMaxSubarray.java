import java.util.Scanner;

public class BruteForceMaxSubarray {
    

    public static int MaxSubarray(int array[], int size) {
        int sum = 0;

        for (int i = 0 ; i < size-1 ; i++) {
            sum = array[i];
            for (int j = i+1 ; j < size ; j++) {
                int new_sum = sum + array[j];
                if (new_sum < sum) {
                    break;
                }
                else {
                    sum = new_sum;
                    continue;
                }
            }
        }
        return sum;
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