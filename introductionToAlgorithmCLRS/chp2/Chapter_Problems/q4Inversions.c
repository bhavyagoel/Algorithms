#include <stdio.h>

int Inversion(int array[], int size) {

    int count = 0;
    for(int i = 0; i < size-1 ; i++) {
        for (int j = i+1 ; j <size ; j++) {
            if (array[i]>array[j]) {
                count++;
            }
        }
    }
    return count;
}


int Merge(int array[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int count = 0;

    int left[n1];
    int right[n2];

    for (int i = 0 ; i < n1; ++i) {
        left[i] = array[p + i];
    }
    for (int j = 0; j < n2; ++j) {
        right[j] = array[q + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = p;

    while(i<n1 && j <n2) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i = i + 1;
        }
        else {
            array[k] = right[j];
            count += (q+1) - (p+i);
            j = j + 1;
        }
        k++;
    }

    while(i < n1) {
        array[k] = left[i];
        i++;
        k++;
    }

    while(j < n2) {
        array[k] = right[j];
        k++;
        j++;
    }

    return count;
}

int MergeInversion(int array[], int p, int r) {
    int count = 0;
    if (p < r) {
        int q = (p+r)/2;
        count += MergeInversion(array, p, q);
        count += MergeInversion(array, q+1, r);
        count += Merge(array, p, q, r);
    }
    return count;
}
int main() {

    int size;
    printf("Enter the size of array you wish to have :- ");
    scanf("%d", &size);
    int array[size];

    printf("Enter the elements of the array : ");

    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }


    int count = Inversion(array, size);
    int count2 = MergeInversion(array, 0, size-1);
    printf("Count of inversion(s) is(are)(Using Merge Sort) \t: %d\n" ,count2);
    printf("Count of inversion(s) is(are)(Using Basic Approach) \t: %d\n" ,count);

}