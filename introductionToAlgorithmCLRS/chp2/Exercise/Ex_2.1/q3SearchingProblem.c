#include <stdio.h>

int main() {
    int size;
    printf("Enter the size of array you need : ");
    scanf("%d", &size);
    int array[size];
    printf("Enter the elements of the array \n");
    for (int i = 0 ; i< size; i++) {
        scanf("%d", &array[i]);
    }

    int value;
    printf("Enter the element to be searched for : ");
    scanf("%d", &value);
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            count++;
        }
    }
    int index[count];
    if (count >0) {
        int j = 0;
        for(int i = 0; i < size; i++) {
            if (array[i] == value) {
                index[j] = i + 1;
                j++;
            }
        }
    }
    if (count > 0) {
        printf("Index of searched elements are : [ ");
        for (int i = 0; i < count; i++) {
            printf("%d ", index[i]);
        }
        printf("]");
    }

    else {
        printf("No elements found !! \n");
    }

}