import java.util.Scanner;

public class q4Inversions {
    public static int Inversion(int array[], int size) {

        int count = 0;
        for(int i = 0; i < size ; i++) {
            for (int j = i+1 ; j <size ; j++) {
                if (array[i]>array[j]) {
                    count++;
                }
            }
        }
        return count;
    }

    public static int MergeInversion(int array[], int size) {
        
    }


    public static void main(String[] args){

        int size;
        System.out.print("Enter the size of array you wish to have :- ");
        Scanner element = new Scanner(System.in);
        size = element.nextInt();
        int array[] = new int[size];

        System.out.print("Enter the elements of the array : ");

        for (int i = 0; i < size; i++) {
            array[i] = element.nextInt();
        }

        element.close();

        int count = Inversion(array, size);

        System.out.println("Count of inversion(s) is(are) : " +count);


    }
}