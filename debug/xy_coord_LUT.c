//2024.04.02.AE -> Modified y and row coordinate mapping
//2024.03.30.AE -> Original Version

//Author: Arnold Etta

//Program: A program developed to create the look-up table mapping
//		   a set of (x,y) coordinates to fruit objects on the game
//		   board. It should have 48 case statements for 8x6 GMBrd.

#include <stdio.h>

int main()
{   
    int x_size = 8, y_size = 1;
    int condition;
    for(int j = 0; j < y_size; j++){
        for(int i = 0; i < x_size; i++){
            condition = (85+(i*28))*(32+(j*30));
            printf("case %d: \n", condition);
            printf("    return GMBrd[%d][%d]; \n", j, i);
        }
    }

    return 0;
}