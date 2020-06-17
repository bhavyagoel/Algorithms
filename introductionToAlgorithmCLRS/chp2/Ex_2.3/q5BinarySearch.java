import java.util.Scanner;

public class q5BinarySearch {
    public static int binarySearch(int array[], int p, int r, int value) {

        int q = (p + r) / 2;
        int index = -1;

        if (array[q] > value) {
            return binarySearch(array, p, q - 1, value);
        }

        else if (array[q] < value) {
            return binarySearch(array, q + 1, r, value);
        }

        else {
            index = q;
        }

        return index;
    }

    public static void main(String[] args) {
        System.out.print("Enter the size of array : ");
        Scanner element = new Scanner(System.in);
        int size = element.nextInt();
        int array[] = new int[size];
        System.out.print("Enter the elements of the array : ");
        for(int i = 0; i < size ; i++) {
            array[i] = element.nextInt();
        }

        System.out.print("Enter the value to be searched for : ");
        int value = element.nextInt();

        int index = binarySearch(array, 0, size -1 , value);

        if (index != -1){
            System.out.println("Your value is found at " +(index+1));
        }
        else {
            System.out.println("Value not found !!!");
        }
    }
}