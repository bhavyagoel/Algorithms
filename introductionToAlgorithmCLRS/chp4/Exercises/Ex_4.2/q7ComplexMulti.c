#include <stdio.h>

int *ComplexMulti(int *A, int *B, int *C) {
    int M1 = B[0] + B[1];
    int M2 = A[0] + A[1];
    int M3 = B[1] - B[0];

    C[0] = (A[0]*M1 - B[1]*M2);
    C[1] = (B[1]*M2 - A[1]*M3);

    return C;
}


void main() {
    int complexA[2];
    int complexB[2];

    printf("Enter the Complex A : ");
    for (int i = 0; i < 2; i++) {
        scanf("%d", &complexA[i]);
    }

    printf("Enter the Complex B : ");
    for (int i = 0; i < 2; i++) {
        scanf("%d", &complexB[i]);
    }

    int complexC[2];
    ComplexMulti(complexA, complexB, complexC);

    printf("Result of A*B complex number is : %d +i(%d)\n", complexC[0], complexC[1]);
}