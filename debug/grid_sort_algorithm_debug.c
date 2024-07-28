//2024.04.03.AE -> Completely revamped code for functionality with pointer array and 'row != col' array dimensions
//2024.03.30.AE -> Original Version

//Author: Arnold Etta


#include <stdbool.h>
#include <stdio.h>


typedef struct {
    int x;
    int y;
} coordinate_t;

void swap(coordinate_t** a, coordinate_t** b) {
    coordinate_t* temp = *a;
    *a = *b;
    *b = temp;
}

void sort_coordinates(coordinate_t** flattened_grid) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < 47; i++) {
            if (flattened_grid[i]->y > flattened_grid[i + 1]->y) {
                swap(&flattened_grid[i], &flattened_grid[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

void rearrange_grid(coordinate_t* grid[6][8], coordinate_t** flattened_grid) {
    int index = 0;
    for (int row = 0; row < 6; row++) {
        for (int col = 0; col < 8; col++) {
            grid[row][col] = flattened_grid[index++];
        }
    }
}

void sort_row(coordinate_t* row[], int size) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < size - 1; i++) {
            if (row[i]->x > row[i + 1]->x) {
                swap(&row[i], &row[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

void sort_grid_by_x(coordinate_t* grid[6][8]) {
    for (int row = 0; row < 6; row++) {
        sort_row(grid[row], 8);
    }
}

int main() {
    coordinate_t* grid[6][8] = {
        { &(coordinate_t){85, 32},  &(coordinate_t){85, 62},  &(coordinate_t){85, 92},  &(coordinate_t){85, 122},  &(coordinate_t){85, 152},  &(coordinate_t){85, 182},  &(coordinate_t){113, 32},  &(coordinate_t){113, 62} },
        { &(coordinate_t){197, 32},  &(coordinate_t){197, 62},  &(coordinate_t){197, 92},  &(coordinate_t){197, 122},  &(coordinate_t){197, 152},  &(coordinate_t){197, 182},  &(coordinate_t){225, 32},  &(coordinate_t){225, 62} },
        { &(coordinate_t){113, 92},  &(coordinate_t){113, 122},  &(coordinate_t){113, 152},  &(coordinate_t){113, 182},  &(coordinate_t){141, 32},  &(coordinate_t){141, 62},  &(coordinate_t){141, 92},  &(coordinate_t){141, 122} },
        { &(coordinate_t){225, 92},  &(coordinate_t){225, 122},  &(coordinate_t){225, 152},  &(coordinate_t){225, 182},  &(coordinate_t){253, 32},  &(coordinate_t){253, 62},  &(coordinate_t){253, 92},  &(coordinate_t){253, 122} },
        { &(coordinate_t){141, 152},  &(coordinate_t){141, 182},  &(coordinate_t){169, 32},  &(coordinate_t){169, 62},  &(coordinate_t){169, 92},  &(coordinate_t){169, 122},  &(coordinate_t){169, 152},  &(coordinate_t){169, 182} },
        { &(coordinate_t){253, 152},  &(coordinate_t){253, 182},  &(coordinate_t){281, 32},  &(coordinate_t){281, 62},  &(coordinate_t){281, 92},  &(coordinate_t){281, 122},  &(coordinate_t){281, 152},  &(coordinate_t){281, 182} }
    };
	
	for (int row = 0; row < 6; row++) {
        for (int col = 0; col < 8; col++) {
            printf("(%d, %d) ", grid[row][col]->x, grid[row][col]->y);
        }
        printf("\n");
    }
	printf("\n");
    
	// Flatten the 2D array into a 1D array for sorting
    struct coordinate_t* flattened_grid[48];
    int k = 0;
    for (int j = 0; j < 6; j++) {
        for (int i = 0; i < 8; i++) {
            flattened_grid[k++] = grid[j][i];
        }
    }
	/*
	coordinate_t** flattened_grid = flatten_grid(grid);
	for(int i = 0; i < 48; i++){
		printf("(%d, %d) ", flattened_grid[i]->x, flattened_grid[i]->y);
		if((i+1)%8 == 0){
			printf("\n");	
		}
	}
	*/
    sort_coordinates(flattened_grid);
    rearrange_grid(grid, flattened_grid);
    sort_grid_by_x(grid);

    // Print the sorted grid
    for (int row = 0; row < 6; row++) {
        for (int col = 0; col < 8; col++) {
            printf("(%d, %d) ", grid[row][col]->x, grid[row][col]->y);
        }
        printf("\n");
    }

    return 0;
}


