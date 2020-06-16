#include <stdio.h>
#include <math.h>

long long convert(int num) {
    long long bin = 0;
    int rem, i;
    i = 1;
    while (num != 0 ) {
        rem = num % 2;
        num /= 2;
        bin += rem * i;
        i *= 10;
    }
    return bin;
}

long long sumBin(long long bin1, long long bin2, long long sumBinary) {
    int init = 1;
    sumBinary = 0;
    int res = 0;
    while(bin1 != 0 && bin2 != 0) {
        sumBinary += ((bin1 %10 + bin2%10 + res) %2)*init;
        res = (bin1 %10 + bin2%10 + res)/2;
        bin1 /= 10;
        bin2 /= 10;
        init *= 10;
    }
    if (res != 0) {
        sumBinary += res*init;
    }

    return sumBinary;
}
int main() {
    int num1, num2;
    printf("Enter the number to be added : ");
    scanf("%d %d", &num1, &num2);

    long long num1Binary, num2Binary;

    num1Binary = convert(num1);
    num2Binary = convert(num2);

    printf("Binary of the %d is %lld.\n", num1, num1Binary);
    printf("Binary of the %d is %lld.\n", num2, num2Binary);

    long long sumBinary;
    sumBinary = sumBin(num1Binary, num2Binary, sumBinary);

    printf("sum in Binary is : %lld ", sumBinary);

}