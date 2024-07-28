//2024.03.30.AE -> Original Version

//Author: Arnold Etta


#include <stdio.h>
#include <stdbool.h>

int main() {
    // Define boolean variables
    bool isRaining = true;
    bool isSunny = false;

    // Print the values of boolean variables
    printf("Is it raining? %s\n", isRaining ? "Yes" : "No");
    printf("Is it sunny? %s\n", isSunny ? "Yes" : "No");

    // Change the values of boolean variables
    isRaining = false;
    isSunny = true;

    // Print the updated values
    printf("Is it raining now? %s\n", isRaining ? "Yes" : "No");
    printf("Is it sunny now? %s\n", isSunny ? "Yes" : "No");

    return 0;
}
