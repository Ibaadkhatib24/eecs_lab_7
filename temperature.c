#include <stdio.h>

//  conversion functions
float to_fahrenheit(float celsius) { return (celsius * 9 / 5) + 32; }  // converts C to F
float to_celsius_from_fahrenheit(float fahrenheit) { return (fahrenheit - 32) * 5 / 9; }  // F to C
float to_kelvin(float celsius) { return celsius + 273.15; }  // C to K
float to_celsius_from_kelvin(float kelvin) { return kelvin - 273.15; }  // K to C

// gives weather advice based on temp
void temperature_advisory(float celsius) {
    if (celsius < 0) printf("t's cold wear layers!\n");
    else if (celsius < 10) printf("a jacket would be wise.\n");  
    else if (celsius < 25) printf("perfectly pleasant weather\n");  
    else if (celsius < 35) printf("stay cool and hydrated.\n"); 
    else printf(" extreme heat warning, stay safe indoors.\n");  
}

int main() {
    float temp, converted_temp;
    int current_scale, target_scale;

    // get user input
    printf("what temperature you'd like to convert? ");  // ask user for the temp
    scanf("%f", &temp);

    printf("Pick the current scale: (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");  // the current unit u chose to start with
    scanf("%d", &current_scale);

    printf("Convert to: (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");  // what unit to change it to 
    scanf("%d", &target_scale);

    // do the conversion based on user choices
    if (current_scale == 1 && target_scale == 2)
        converted_temp = to_fahrenheit(temp);  // C to F logic
    else if (current_scale == 1 && target_scale == 3)
        converted_temp = to_kelvin(temp);  // C to K logic
    else if (current_scale == 2 && target_scale == 1)
        converted_temp = to_celsius_from_fahrenheit(temp);  // F to C logic
    else if (current_scale == 3 && target_scale == 1)
        converted_temp = to_celsius_from_kelvin(temp);  // K to C  logic
    else {
        printf(" invalid choice\n");  // wring number error 
        return 0;
    }

    // prints the result
    printf("\nThe temperature after conversion: %.2f\n", converted_temp);

    // gives the weather advice convert to C 
    temperature_advisory(target_scale == 1 ? converted_temp : to_celsius_from_fahrenheit(converted_temp));

    return 0;
}