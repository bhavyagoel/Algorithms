import java.util.Scanner;
import java.util.Arrays;

public class q3SearchingProblem {

    public static int[] search(int[] array, int value) {
        int count = 0;
        for (int i = 0; i < array.length; i++) {
            if (array[i] == value) {
                count ++;
            }
        }
        int index[] = new int[count];

        if (count > 0) {
            int j = 0;
            for(int i = 0 ; i < array.length ; i++) {
                if (array[i] == value) {
                    index[j] = i + 1;
                    j++;
                }
            }
        }
        return index;
    }
    public static void main(String[] args) {
        int size;
        System.out.println("Enter the size of array you wish to have :-");
        Scanner element = new Scanner(System.in);
        size = element.nextInt();
        int array[] = new int[size];

        System.out.println("First Defination of array is : " + Arrays.toString(array));
        System.out.println("Enter the elements of the array");

        for (int i = 0; i < size; i++) {
            array[i] = element.nextInt();
        }

        int value;
        System.out.println("Enter the element to be searcher for :- ");
        value = element.nextInt();
        element.close();
        int index[] = search(array, value);

        if (index.length == 0) {
            System.out.println("No matching element found!!");
        }

        else {
            System.out.println("Matching elements are found at element(s) : " +Arrays.toString(index));
        }

    }
}