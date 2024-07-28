#include <stdio.h>

int main()
{
    for(int i = 0; i<320; i++){
        printf("plot_pixel(%d, y, screen_array[320*y + %d]); \n", i, i);
    }
    

    return 0;
}