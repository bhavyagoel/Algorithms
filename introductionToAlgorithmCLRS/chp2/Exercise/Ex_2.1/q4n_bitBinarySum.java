import java.util.Scanner;


public class q4n_bitBinarySum {

    public static long convert(int num) {
        long bin = 0;
        int i;
        i = 1;
        while(num != 0) {
            bin += (num%2)*i;
            num = num / 2;
            i *= 10;
        }
        return bin;
    }

    public static long sum(long bin1, long bin2) {
        long sumBinary = 0;
        long init = 1;
        long res = 0;
        while(bin1 != 0 || bin2 != 0) {
            sumBinary += ((bin1 % 10 + bin2%10 + res)%2 )* init;
            res = (bin1%10 + bin2%10 + res)/2;
            bin1 = bin1/10;
            bin2 = bin2/10;
            init *= 10;
        }
        if (res != 0) {
            sumBinary += res*init;
        }

        return sumBinary;
    }
    public static void main(String[] args) {
        int num1, num2;
        Scanner element = new Scanner(System.in);
        System.out.println("Enter the numbers to be added : ");
        num1 = element.nextInt();
        num2 = element.nextInt();
        element.close();
        long num1Binary = convert(num1);
        long num2Binary = convert(num2);

        System.out.println("Binary of " +num1  +" is " +num1Binary);
        System.out.println("Binary of " +num2  +" is " +num2Binary);

        long sumBinary = sum(num1Binary, num2Binary);

        System.out.println("Sum in Binary is " +sumBinary);
    }
}