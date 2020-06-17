import java.util.Scanner;

public class q7 {

    public static int binarySearch(int array[], int p, int r, int value) {

        if (r >= p){

            int q = (p + r) / 2;
            if (array[q] < value) {
                return binarySearch(array, q + 1, r, value);
            }
            else if (array[q] > value) {
                return binarySearch(array, p, q - 1, value);
            }
            else {
                return q;
            }
        }
        return -1;
    }

    public static int [] binarySearchSum(int array[], int size, int value) {
        int flag = 0;
        int retIndex[] = {-1, -1, 0};
        for (int i = 0 ; i < size ; i++) {
            if (value > array[i]) {
                int subValue = value - array[i];
                int otherIndex = binarySearch(array, 0, size - 1, subValue);
                if (otherIndex != -1) {
                    retIndex[0] = i;
                    retIndex[1] = otherIndex;
                    flag = 1;
                    retIndex[2] = flag;
                }
            }
        }
        return retIndex;
    }

    public static void main(String[] args) {
        System.out.print("Enter the size of array you want : ");
        Scanner element = new Scanner(System.in);
        int size = element.nextInt();
        int array[] = new int[size];
        System.out.print("Enter the elements of the array : ");
        for (int i = 0 ; i < size ; i++ ) {
            array[i] = element.nextInt();
        }

        System.out.print("Enter the sum value : ");
        int value = element.nextInt();
        element.close();
        int index[] = binarySearchSum(array, size, value);

        if (index[2] != 0) {
            System.out.println("Elements are found that sum " +value + " and the elements are [" +array[index[0]] +", " + array[index[1]]+ "].");
        }
        else {
            System.out.println("Summed value is not found !!!");
        }

    }
}