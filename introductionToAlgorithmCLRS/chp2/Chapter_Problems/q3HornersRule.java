import java.util.Arrays;
import java.util.Scanner;


public class q3HornersRule {

    public static int HornersRule(int degree, int coef[], int x) {
        int val = 0;
        for (int i = degree; i >-1; i--) {
            val = coef[i] + x*val;
        }

        return val;
    }
    
    public static void main(String[] args) {
        Scanner element = new Scanner(System.in);

        System.out.print("Enter the degree of polynomial you wish to have : ");
        int degree = element.nextInt();

        int coef[] = new int[(degree+1)];
        System.out.print("Enter the coefficients of the polynomial : ");

        for (int i = 0 ; i < degree+1; i++) {
            coef[i] = element.nextInt();
        }

        System.out.println("Coeeficients are : " +Arrays.toString(coef));

        System.out.print("Enter the value of x : ");
        int x = element.nextInt();
        element.close();
        int val = HornersRule(degree, coef, x);
        System.out.println("The calculated value is : " +val);
    }
}