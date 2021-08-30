import java.util.Scanner; 
import java.util.Arrays; 

public class master extends HeapSort{

    public static void main(String[] args) {
        Scanner element = new Scanner(System.in);
        System.out.print("Enter the size of array : ");
        int size = element.nextInt();

        int array[] = new int[size];
        System.out.print("Enter the elements of the array : ");

        for (int i = 0 ; i < size; i++) {
            array[i] = element.nextInt();
        }
        element.close();
        System.out.println("Your given array is : "+Arrays.toString(array));
        Build(array, size);
        System.out.println("Build Max Heap is : " +Arrays.toString(array));
        Sort(array, size);
        System.out.println("Your sorted array is : "+Arrays.toString(array));

    }
}