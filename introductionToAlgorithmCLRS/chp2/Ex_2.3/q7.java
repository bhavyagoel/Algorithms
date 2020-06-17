import java.util.Scanner;

public class q7 {
    public static int binarySearchSum(int array[], int p, int r, int value) {

        if (r >= p){

            int q = (p + r) / 2;
            int index;
            if (array[q] < value) {
                return binarySearchSum(array, q + 1, r, value);
            }
            else if (array[q] > value) {
                return binarySearchSum(array, p, q, value);
            }
            else {
                index = q;
                return index;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println("Enter the size of array you want : ");
        Scanner element = 
        int index = binarySearchSum(array, 0, 9, 8);
        System.out.println(index);

    }
}