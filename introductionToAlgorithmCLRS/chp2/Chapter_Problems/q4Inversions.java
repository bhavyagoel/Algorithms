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


    public static int Merge(int array[], int p, int q, int r, int count) {
        int n1 = q - p + 1;
        int n2 = r - q;

        int left[] = new int[n1 + 1];
        int right[] = new int[n2 + 1];

        for (int i = 0 ; i < n1; ++i) {
            left[i] = array[p + i];
        }
        for (int j = 0; j < n2; ++j) {
            right[j] = array[q + j + 1];
        }

        left[n1] = 99999; //Representing infinity
        right[n2] = 99999; //Representing infinity
        int i = 0;
        int j = 0;

        for (int k = p; k < r+1 ; k++) {
            if (left[i] < right[j]) {
                count+=1;
                i+=1;
            }

        }
    
        return count;
    }

    public static int MergeInversion(int array[], int p, int r) {
        int count = 0;
        if (p < r) {
            int q = (p+r)/2;
            count += MergeInversion(array, p, q);
            count += MergeInversion(array, q+1, r);
            count += Merge(array, p, q, r, count);
        }
        return count;
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
        int count2 = MergeInversion(array, 0, size-1);
        System.out.println("Count of inversion(s) is(are) : " +count2);


    }
}