//2024.04.03.AE-> Replaced game board sort algorithm
//2024.04.02.AE -> Added and implemented search_colID function. Finished up search_xyCoord function
//2024.03.30.AE -> Original Version

//Author: Arnold Etta


#include "sprites.h" // Includes globals.h

/*********************************************************************************************/
/*                                  Function Implemetations                                  */
/*********************************************************************************************/

void swap_fruit(struct fruit* f1, struct fruit* f2){
    // Store f1 xy coord in temporary variables
    int temp_x = f1->x_pos, temp_y = f1->y_pos;

    // Copy xy coord of f2 into f1
    f1->x_pos = f2->x_pos;
    f1->y_pos = f2->y_pos;

    //Copy xy coord of temp (prev. f1) into f2
    f2->x_pos = temp_x;
    f2->y_pos = temp_y;
}

struct fruit* search_colID(struct fruit* GMbrd[][BOARD_WIDTH], const int col_ID){
    for(int row = 0; row < BOARD_LENGTH; row++){
        for(int col = 0; col < BOARD_WIDTH; col++){
            if(GMbrd[row][col]->color_id == col_ID && GMbrd[row][col]->x_pos == 0){
                return GMbrd[row][col];
            }
        }
    }
    return NULL;
}

struct fruit* search_xyCoord(struct fruit* GMBrd[][BOARD_WIDTH], int x, int y){
    
    switch (x*y)
    {
        case 2720: 
            return GMBrd[0][0]; 
        case 3616: 
            return GMBrd[0][1]; 
        case 4512: 
            return GMBrd[0][2]; 
        case 5408: 
            return GMBrd[0][3]; 
        case 6304: 
            return GMBrd[0][4]; 
        case 7200: 
            return GMBrd[0][5]; 
        case 8096: 
            return GMBrd[0][6]; 
        case 8992: 
            return GMBrd[0][7]; 
        case 5270: 
            return GMBrd[1][0]; 
        case 7006: 
            return GMBrd[1][1]; 
        case 8742: 
            return GMBrd[1][2]; 
        case 10478: 
            return GMBrd[1][3]; 
        case 12214: 
            return GMBrd[1][4]; 
        case 13950: 
            return GMBrd[1][5]; 
        case 15686: 
            return GMBrd[1][6]; 
        case 17422: 
            return GMBrd[1][7]; 
        case 7820: 
            return GMBrd[2][0]; 
        case 10396: 
            return GMBrd[2][1]; 
        case 12972: 
            return GMBrd[2][2]; 
        case 15548: 
            return GMBrd[2][3]; 
        case 18124: 
            return GMBrd[2][4]; 
        case 20700: 
            return GMBrd[2][5]; 
        case 23276: 
            return GMBrd[2][6]; 
        case 25852: 
            return GMBrd[2][7]; 
        case 10370: 
            return GMBrd[3][0]; 
        case 13786: 
            return GMBrd[3][1]; 
        case 17202: 
            return GMBrd[3][2]; 
        case 20618: 
            return GMBrd[3][3]; 
        case 24034: 
            return GMBrd[3][4]; 
        case 27450: 
            return GMBrd[3][5]; 
        case 30866: 
            return GMBrd[3][6]; 
        case 34282: 
            return GMBrd[3][7]; 
        case 12920: 
            return GMBrd[4][0]; 
        case 17176: 
            return GMBrd[4][1]; 
        case 21432: 
            return GMBrd[4][2]; 
        case 25688: 
            return GMBrd[4][3]; 
        case 29944: 
            return GMBrd[4][4]; 
        case 34200: 
            return GMBrd[4][5]; 
        case 38456: 
            return GMBrd[4][6]; 
        case 42712: 
            return GMBrd[4][7]; 
        case 15470: 
            return GMBrd[5][0]; 
        case 20566: 
            return GMBrd[5][1]; 
        case 25662: 
            return GMBrd[5][2]; 
        case 30758: 
            return GMBrd[5][3]; 
        case 35854: 
            return GMBrd[5][4]; 
        case 40950: 
            return GMBrd[5][5]; 
        case 46046: 
            return GMBrd[5][6]; 
        case 51142: 
            return GMBrd[5][7];
        
        default:
            break;
    }
};

void swap(struct fruit** a, struct fruit** b){
    struct fruit* temp = *a;
    *a = *b;
    *b = temp;
}

void sort_coordinates(struct fruit** flattened_grid){
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < 47; i++) {
            if (flattened_grid[i]->y_pos > flattened_grid[i + 1]->y_pos) {
                swap(&flattened_grid[i], &flattened_grid[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

void rearrange_grid(struct fruit* GMBrd[][BOARD_WIDTH], struct fruit** flattened_grid){
    int index = 0;
    for (int row = 0; row < 6; row++) {
        for (int col = 0; col < 8; col++) {
            GMBrd[row][col] = flattened_grid[index++];
        }
    }
}

void sort_row(struct fruit* row[], int size){
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < size - 1; i++) {
            if (row[i]->x_pos > row[i + 1]->x_pos) {
                swap(&row[i], &row[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

void sort_grid_by_x(struct fruit* GMBrd[][BOARD_WIDTH]){
    for (int row = 0; row < 6; row++) {
        sort_row(GMBrd[row], 8);
    }
}

void sort_GMBrd(struct fruit* GMBrd[][BOARD_WIDTH]){
    // Flatten the 2D array into a 1D array for sorting
    struct fruit* flattened_grid[48];
    int k = 0;
    for (int j = 0; j < 6; j++) {
        for (int i = 0; i < 8; i++) {
            flattened_grid[k++] = GMBrd[j][i];
        }
    }

    sort_coordinates(flattened_grid);
    rearrange_grid(GMBrd, flattened_grid);
    sort_grid_by_x(GMBrd);
}

// Function to print the gameboard
void printGMBrd(struct fruit* GMBrd[][BOARD_WIDTH], int x_size, int y_size){
    for (int i = 0; i < x_size; i++) {
        for (int j = 0; j < y_size; j++) {
            printf("(%d, %d) ", GMBrd[i][j]->x_pos, GMBrd[i][j]->y_pos);
        }
        printf("\n");
    }
}