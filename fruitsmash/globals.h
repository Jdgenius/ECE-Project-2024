//2024.03.30.AE -> Original Version

//Author: Arnold Etta 

//  globals.h
//  Fruit Smash Game

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

    #include "address_map_nios2.h"

    /*I/O Devices Memory-Mapped Address Bases*/
    #define PS2_BASE_ADDR ((volatile long *) 0xFF200100)
    #define TIMER_BASE_ADDR ((volatile long *) 0xFF202000)
    #define PIXEL_BUF_CTRL_BASE_ADDR ((volatile long *) 0xFF203020)
    #define CHAR_BUF_CTRL_BASE_ADDR ((volatile long *) 0xFF203030)
    
    /*Colour IDs Global Definitions*/
    const int RED = 0xF840;
    const int ORANGE = 0xFBE0;
    const int YELLOW = 0xFF8A;
    const int GREEN = 0x2444;
    const int BLUE = 0x0130;
    const int PURPLE = 0x8010;

    /*Other Global Definitions*/
    #define BOARD_WIDTH ((const short) 8)
    #define BOARD_LENGTH ((const short) 6)
    #define BOARD_COLOUR ((unsigned const short) 0x53f3)
    #define FRUIT_SIZE ((const) 676)
    short int GOLD = 0xA3E0;
    #define UP ((const short) 0)
    #define DOWN ((const short) 1)
    #define RIGHT ((const short) 2)
    #define LEFT ((const short) 3)

    /*Global Variables & Structs*/
    int pause = 0; //Pull to -1 when game is in session. Disable timer interrupt when pushed to 1 and wait for keyboard input.
    int pixel_buffer_start; //Should hold the address to the array identifier for the back buffer always
    volatile int* pixel_ctrl_ptr = (int *)PIXEL_BUF_CTRL_BASE_ADDR;
    volatile int* interval_timer_ptr = (int *)TIMER_BASE_ADDR;
    volatile int* ps2_ptr = (int *)PS2_BASE_ADDR;

    /*Interrupt Function Declarations*/
    void interrupt_handler(void);
    void ps2_keyboard_ISR(void);
    void interval_timer_ISR(void);
    void clear_ps2_fifo(void); // Use RI field of PS/2 control register to clear PS/2 FIFO

    /*VGA Support Function Declarations*/
    void plot_pixel(int x, int y, short int line_color); // To draw a pixel to the screen
    void write_char(int x, int y, char c); // To draw a single (8px by 8px) character to VGA screen
    void draw_box(int x, int y, int x_size, int y_size, short int box_colour, bool fill);
    void draw_screen(const short int* screen_array); // To a draw a 320x240 pic on the VGA screen
    void clear_screen(void); // To paint entire screen black (may not use it at all)
    void wait_for_vsync(void);

    /*Other Function Declarations*/
    void initialize_GAME(void);

#endif