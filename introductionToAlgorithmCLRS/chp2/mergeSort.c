#include <stdio.h>

int *merge(int array[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - p;

    int left[n1];
    int right[n2];

    for(int i = 0 ; i<n1; i++) {
        left[i] = array[p + i];
    }

    for(int j = 0 ; j<n2; j++) {
        right[j] = array[1 + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = p;

    while(i<n1 && j<n2) {
        if(left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        }
        else {
            array[k] = right[j];
            j++;
        }

        k++;
    }

    while(i < n1) {
        array[k] = left[i];
        k++;
        i++;
    }

    while(j < n2) {
        array[k] = right[j];
        k++;
        j++;
    }

}

