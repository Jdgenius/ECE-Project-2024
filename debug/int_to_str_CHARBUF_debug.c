//2024.03.31.AE -> Original Version

//Author: Arnold Etta


#include <stdio.h>

int main() {
    int num = 12345;
    char str[20]; // Make sure the array is large enough to hold the string representation of the integer
	
	while(num > 0){
		// Convert integer to string
    	sprintf(str, "%d", num);
		
		// Time Delay
		for(int i = 0; i<50000; i++){
			continue;
		}
		
		// Print the string
		printf("String representation of %d: %s\n", num, str);
		
		//Decrement num by 1 and repeat process till num = 0
		num -= 1;
	}

    return 0;
}
