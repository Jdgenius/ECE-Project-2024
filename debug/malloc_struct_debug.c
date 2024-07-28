//2024.03.30.AE -> Original Version

//Author: Arnold Etta


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct ExampleStruct {
    int data;
};

int main() {
    // Create an array of pointers to struct ExampleStruct
    struct ExampleStruct *array[MAX_SIZE];
	
    // Allocate memory for each struct and assign its address to the array of pointers
    for (int i = 0; i < 6; ++i) {
        array[i] = (struct ExampleStruct *)malloc(sizeof(struct ExampleStruct));
        if (array[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        array[i]->data = i+1; // Assign some data to each struct
    }

    // Access data through the array of pointers
    printf("Data stored in the structs:\n");
    for (int i = 0; i < MAX_SIZE; ++i) {
        printf("%d\n", array[i]->data);
    }

    // Free allocated memory
    for (int i = 0; i < MAX_SIZE; ++i) {
        free(array[i]);
    }

    return 0;
}