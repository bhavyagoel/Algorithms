import java.util.Scanner;
import java.util.Arrays; 


public class q7ComplexMulti {

    public static int[] ComplexMulti(int[] A, int[] B) {
        int M1 = B[0] + B[1];
        int M2 = A[0] + A[1];
        int M3 = B[1] - B[0];

        int []C = new int[2];
        C[0] = (A[0]*M1 - B[1]*M2);
        C[1] = (B[1]*M2 - A[1]*M3);

        return C;
    }
    

    public static void main(String[] args) {
        Scanner element = new Scanner(System.in);
        int complexA[] = new int[2];
        int complexB[] = new int[2];

        System.out.print("Enter the Complex A : ");
        for (int i = 0; i < 2; i++) {
            complexA[i] = element.nextInt();
        }

        System.out.print("Enter the Complex B : ");
        for (int i = 0; i < 2; i++) {
            complexB[i] = element.nextInt();
        }
        element.close();
        int complexC[] = new int[2];
        complexC = ComplexMulti(complexA, complexB);

        System.out.println("Result of A*B complex number is : "+complexC[0]+" + i"+complexC[1]);
    }
}