//Parent Code: general_hex_debugger.c

//2024.03.27.AE -> Modified Version (Original)

//Author: Arnold Etta


/*Function Declarations*/
int hex_decoder(int data_4bit);
int sw_off_hex(int hex_num);

/*Definitions & Global Declarations*/
#define ADDR_7SEG_REG1 ((volatile long *) 0xFF200020)
#define ADDR_7SEG_REG2 ((volatile long *) 0xFF200030)
//Modified:
#define PS2_BASE ((volatile long *) 0xFF200100)
	
int main()
{	
	int data_16bit = 0x0;
	
	int data_4bit_0, data_4bit_1, data_4bit_2, data_4bit_3;
	
	int hex0_data, hex1_data, hex2_data, hex3_data;
	
	int hex_datareg_1 = 0x0, hex_datareg_2 = 0x0;
	
	int PS2_Data;
	
	int RVALID, i = 0;
	
	int code0_1byte = 0x00, code1_1byte = 0x00;
	
	while(i==0){

		PS2_Data = *PS2_BASE & 0x000080FF; //Read from PS_2 data register
		
		RVALID = PS2_Data & 0x00008000; //Extract bit 15 of Data Register
		
		//Capture last 2 keycodes from PS/2 port FIFO
		code0_1byte = code1_1byte;
		code1_1byte = PS2_Data & 0x000000FF; //Extract bits 7 - 0 (1 byte key code)
		
		if(RVALID!=0){
			//16 bit data (of the form 0x####) to be displayed on HEX3 to HEX0
			data_16bit = code0_1byte;
			data_16bit = (data_16bit<<8) + code1_1byte;

			//Split 16 bit Data into 4 chunks of 4 bit data
			data_4bit_0 = data_16bit & 0x000F;
			data_4bit_1 = (data_16bit & 0x00F0) >> 4;
			data_4bit_2 = (data_16bit & 0x0F00) >> 8;
			data_4bit_3 = (data_16bit & 0xF000) >> 12;

			//Decoder - Takes in 4 bits (0x0-0xF) and returns 7 bits
			hex0_data = hex_decoder(data_4bit_0);
			hex1_data = hex_decoder(data_4bit_1);
			hex2_data = hex_decoder(data_4bit_2);
			hex3_data = hex_decoder(data_4bit_3);

			//Arrange HEX data bits into data register appropriately
			hex_datareg_1 = hex3_data;
			hex_datareg_1 = (hex_datareg_1 << 8) + hex2_data;
			hex_datareg_1 = (hex_datareg_1 << 8) + hex1_data;
			hex_datareg_1 = (hex_datareg_1 << 8) + hex0_data;

			// Activate respective segments in each HEX display 
			*ADDR_7SEG_REG1 = hex_datareg_1 & sw_off_hex(4); 
			*ADDR_7SEG_REG2 = hex_datareg_2;
		}
		//i++;
	}
	
	//while(1){
	//	i = i+0.1;
	//}
}

/*****************************************************************
 Additional Functionalities:
	1.	To turn off a hex display, perform an '&' (and) operation
		with data variable 'hex_datareg_1' and the function 
		'sw_off_hex'. The function takes in the '#' number
		in HEX# to turn off HEX#.
			
		-> For example,
				*ADDR_7SEG_REG1 = hex_datareg_1 & sw_off_hex(0);
		   turns off the HEX0 display.
			
	2.	To turn off multiple hex diplays, simply perform the (and)
		operation multiple times.
			
		-> For example,
				hex_datareg_1 & sw_off_hex(0) & sw_off_hex(1)
		   turns off both the HEX0 and HEX1 displays.
******************************************************************/

/* Function Implementations */
int hex_decoder(int data_4bit)
{
	switch(data_4bit){
		case 0x0:
			return 0x3F;
		case 0x1:
			return 0x06;
		case 0x2:
			return 0x5B;
		case 0x3:
			return 0x4F;
		case 0x4:
			return 0x66;
		case 0x5:
			return 0x6D;
		case 0x6:
			return 0x7D;
		case 0x7:
			return 0x07;
		case 0x8:
			return 0x7F;
		case 0x9:
			return 0x6F;
		case 0xA:
			return 0x77;
		case 0xb:
			return 0x7C;
		case 0xC:
			return 0x39;
		case 0xd:
			return 0x5E;
		case 0xE:
			return 0x79;
		case 0xF:
			return 0x71;
	}
}

int sw_off_hex(int hex_num)
{
	switch(hex_num){
		case 0:
			return 0xFFFFFF00;
		case 1:
			return 0xFFFF00FF;
		case 2:
			return 0xFF00FFFF;
		case 3:
			return 0x00FFFFFF;
		default:
			return 0xFFFFFFFF;
	}
}