//2024.03.30.AE -> Original Version

//Author: Arnold Etta


#include <stdio.h>

int* getSecondElement(int arr[], int size) {
    if (size < 2) {
        return NULL; // Array size is too small
    }
    return &arr[1]; // Return a pointer to the second element
}

int main() {
    int num[] = {1, 2, 3};
    int* ptr = getSecondElement(num, sizeof(num) / sizeof(num[0]));

    if (ptr != NULL) {
        printf("Second element of the array: %d\n", *ptr);
    } else {
        printf("Array size is too small\n");
    }

    return 0;
}
