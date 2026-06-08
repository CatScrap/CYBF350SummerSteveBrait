
// Steve Brait
// 06/07/2026
// CYBF 350

// This program collects the user's name, age, and GPA, displays a formatted summary of that information, and calculates what the user's age will be in five years.

#include <stdio.h>


// main runs the program, gets the input, does the math, and prints the summary
int main(void) {
    char name[50];   // the user's name
    int age;         // the user's age in years
    float gpa;       // the user's GPA
    int futureAge;   // the user's age in five years

    // greet the user
    printf("Welcome to my C program!\n");

    // ask for the user's name, uses scanf to initiate input scanning from input, and %s is the input as a string, and 'name' is the variable to store the input in
    printf("Enter your name: ");
    scanf("%s", name);

    // ask for the user's age
    printf("Enter your age: ");
    scanf("%d", &age);

    // ask for the user's GPA, we use %f for float input, and the '&' is used to concatenate the variable 'gpa' to the scanf function so it knows where to store the input value
    printf("Enter your GPA: ");
    scanf("%f", &gpa);

    // add five years to the user's age
    futureAge = age + 5;

    // print the summary back to the user
    printf("\n User Summary \n");
    printf("Name:\t%s\n", name);
    printf("Age:\t%d\n", age);
    printf("GPA:\t%.2f\n", gpa);
    printf("In 5 years, you will be %d years old.\n", futureAge);

    return 0;
}
