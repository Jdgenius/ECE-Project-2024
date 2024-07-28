//2024.04.02.AE -> Added draw_screen function
//2024.03.31.AE -> Modified Version (added clear_screen() & draw_box functions)

//Author: UofT ECE243 Department
//Modified by Arnold Etta


#include "globals.h"

void plot_pixel(int x, int y, short int line_color){
    short int *one_pixel_address;    
    one_pixel_address = pixel_buffer_start + (y << 10) + (x << 1);
    *one_pixel_address = line_color;
}

void write_char(int x, int y, char c) {
    // VGA character buffer
    volatile char * character_buffer = (char *) (0x09000000 + (y<<7) + x);
    *character_buffer = c;
}

void draw_box(int x, int y, int x_size, int y_size, short int box_colour, bool fill){
    if(fill){
        // Draw filled box with colour box_colour
        for(int j = y; j < y + y_size; j++){
            for(int i = x; i < x + x_size; i++){
                plot_pixel(i, j, box_colour);
            }
        }
    }else{ // Draw empty box
        // Top line
        for(int i = x; i < x + x_size; i++){
            plot_pixel(i, y, box_colour);
        }

        // Bottom line
        for(int i = x; i < x + x_size; i++){
            plot_pixel(i, y + y_size, box_colour);
        }

        // Left line
        for(int j = y; j < y + y_size; j++){
            plot_pixel(x, j, box_colour);
        }

        // Right line
        for(int j = y; j < y + y_size; j++){
            plot_pixel(x + x_size, j, box_colour);
        }
    }
    
}

void draw_screen(const short int* screen_array){
    for(int y = 0; y < 240; y++){
        for(int x = 0; x < 320; x+=320){
            plot_pixel(x, y, screen_array[320*y + x]);
            //plot_pixel(0, y, screen_array[320*y + 0]); 
            plot_pixel(1, y, screen_array[320*y + 1]); 
            plot_pixel(2, y, screen_array[320*y + 2]); 
            plot_pixel(3, y, screen_array[320*y + 3]); 
            plot_pixel(4, y, screen_array[320*y + 4]); 
            plot_pixel(5, y, screen_array[320*y + 5]); 
            plot_pixel(6, y, screen_array[320*y + 6]); 
            plot_pixel(7, y, screen_array[320*y + 7]); 
            plot_pixel(8, y, screen_array[320*y + 8]); 
            plot_pixel(9, y, screen_array[320*y + 9]); 
            plot_pixel(10, y, screen_array[320*y + 10]); 
            plot_pixel(11, y, screen_array[320*y + 11]); 
            plot_pixel(12, y, screen_array[320*y + 12]); 
            plot_pixel(13, y, screen_array[320*y + 13]); 
            plot_pixel(14, y, screen_array[320*y + 14]); 
            plot_pixel(15, y, screen_array[320*y + 15]); 
            plot_pixel(16, y, screen_array[320*y + 16]); 
            plot_pixel(17, y, screen_array[320*y + 17]); 
            plot_pixel(18, y, screen_array[320*y + 18]); 
            plot_pixel(19, y, screen_array[320*y + 19]); 
            plot_pixel(20, y, screen_array[320*y + 20]); 
            plot_pixel(21, y, screen_array[320*y + 21]); 
            plot_pixel(22, y, screen_array[320*y + 22]); 
            plot_pixel(23, y, screen_array[320*y + 23]); 
            plot_pixel(24, y, screen_array[320*y + 24]); 
            plot_pixel(25, y, screen_array[320*y + 25]); 
            plot_pixel(26, y, screen_array[320*y + 26]); 
            plot_pixel(27, y, screen_array[320*y + 27]); 
            plot_pixel(28, y, screen_array[320*y + 28]); 
            plot_pixel(29, y, screen_array[320*y + 29]); 
            plot_pixel(30, y, screen_array[320*y + 30]); 
            plot_pixel(31, y, screen_array[320*y + 31]); 
            plot_pixel(32, y, screen_array[320*y + 32]); 
            plot_pixel(33, y, screen_array[320*y + 33]); 
            plot_pixel(34, y, screen_array[320*y + 34]); 
            plot_pixel(35, y, screen_array[320*y + 35]); 
            plot_pixel(36, y, screen_array[320*y + 36]); 
            plot_pixel(37, y, screen_array[320*y + 37]); 
            plot_pixel(38, y, screen_array[320*y + 38]); 
            plot_pixel(39, y, screen_array[320*y + 39]); 
            plot_pixel(40, y, screen_array[320*y + 40]); 
            plot_pixel(41, y, screen_array[320*y + 41]); 
            plot_pixel(42, y, screen_array[320*y + 42]); 
            plot_pixel(43, y, screen_array[320*y + 43]); 
            plot_pixel(44, y, screen_array[320*y + 44]); 
            plot_pixel(45, y, screen_array[320*y + 45]); 
            plot_pixel(46, y, screen_array[320*y + 46]); 
            plot_pixel(47, y, screen_array[320*y + 47]); 
            plot_pixel(48, y, screen_array[320*y + 48]); 
            plot_pixel(49, y, screen_array[320*y + 49]); 
            plot_pixel(50, y, screen_array[320*y + 50]); 
            plot_pixel(51, y, screen_array[320*y + 51]); 
            plot_pixel(52, y, screen_array[320*y + 52]); 
            plot_pixel(53, y, screen_array[320*y + 53]); 
            plot_pixel(54, y, screen_array[320*y + 54]); 
            plot_pixel(55, y, screen_array[320*y + 55]); 
            plot_pixel(56, y, screen_array[320*y + 56]); 
            plot_pixel(57, y, screen_array[320*y + 57]); 
            plot_pixel(58, y, screen_array[320*y + 58]); 
            plot_pixel(59, y, screen_array[320*y + 59]); 
            plot_pixel(60, y, screen_array[320*y + 60]); 
            plot_pixel(61, y, screen_array[320*y + 61]); 
            plot_pixel(62, y, screen_array[320*y + 62]); 
            plot_pixel(63, y, screen_array[320*y + 63]); 
            plot_pixel(64, y, screen_array[320*y + 64]); 
            plot_pixel(65, y, screen_array[320*y + 65]); 
            plot_pixel(66, y, screen_array[320*y + 66]); 
            plot_pixel(67, y, screen_array[320*y + 67]); 
            plot_pixel(68, y, screen_array[320*y + 68]); 
            plot_pixel(69, y, screen_array[320*y + 69]); 
            plot_pixel(70, y, screen_array[320*y + 70]); 
            plot_pixel(71, y, screen_array[320*y + 71]); 
            plot_pixel(72, y, screen_array[320*y + 72]); 
            plot_pixel(73, y, screen_array[320*y + 73]); 
            plot_pixel(74, y, screen_array[320*y + 74]); 
            plot_pixel(75, y, screen_array[320*y + 75]); 
            plot_pixel(76, y, screen_array[320*y + 76]); 
            plot_pixel(77, y, screen_array[320*y + 77]); 
            plot_pixel(78, y, screen_array[320*y + 78]); 
            plot_pixel(79, y, screen_array[320*y + 79]); 
            plot_pixel(80, y, screen_array[320*y + 80]); 
            plot_pixel(81, y, screen_array[320*y + 81]); 
            plot_pixel(82, y, screen_array[320*y + 82]); 
            plot_pixel(83, y, screen_array[320*y + 83]); 
            plot_pixel(84, y, screen_array[320*y + 84]); 
            plot_pixel(85, y, screen_array[320*y + 85]); 
            plot_pixel(86, y, screen_array[320*y + 86]); 
            plot_pixel(87, y, screen_array[320*y + 87]); 
            plot_pixel(88, y, screen_array[320*y + 88]); 
            plot_pixel(89, y, screen_array[320*y + 89]); 
            plot_pixel(90, y, screen_array[320*y + 90]); 
            plot_pixel(91, y, screen_array[320*y + 91]); 
            plot_pixel(92, y, screen_array[320*y + 92]); 
            plot_pixel(93, y, screen_array[320*y + 93]); 
            plot_pixel(94, y, screen_array[320*y + 94]); 
            plot_pixel(95, y, screen_array[320*y + 95]); 
            plot_pixel(96, y, screen_array[320*y + 96]); 
            plot_pixel(97, y, screen_array[320*y + 97]); 
            plot_pixel(98, y, screen_array[320*y + 98]); 
            plot_pixel(99, y, screen_array[320*y + 99]); 
            plot_pixel(100, y, screen_array[320*y + 100]); 
            plot_pixel(101, y, screen_array[320*y + 101]); 
            plot_pixel(102, y, screen_array[320*y + 102]); 
            plot_pixel(103, y, screen_array[320*y + 103]); 
            plot_pixel(104, y, screen_array[320*y + 104]); 
            plot_pixel(105, y, screen_array[320*y + 105]); 
            plot_pixel(106, y, screen_array[320*y + 106]); 
            plot_pixel(107, y, screen_array[320*y + 107]); 
            plot_pixel(108, y, screen_array[320*y + 108]); 
            plot_pixel(109, y, screen_array[320*y + 109]); 
            plot_pixel(110, y, screen_array[320*y + 110]); 
            plot_pixel(111, y, screen_array[320*y + 111]); 
            plot_pixel(112, y, screen_array[320*y + 112]); 
            plot_pixel(113, y, screen_array[320*y + 113]); 
            plot_pixel(114, y, screen_array[320*y + 114]); 
            plot_pixel(115, y, screen_array[320*y + 115]); 
            plot_pixel(116, y, screen_array[320*y + 116]); 
            plot_pixel(117, y, screen_array[320*y + 117]); 
            plot_pixel(118, y, screen_array[320*y + 118]); 
            plot_pixel(119, y, screen_array[320*y + 119]); 
            plot_pixel(120, y, screen_array[320*y + 120]); 
            plot_pixel(121, y, screen_array[320*y + 121]); 
            plot_pixel(122, y, screen_array[320*y + 122]); 
            plot_pixel(123, y, screen_array[320*y + 123]); 
            plot_pixel(124, y, screen_array[320*y + 124]); 
            plot_pixel(125, y, screen_array[320*y + 125]); 
            plot_pixel(126, y, screen_array[320*y + 126]); 
            plot_pixel(127, y, screen_array[320*y + 127]); 
            plot_pixel(128, y, screen_array[320*y + 128]); 
            plot_pixel(129, y, screen_array[320*y + 129]); 
            plot_pixel(130, y, screen_array[320*y + 130]); 
            plot_pixel(131, y, screen_array[320*y + 131]); 
            plot_pixel(132, y, screen_array[320*y + 132]); 
            plot_pixel(133, y, screen_array[320*y + 133]); 
            plot_pixel(134, y, screen_array[320*y + 134]); 
            plot_pixel(135, y, screen_array[320*y + 135]); 
            plot_pixel(136, y, screen_array[320*y + 136]); 
            plot_pixel(137, y, screen_array[320*y + 137]); 
            plot_pixel(138, y, screen_array[320*y + 138]); 
            plot_pixel(139, y, screen_array[320*y + 139]); 
            plot_pixel(140, y, screen_array[320*y + 140]); 
            plot_pixel(141, y, screen_array[320*y + 141]); 
            plot_pixel(142, y, screen_array[320*y + 142]); 
            plot_pixel(143, y, screen_array[320*y + 143]); 
            plot_pixel(144, y, screen_array[320*y + 144]); 
            plot_pixel(145, y, screen_array[320*y + 145]); 
            plot_pixel(146, y, screen_array[320*y + 146]); 
            plot_pixel(147, y, screen_array[320*y + 147]); 
            plot_pixel(148, y, screen_array[320*y + 148]); 
            plot_pixel(149, y, screen_array[320*y + 149]); 
            plot_pixel(150, y, screen_array[320*y + 150]); 
            plot_pixel(151, y, screen_array[320*y + 151]); 
            plot_pixel(152, y, screen_array[320*y + 152]); 
            plot_pixel(153, y, screen_array[320*y + 153]); 
            plot_pixel(154, y, screen_array[320*y + 154]); 
            plot_pixel(155, y, screen_array[320*y + 155]); 
            plot_pixel(156, y, screen_array[320*y + 156]); 
            plot_pixel(157, y, screen_array[320*y + 157]); 
            plot_pixel(158, y, screen_array[320*y + 158]); 
            plot_pixel(159, y, screen_array[320*y + 159]); 
            plot_pixel(160, y, screen_array[320*y + 160]); 
            plot_pixel(161, y, screen_array[320*y + 161]); 
            plot_pixel(162, y, screen_array[320*y + 162]); 
            plot_pixel(163, y, screen_array[320*y + 163]); 
            plot_pixel(164, y, screen_array[320*y + 164]); 
            plot_pixel(165, y, screen_array[320*y + 165]); 
            plot_pixel(166, y, screen_array[320*y + 166]); 
            plot_pixel(167, y, screen_array[320*y + 167]); 
            plot_pixel(168, y, screen_array[320*y + 168]); 
            plot_pixel(169, y, screen_array[320*y + 169]); 
            plot_pixel(170, y, screen_array[320*y + 170]); 
            plot_pixel(171, y, screen_array[320*y + 171]); 
            plot_pixel(172, y, screen_array[320*y + 172]); 
            plot_pixel(173, y, screen_array[320*y + 173]); 
            plot_pixel(174, y, screen_array[320*y + 174]); 
            plot_pixel(175, y, screen_array[320*y + 175]); 
            plot_pixel(176, y, screen_array[320*y + 176]); 
            plot_pixel(177, y, screen_array[320*y + 177]); 
            plot_pixel(178, y, screen_array[320*y + 178]); 
            plot_pixel(179, y, screen_array[320*y + 179]); 
            plot_pixel(180, y, screen_array[320*y + 180]); 
            plot_pixel(181, y, screen_array[320*y + 181]); 
            plot_pixel(182, y, screen_array[320*y + 182]); 
            plot_pixel(183, y, screen_array[320*y + 183]); 
            plot_pixel(184, y, screen_array[320*y + 184]); 
            plot_pixel(185, y, screen_array[320*y + 185]); 
            plot_pixel(186, y, screen_array[320*y + 186]); 
            plot_pixel(187, y, screen_array[320*y + 187]); 
            plot_pixel(188, y, screen_array[320*y + 188]); 
            plot_pixel(189, y, screen_array[320*y + 189]); 
            plot_pixel(190, y, screen_array[320*y + 190]); 
            plot_pixel(191, y, screen_array[320*y + 191]); 
            plot_pixel(192, y, screen_array[320*y + 192]); 
            plot_pixel(193, y, screen_array[320*y + 193]); 
            plot_pixel(194, y, screen_array[320*y + 194]); 
            plot_pixel(195, y, screen_array[320*y + 195]); 
            plot_pixel(196, y, screen_array[320*y + 196]); 
            plot_pixel(197, y, screen_array[320*y + 197]); 
            plot_pixel(198, y, screen_array[320*y + 198]); 
            plot_pixel(199, y, screen_array[320*y + 199]); 
            plot_pixel(200, y, screen_array[320*y + 200]); 
            plot_pixel(201, y, screen_array[320*y + 201]); 
            plot_pixel(202, y, screen_array[320*y + 202]); 
            plot_pixel(203, y, screen_array[320*y + 203]); 
            plot_pixel(204, y, screen_array[320*y + 204]); 
            plot_pixel(205, y, screen_array[320*y + 205]); 
            plot_pixel(206, y, screen_array[320*y + 206]); 
            plot_pixel(207, y, screen_array[320*y + 207]); 
            plot_pixel(208, y, screen_array[320*y + 208]); 
            plot_pixel(209, y, screen_array[320*y + 209]); 
            plot_pixel(210, y, screen_array[320*y + 210]); 
            plot_pixel(211, y, screen_array[320*y + 211]); 
            plot_pixel(212, y, screen_array[320*y + 212]); 
            plot_pixel(213, y, screen_array[320*y + 213]); 
            plot_pixel(214, y, screen_array[320*y + 214]); 
            plot_pixel(215, y, screen_array[320*y + 215]); 
            plot_pixel(216, y, screen_array[320*y + 216]); 
            plot_pixel(217, y, screen_array[320*y + 217]); 
            plot_pixel(218, y, screen_array[320*y + 218]); 
            plot_pixel(219, y, screen_array[320*y + 219]); 
            plot_pixel(220, y, screen_array[320*y + 220]); 
            plot_pixel(221, y, screen_array[320*y + 221]); 
            plot_pixel(222, y, screen_array[320*y + 222]); 
            plot_pixel(223, y, screen_array[320*y + 223]); 
            plot_pixel(224, y, screen_array[320*y + 224]); 
            plot_pixel(225, y, screen_array[320*y + 225]); 
            plot_pixel(226, y, screen_array[320*y + 226]); 
            plot_pixel(227, y, screen_array[320*y + 227]); 
            plot_pixel(228, y, screen_array[320*y + 228]); 
            plot_pixel(229, y, screen_array[320*y + 229]); 
            plot_pixel(230, y, screen_array[320*y + 230]); 
            plot_pixel(231, y, screen_array[320*y + 231]); 
            plot_pixel(232, y, screen_array[320*y + 232]); 
            plot_pixel(233, y, screen_array[320*y + 233]); 
            plot_pixel(234, y, screen_array[320*y + 234]); 
            plot_pixel(235, y, screen_array[320*y + 235]); 
            plot_pixel(236, y, screen_array[320*y + 236]); 
            plot_pixel(237, y, screen_array[320*y + 237]); 
            plot_pixel(238, y, screen_array[320*y + 238]); 
            plot_pixel(239, y, screen_array[320*y + 239]); 
            plot_pixel(240, y, screen_array[320*y + 240]); 
            plot_pixel(241, y, screen_array[320*y + 241]); 
            plot_pixel(242, y, screen_array[320*y + 242]); 
            plot_pixel(243, y, screen_array[320*y + 243]); 
            plot_pixel(244, y, screen_array[320*y + 244]); 
            plot_pixel(245, y, screen_array[320*y + 245]); 
            plot_pixel(246, y, screen_array[320*y + 246]); 
            plot_pixel(247, y, screen_array[320*y + 247]); 
            plot_pixel(248, y, screen_array[320*y + 248]); 
            plot_pixel(249, y, screen_array[320*y + 249]); 
            plot_pixel(250, y, screen_array[320*y + 250]); 
            plot_pixel(251, y, screen_array[320*y + 251]); 
            plot_pixel(252, y, screen_array[320*y + 252]); 
            plot_pixel(253, y, screen_array[320*y + 253]); 
            plot_pixel(254, y, screen_array[320*y + 254]); 
            plot_pixel(255, y, screen_array[320*y + 255]); 
            plot_pixel(256, y, screen_array[320*y + 256]); 
            plot_pixel(257, y, screen_array[320*y + 257]); 
            plot_pixel(258, y, screen_array[320*y + 258]); 
            plot_pixel(259, y, screen_array[320*y + 259]); 
            plot_pixel(260, y, screen_array[320*y + 260]); 
            plot_pixel(261, y, screen_array[320*y + 261]); 
            plot_pixel(262, y, screen_array[320*y + 262]); 
            plot_pixel(263, y, screen_array[320*y + 263]); 
            plot_pixel(264, y, screen_array[320*y + 264]); 
            plot_pixel(265, y, screen_array[320*y + 265]); 
            plot_pixel(266, y, screen_array[320*y + 266]); 
            plot_pixel(267, y, screen_array[320*y + 267]); 
            plot_pixel(268, y, screen_array[320*y + 268]); 
            plot_pixel(269, y, screen_array[320*y + 269]); 
            plot_pixel(270, y, screen_array[320*y + 270]); 
            plot_pixel(271, y, screen_array[320*y + 271]); 
            plot_pixel(272, y, screen_array[320*y + 272]); 
            plot_pixel(273, y, screen_array[320*y + 273]); 
            plot_pixel(274, y, screen_array[320*y + 274]); 
            plot_pixel(275, y, screen_array[320*y + 275]); 
            plot_pixel(276, y, screen_array[320*y + 276]); 
            plot_pixel(277, y, screen_array[320*y + 277]); 
            plot_pixel(278, y, screen_array[320*y + 278]); 
            plot_pixel(279, y, screen_array[320*y + 279]); 
            plot_pixel(280, y, screen_array[320*y + 280]); 
            plot_pixel(281, y, screen_array[320*y + 281]); 
            plot_pixel(282, y, screen_array[320*y + 282]); 
            plot_pixel(283, y, screen_array[320*y + 283]); 
            plot_pixel(284, y, screen_array[320*y + 284]); 
            plot_pixel(285, y, screen_array[320*y + 285]); 
            plot_pixel(286, y, screen_array[320*y + 286]); 
            plot_pixel(287, y, screen_array[320*y + 287]); 
            plot_pixel(288, y, screen_array[320*y + 288]); 
            plot_pixel(289, y, screen_array[320*y + 289]); 
            plot_pixel(290, y, screen_array[320*y + 290]); 
            plot_pixel(291, y, screen_array[320*y + 291]); 
            plot_pixel(292, y, screen_array[320*y + 292]); 
            plot_pixel(293, y, screen_array[320*y + 293]); 
            plot_pixel(294, y, screen_array[320*y + 294]); 
            plot_pixel(295, y, screen_array[320*y + 295]); 
            plot_pixel(296, y, screen_array[320*y + 296]); 
            plot_pixel(297, y, screen_array[320*y + 297]); 
            plot_pixel(298, y, screen_array[320*y + 298]); 
            plot_pixel(299, y, screen_array[320*y + 299]); 
            plot_pixel(300, y, screen_array[320*y + 300]); 
            plot_pixel(301, y, screen_array[320*y + 301]); 
            plot_pixel(302, y, screen_array[320*y + 302]); 
            plot_pixel(303, y, screen_array[320*y + 303]); 
            plot_pixel(304, y, screen_array[320*y + 304]); 
            plot_pixel(305, y, screen_array[320*y + 305]); 
            plot_pixel(306, y, screen_array[320*y + 306]); 
            plot_pixel(307, y, screen_array[320*y + 307]); 
            plot_pixel(308, y, screen_array[320*y + 308]); 
            plot_pixel(309, y, screen_array[320*y + 309]); 
            plot_pixel(310, y, screen_array[320*y + 310]); 
            plot_pixel(311, y, screen_array[320*y + 311]); 
            plot_pixel(312, y, screen_array[320*y + 312]); 
            plot_pixel(313, y, screen_array[320*y + 313]); 
            plot_pixel(314, y, screen_array[320*y + 314]); 
            plot_pixel(315, y, screen_array[320*y + 315]); 
            plot_pixel(316, y, screen_array[320*y + 316]); 
            plot_pixel(317, y, screen_array[320*y + 317]); 
            plot_pixel(318, y, screen_array[320*y + 318]); 
            plot_pixel(319, y, screen_array[320*y + 319]);
        }
    }
}

void clear_screen(void){
    for(int y = 0; y < 240; y++){
        for(int x = 0; x < 320; x++){
            plot_pixel(x, y, 0);
        }
    }	
}

void wait_for_vsync(void){
	int status;
	
	*pixel_ctrl_ptr = 1;
	
	status = *(pixel_ctrl_ptr + 3);
	
	while( (status&0x01) != 0 ){
		status = *(pixel_ctrl_ptr + 3);
	}
	printf("Done swap");
}