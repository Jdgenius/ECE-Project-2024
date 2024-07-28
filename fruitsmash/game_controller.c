//2024.04.02.AE -> Implemented game initialization function
//2024.04.01.AE -> Implemented vital parts of ISR functions for testing
//2024.03.31.AE -> Original Version

//Author: Arnold Etta


#include "game_controller.h" // Includes globals.h, sprites.h and game_screen_files.h already

extern int playerScore, targetScore, timeRemaining;
extern struct box_selector sel_1, sel_2;
extern struct fruit* to_be_swapped_1;
extern struct fruit* to_be_swapped_2;
extern struct fruit* GMBrd[BOARD_LENGTH][BOARD_WIDTH];


/*********************************************************************************************/
/*                                  Function Implemetations                                  */
/*********************************************************************************************/

void draw_box_selector(struct box_selector sel, bool clear){
    short int selector_col = GOLD;
    if(clear){
        selector_col = 0; // Make colour Black
    }

    draw_box(sel.x_loc, sel.y_loc, 26, 26, selector_col, 0);
}

void draw_fruit(struct fruit* f0, int data_size){
	int dx = 0, dy = 0;
	
	for(int i = 0; i < data_size; i++){
		if(i%26 != 0){
			plot_pixel(f0->x_pos + dx, f0->y_pos + dy, f0->fruit_data[i]);
			dx++;
		}else{
			dx = 0;
			dy++; 
		}
	}
}

void draw_GMBrd(struct fruit* GMBrd[][BOARD_WIDTH]){
    draw_box(80, 30, 230, 180, BOARD_COLOUR, 1);

    for(int row = 0; row < BOARD_LENGTH; row++){
        for(int col = 0; col < BOARD_WIDTH; col++){
            draw_fruit(GMBrd[row][col], FRUIT_SIZE);
        }
    }
}

void draw_target_score(int target_score, bool clear){
    int y = 6;
    int dx = 0;
    if(clear){
        char* hw = "       "; // 7 spaces to clear score only          
        while (*hw) {
            write_char(11 + dx, y, *hw);
            dx++;
            hw++;
        }
        return;
    }else{
        char* target;
        sprintf(target, "%d", target_score);

        // Print leading word, "Target: "
        char* word = "Target: ";             
        int x = 3;
        while (*word) {
            write_char(x, y, *word);
            x++;
            word++;
        }
        // Print score on the same line afterwards, "Target: (int)target_score"
        while(*target){
            write_char(x, y, *target);
            x++;
            target++;
        }
    }
    return;
}

void draw_player_score(int player_score, bool clear){
    int dx = 0;

    if(clear){
        char* hw = "         "; // 14 spaces to clear target score in its entirety          
        while (*hw) {
            write_char(6 + dx, 38, *hw);
            dx++;
            hw++;
        }
        return;
    }else{
        char* p_score;
        sprintf(p_score, "%d", player_score);

        // Print leading word, "Score: "
        char* word = "Score: ";             
        int x = 4;
        while (*word) {
            write_char(x, 34, *word);
            x++;
            word++;
        }
        // Print score on the next line (2 lines down tbf) afterwards, "Score: \n \n (int)player_score"
        x = 6;
        while(*p_score){
            write_char(x, 38, *p_score);
            x++;
            p_score++;
        }
    }
    return;
}

void draw_timer(int time, bool clear){
    int dx = 0;

    if(clear){
        char* hw = "   "; // 3 spaces to clear time left          
        while (*hw) {
            write_char(9 + dx, 28, *hw);
            dx++;
            hw++;
        }
        return;
    }else{
        char* time_left;
        sprintf(time_left, "%d", time);
 
        // Print time remaining, "(int)time"
        int x = 9;
        while(*time_left){
            write_char(x, 28, *time_left);
            x++;
            time_left++;
        }
        // Print following word on the same line afterwards, "(int)time sec"
        char* word = "sec";
        x = 13;             
        while (*word) {
            write_char(x, 28, *word);
            x++;
            word++;
        }
    }
    return;
}

void animate_box_selector(struct box_selector sel, int direction){
    switch (direction)
    {
    case UP: ;
        int prev_y_loc_up = sel.y_loc + 30;
        int new_y_loc_up = sel.y_loc;

        for(int j = (prev_y_loc_up - 2); j >= new_y_loc_up; j-=2){
            draw_fruit(search_xyCoord(GMBrd, sel.x_loc, new_y_loc_up), FRUIT_SIZE);
            draw_fruit(search_xyCoord(GMBrd, sel.x_loc, prev_y_loc_up), FRUIT_SIZE);

            sel.y_loc = j;

            draw_box_selector(sel, 0);

            wait_for_vsync();
            pixel_buffer_start = *(pixel_ctrl_ptr + 1);
        }

        sel.y_loc = new_y_loc_up;
        return;
    
    case DOWN: ;
        int prev_y_loc_dwn = sel.y_loc - 30;
        int new_y_loc_dwn = sel.y_loc;

        for(int j = (prev_y_loc_dwn + 2); j >= new_y_loc_dwn; j+=2){
            draw_fruit(search_xyCoord(GMBrd, sel.x_loc, new_y_loc_dwn), FRUIT_SIZE);
            draw_fruit(search_xyCoord(GMBrd, sel.x_loc, prev_y_loc_dwn), FRUIT_SIZE);

            sel.y_loc = j;

            draw_box_selector(sel, 0);

            wait_for_vsync();
            pixel_buffer_start = *(pixel_ctrl_ptr + 1);
        }

        sel.y_loc = new_y_loc_dwn;
        return;

    case LEFT: ;
        int prev_x_loc_lft = sel.x_loc + 28;
        int new_x_loc_lft = sel.x_loc;

        for(int i = (prev_x_loc_lft - 2); i >= new_x_loc_lft; i-=2){
            draw_fruit(search_xyCoord(GMBrd, new_x_loc_lft, sel.y_loc), FRUIT_SIZE);
            draw_fruit(search_xyCoord(GMBrd, prev_x_loc_lft, sel.y_loc), FRUIT_SIZE);

            sel.x_loc = i;

            draw_box_selector(sel, 0);

            wait_for_vsync();
            pixel_buffer_start = *(pixel_ctrl_ptr + 1);
        }

        sel.x_loc = new_x_loc_lft;
        return;

    case RIGHT: ;
        int prev_x_loc_rht = sel.x_loc - 28;
        int new_x_loc_rht = sel.x_loc;

        for(int i = (prev_x_loc_rht + 2); i >= new_x_loc_rht; i+=2){
            draw_fruit(search_xyCoord(GMBrd, new_x_loc_rht, sel.y_loc), FRUIT_SIZE);
            draw_fruit(search_xyCoord(GMBrd, prev_x_loc_rht, sel.y_loc), FRUIT_SIZE);

            sel.x_loc = i;

            draw_box_selector(sel, 0);

            wait_for_vsync();
            pixel_buffer_start = *(pixel_ctrl_ptr + 1);
        }

        sel.x_loc = new_x_loc_rht;
        return;

    default:
        break;
    }
}

void move_box_selector(int direction){
    switch (direction)
    {
    case UP:
        if( ((sel_1.isLatched == false) && (sel_1.y_loc > 32)) ){
            sel_1.y_loc -= 30;
            animate_box_selector(sel_1, UP);
        }else if( ((sel_1.isLatched == true && sel_2.isLatched == false) && (sel_2.y_loc > 32)) ){
            sel_2.y_loc -= 30;
            animate_box_selector(sel_2, UP);

            draw_box_selector(sel_1, 0);
        }else{
            // Too far up (possible audio output constraint message)

            ;
        }
        return;
    
    case DOWN:
        if( ((sel_1.isLatched == false) && (sel_1.y_loc < 182)) ){
            sel_1.y_loc += 30;
            animate_box_selector(sel_1, DOWN);
        }else if( ((sel_1.isLatched == true && sel_2.isLatched == false) && (sel_2.y_loc < 182)) ){
            sel_2.y_loc += 30;
            animate_box_selector(sel_2, DOWN);

            draw_box_selector(sel_1, 0);
        }else{
            // Too far down (possible audio output constraint message)

            ;
        }
        return;

    case LEFT:
        if( ((sel_1.isLatched == false) && (sel_1.x_loc > 85)) ){
            sel_1.y_loc -= 28;
            animate_box_selector(sel_1, LEFT);

            draw_box_selector(sel_1, 0);
        }else if( ((sel_1.isLatched == true && sel_2.isLatched == false) && (sel_2.y_loc > 85)) ){
            sel_2.y_loc -= 28;
            animate_box_selector(sel_2, LEFT);
        }else{
            // Too far left (possible audio output constraint message)

            ;
        }
        return;

    case RIGHT:
        if( ((sel_1.isLatched == false) && (sel_1.y_loc < 281)) ){
            sel_1.y_loc += 28;
            animate_box_selector(sel_1, RIGHT);
        }else if( ((sel_1.isLatched == true && sel_2.isLatched == false) && (sel_2.y_loc < 281)) ){
            sel_2.y_loc += 28;
            animate_box_selector(sel_2, RIGHT);

            draw_box_selector(sel_1, 0);
        }else{
            // Too far right (possible audio output constraint message)

            ;
        }
        return;
    
    default:
        break;
    }
    return; //Again, not necessary
}
/* IGNORE FOR NOW
void draw_swap(char* swap[5], bool clear);
void draw_menu(bool clear);
void draw_squash(bool clear);
*/
int check_match(struct fruit* GMBrd[][BOARD_WIDTH]){
    int fruit_smashed = 0;
    //Check horizontal matching
    for(int row = 0; row < 6; row++){
        for(int col = 0; col < 8; col++){
            int count = 0;
            for(int step = 0; col + step < 8; step++){
                if(GMBrd[row][col+step]->color_id == GMBrd[row][col]->color_id){
                    count += 1;
                }
            }
            if(count >= 3){
                for(int i = 0; i < count; i++){
                    GMBrd[row][col+i]->isSmashed = 1;
                }
                fruit_smashed += count;
            }
        }
    }

    return fruit_smashed;
}



/*********************************************************************************************/
/*                                INITIALIZE GAME FUNCTION                                   */
/*********************************************************************************************/

void initialize_GAME(void){
    draw_screen(game_background); // Draw game background image first
    draw_target_score(15000, 0);
    draw_timer(999, 0);
    draw_player_score(0, 0);
    
    // Randomize fruit placement on Game Board
    for(int row = 0; row < BOARD_LENGTH; row++){
        for(int col = 0; col < BOARD_WIDTH; col++){
            switch (fruit_arrangement_1[row][col])
            {
            case 'R': ;
                struct fruit* apple_temp = search_colID(GMBrd, RED);
                apple_temp->x_pos = 85 + (col*28);
                apple_temp->y_pos = 32 + (row*30);
                break;
            
            case 'O': ;
                struct fruit* orange_temp = search_colID(GMBrd, ORANGE);
                orange_temp->x_pos = 85 + (col*28);
                orange_temp->y_pos = 32 + (row*30);
                break;
            
            case 'Y': ;
                struct fruit* lemon_temp = search_colID(GMBrd, YELLOW);
                lemon_temp->x_pos = 85 + (col*28);
                lemon_temp->y_pos = 32 + (row*30);
                break;

            case 'G': ;
                struct fruit* watermelon_temp = search_colID(GMBrd, GREEN);
                watermelon_temp->x_pos = 85 + (col*28);
                watermelon_temp->y_pos = 32 + (row*30);
                break;
            
            case 'B': ;
                struct fruit* blueberry_temp = search_colID(GMBrd, BLUE);
                blueberry_temp->x_pos = 85 + (col*28);
                blueberry_temp->y_pos = 32 + (row*30);
                break;
            
            case 'P': ;
                struct fruit* grape_temp = search_colID(GMBrd, PURPLE);
                grape_temp->x_pos = 85 + (col*28);
                grape_temp->y_pos = 32 + (row*30);
                break;
            
            default:
                break;
            }
        }
    }

    sort_GMBrd(GMBrd);

    draw_GMBrd(GMBrd);

    return;

}




/*********************************************************************************************/
/*                              Interrupt Function Implemetations                            */
/*********************************************************************************************/

void ps2_keyboard_ISR(void){
    int PS2_Data = *ps2_ptr & 0xFFFF80FF; //Read from PS_2 data register

    int RAVAIL = PS2_Data & 0xFFFF0000;
    int RVALID = PS2_Data & 0x00008000;

    int key_code_1 = 0x00, key_code_2 = 0x00, key_code_3 = PS2_Data & 0x000000FF;

    int limiter = 1;

    while(RAVAIL != 0 && limiter < 3){
        PS2_Data = *ps2_ptr & 0xFFFF80FF;
        RAVAIL = PS2_Data & 0xFFFF0000;

        key_code_1 = key_code_2;
        key_code_2 = key_code_3;
        key_code_3 = PS2_Data & 0x000000FF;

        limiter++;
    }

    switch (pause)
    {
    case 0: /*Game has not started*/
        // Do not start game (pull pause to -1) and return from ISR until 'Enter' is pressed
        if(key_code_1 != 0x5A){ // add || key_code_2 != 0x5A if need be
            return;
        }else{
            pause = -1; // Game is in session
            return;
            //vsync
        }
        break;

    case 1: /*Game is already paused*/
        // Leave game paused and return from ISR until 'Enter' or 'Esc' is pressed)
        if( (key_code_1 != 0x5A || key_code_1 != 0x76) ){
            return;
        }else{
            switch (key_code_1)
            {
            case 0x76:
                pause = -1;
                break;
            case 0x5A:
                pause = 0;
                load_game_start_screen();
                break;
            
            default:
                break;
            }

            return;
        }
        break;

    case -1: /*Game is already in session*/
        // Check if interrupt was triggered to pause it
        if(key_code_1 == 0x76){
            pause = 1;
            // print menu function
            // vsync
            return;
        }

        // Check if interrupt was trigerred by box selector latching onto fruit
        if(key_code_1 == 0x29){
            if(sel_1.isLatched == false){
                to_be_swapped_1 = search_xyCoord(GMBrd, sel_1.x_loc, sel_1.y_loc);
                draw_box_selector(sel_1, 0);
                sel_1.isLatched = true;

                draw_box_selector(sel_2, 0);

                wait_for_vsync();
                pixel_buffer_start = *(pixel_ctrl_ptr + 1);

                return;
            }else if(sel_1.isLatched == true && sel_2.isLatched == false){
                to_be_swapped_2 = search_xyCoord(GMBrd, sel_2.x_loc, sel_2.y_loc);
                sel_2.isLatched = true;

                swap_fruit(to_be_swapped_1, to_be_swapped_2);
                sort_GMBrd(GMBrd);

                draw_fruit(to_be_swapped_1, FRUIT_SIZE);
                draw_fruit(to_be_swapped_2, FRUIT_SIZE);

                wait_for_vsync();
                pixel_buffer_start = *(pixel_ctrl_ptr + 1);

                // Draw swapped fruits on newly acquired back buffer
                draw_fruit(to_be_swapped_1, FRUIT_SIZE);
                draw_fruit(to_be_swapped_2, FRUIT_SIZE);

                int match_mesh = check_match(GMBrd);

                if(match_mesh == 0){
                    sel_1.isLatched = false;
                    sel_2.isLatched = false;

                    draw_box_selector(sel_2, 1);

                    // Reset sel_2 location (possibly?)

                    wait_for_vsync();
                    pixel_buffer_start = *(pixel_ctrl_ptr + 1);

                    return;
                }else{
                    int count = 0;

                    for(int row = 0; row < BOARD_LENGTH; row++){
                        for(int col = 0; col < BOARD_WIDTH; col++){
                            if(GMBrd[row][col]->isSmashed = 1){
                                draw_box(GMBrd[row][col]->x_pos, GMBrd[row][col]->y_pos, 26, 26, 0, 1); // should be animate_swap or smth
                                count++;
                            }
                            if(count == match_mesh){
                                wait_for_vsync();
                                pixel_buffer_start = *(pixel_ctrl_ptr + 1);
                                return;
                            }
                        }
                    }
                    wait_for_vsync(); // Some fruits may get meshed more than once; so, count </= match_mesh always
                    pixel_buffer_start = *(pixel_ctrl_ptr + 1);
                    return; // Shouldn't be necessary if everything above this (within else) goes fine
                }
            }
        }

        // Check if interrupt was triggered to move box selectors
        if( (key_code_1 != 0x1D || key_code_1 != 0x1B || key_code_1 != 0x1C || key_code_1 != 0x23 ) ){
            // Exit if-else block (i.e Do nothing)
            ;
        }else{
            switch (key_code_1)
            {
            // UP ANIMATION
            case 0x1D:
                move_box_selector(UP);
                switch (key_code_2)
                {
                case 0x1D:
                    move_box_selector(UP);
                    switch (key_code_3)
                    {
                    case 0x1D:
                        move_box_selector(UP);
                        break;
                    case 0xF0: ;
                        int key_code_temp = *ps2_ptr & 0x000000FF;
                        if(key_code_temp == 0x1D){
                            ; // To clear PS/2 FIFO of any further 0x1D keycodes
                        }
                        break;
                    default:
                        break;
                    }
                    break;
                    
                case 0xF0:
                    if(key_code_3 == 0x1D){
                        ; // Stop checking directions and exit all switch statements
                    }
                    break;
                
                default:
                    break;
                }

                break;
            
            // DOWN ANIMATION    
            case 0x1B:
                move_box_selector(DOWN);
                switch (key_code_2)
                {
                case 0x1B:
                    move_box_selector(DOWN);
                    switch (key_code_3)
                    {
                    case 0x1B:
                        move_box_selector(DOWN);
                        break;
                    case 0xF0: ;
                        int key_code_temp = *ps2_ptr & 0x000000FF;
                        if(key_code_temp == 0x1B){
                            ; // To clear PS/2 FIFO of any further 0x1B key codes
                        }
                        break;
                    default:
                        break;
                    }
                    break;

                case 0xF0:
                    if(key_code_3 == 0x1B){
                        ; // Stop checking directions and exit all switch statements
                    }
                    break;
                
                default:
                    break;
                }

                break;

            // LEFT ANIMATION
            case 0x1C:
                move_box_selector(LEFT);
                switch (key_code_2)
                {
                case 0x1C:
                    move_box_selector(LEFT);
                    switch (key_code_3)
                    {
                    case 0x1C:
                        move_box_selector(LEFT);
                        break;
                    case 0xF0: ;
                        int key_code_temp = *ps2_ptr & 0x000000FF;
                        if(key_code_temp == 0x1C){
                            ; // To clear PS/2 FIFO of any further 0x1C key codes
                        }
                        break;
                    default:
                        break;
                    }
                    break;

                case 0xF0:
                    if(key_code_3 == 0x1C){
                        ; // Stop checking directions and exit all switch statements
                    }
                    break;
                
                default:
                    break;
                }

                break;

            // RIGHT ANIMATION
            case 0x23:
                move_box_selector(RIGHT);
                switch (key_code_2)
                {
                case 0x23:
                    move_box_selector(RIGHT);
                    switch (key_code_3)
                    {
                    case 0x23:
                        move_box_selector(RIGHT);
                        break;
                    case 0xF0: ;
                        int key_code_temp = *ps2_ptr & 0x000000FF;
                        if(key_code_temp == 0x23){
                            ; // To clear PS/2 FIFO of any further 0x23 key codes
                        }
                        break;
                    default:
                        break;
                    }
                    break;

                case 0xF0:
                    if(key_code_3 == 0x23){
                        ; // Stop checking directions and exit all switch statements
                    }
                    break;
                
                default:
                    break;
                }

                break;
            
            // None of the reserved keyboard keys were pressed
            default:
                break;
            }
        }

        break;
    
    default:
        break;
    }
        
    // possible clear_ps2_fifo but would need to change some returns to breaks were necessary
    // return
    
}

void interval_timer_ISR(void){
    *(interval_timer_ptr) = 0;

    timeRemaining -= 1;

    draw_timer(timeRemaining, 1); // Clear current time
    draw_timer(timeRemaining, 0); // Draw updated time

    wait_for_vsync();
    pixel_buffer_start = *(pixel_ctrl_ptr + 1);

    if(timeRemaining == 0 && (playerScore < targetScore)){
        draw_screen(loser_screen);
        wait_for_vsync();
        pixel_buffer_start = *(pixel_ctrl_ptr + 1);

        // delay loop, a billion or trillion will do

        draw_screen(crdeits_screen); // Should be an animation

        draw_screen(start_screen);
        wait_for_vsync();
        pixel_buffer_start = *(pixel_ctrl_ptr + 1);

        pause = 0;

        return;
    }else if (timeRemaining == 0){
        draw_screen(winner_screen);
        wait_for_vsync();
        pixel_buffer_start = *(pixel_ctrl_ptr + 1);

        // delay loop, a billion or trillion will do

        draw_screen(crdeits_screen); // Should be an animation

        draw_screen(start_screen);
        wait_for_vsync();
        pixel_buffer_start = *(pixel_ctrl_ptr + 1);

        pause = 0;

        return;
    }else{
        return;
    }
    
}