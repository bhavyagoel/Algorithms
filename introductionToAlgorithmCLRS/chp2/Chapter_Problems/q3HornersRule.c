#include <stdio.h>

int HornersRule(int degree, int coef[], int x) {
    int val = 0;
    for (int i = degree; i >-1; i--) {
        val = coef[i] + x*val;
    }

    return val;
}

void main() {

    printf("Enter the degree of polynomial you wish to have : ");
    int degree;
    scanf("%d", &degree);

    int coef[degree+1];
    printf("Enter the coefficients of the polynomial : ");

    for (int i = 0 ; i < degree+1; i++) {
        scanf("%d", &coef[i]);
    }

    printf("Enter the value of x : ");
    int x;
    scanf("%d", &x);
    int val = HornersRule(degree, coef, x);
printf("The calculated value is : %d" ,val);
}