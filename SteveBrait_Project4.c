// Steve Brait
// 06/26/2026
// CYBF 350
// embedded temperature monitoring system that validates each sensor reading before it does anything with it

#include <stdio.h>


// main runs the whole thing, grabs the temp, checks if its even legit, then reacts
int main(void) {
    float temperature;   // the temperature reading in celsius the user types in, float cuz we have decimal points
    char again;          // the Y or N answer for whether we loop again in char but str not needed since one value one char

    // do-while because we always want to run at least once before we ask to repeat
    do {
        // ask for the sensor reading
        printf("Enter a temperature reading in degrees Celsius: ");
        scanf("%f", &temperature); // %f for the float temp and '&' so scanf knows the value

        // validate FIRST dont trust the reading until we know its in range
        if (temperature < -40.0 || temperature > 125.0) { // or comparitor below neg 40 above 125 
            // if outside the -40 to 125 range so its garbage, bail before doing any processing
            printf("Error: Invalid sensor reading.\n");
        } else { // reading is legit so now we can actually use it

            printf("Temperature entered: %.2f degrees Celsius.\n", temperature); // %.2f to keep it at the hundredths

            if (temperature >= 30.0) {
                printf("Cooling system: ON.\n");
            }
 
            else if (temperature <= 15.0) {
                printf("Heating system: ON.\n");
            }
            // anything between 15 and 30 is the happy zone
            else {
                printf("System operating normally.\n");
            }
        }

        // ask if they want to go again
        printf("Would you like to enter another temperature? (Y or N): ");
        scanf(" %c", &again); // space before %c so it skips the leftover newline hanging around in the buffer, that bad boy ruins everything otherwise as it checks the value of the y or n char

    } while (again == 'Y' || again == 'y'); // keep looping while they say Y, accept lowercase too cause people dont read

    // they said anything other than Y so we are done
    printf("Shutting down temperature monitor. Goodbye.\n");

    return 0;
}
