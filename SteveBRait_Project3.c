// Steve Brait
// 06/21/2026
// CYBF 350
// menu student grade manager that uses changeable memory and stays memory safe

#include <stdio.h>  
#include <stdlib.h>     


int max_students = 5; // the global max student variable in integer form

// float pointer because grades is going to be an array of floats
void view_grades(float *grades, int count) {
    int i;          // Loop index variable

    // nothing entered yet
    if (count == 0) {
        printf("No grades stored yet.\n");
        return; // return nothing if no grades are stored yet and obvi print no grades stored yet
    }

    // for if that iterates through the array and prints each grade
    for (i = 0; i < count; i++) {
        printf("Student %d: %.2f\n", i, grades[i]); // oh the %d is for the int index and the %.2f is for the hundredths float grade yeah thats it
    }
}

// add up the grades and return the average using local variables only
float calculate_average(float *grades, int count) {
    int i;              // loop index variable local bad boy
    float sum = 0.0;    // running total local 

    // if empty return value int / float
    if (count == 0) {
        return 0.0;
    }

    // total every grade / iterate through
    for (i = 0; i < count; i++) {
        sum = sum + grades[i];
    }

    
    return sum / count; // divide the total by sum
}


float *expand_capacity(float *grades, int *capacity) { // pointers to arrays going to be passed
    int new_capacity = (*capacity) * 2;     // double the room so we have floating bad boy numbahs
    float *temp;                            // temp pointer in float data type because i got an error

  
    temp = realloc(grades, new_capacity * sizeof(float)); // the baddest boy ( the realloc function that allows us to resize the array)

    // realloc failed, keep the original pointed value and bail
    if (temp == NULL) {
        printf("Could not expand capacity. Keeping current size.\n");
        return grades;
    }


    grades = temp;
    *capacity = new_capacity;
    printf("Capacity expanded to %d students.\n", new_capacity);
    return grades;     // resize worked return those gradez
}

// runs the menu and handles all the memories
int main(void) {
    float *grades;          // pointer the live grades array
    float *backup;          // pointer to the previous calloc
    int capacity;           // current size students
    int count = 0;          // int variable to set count of students, basically how many are actually in there right now not the max
    int choice;             // menu pick
    float new_grade;        // grade being added within the main function
    float average;          // sum variable main

    
    grades = malloc(max_students * sizeof(float)); // we need the malloc here to allocate memory for the grades array, yeah it grabs room for max_students floats up front

    if (grades == NULL) { // if the malloc fails, print 'memory allocation failed' and return 1
        printf("Memory allocation failed.\n");
        return 1;
    }
    capacity = max_students; // nah nvm this ones local, max_students is the only global bad boy


    backup = calloc(max_students, sizeof(float)); // we use calloc with sizeof and array size for backup

    if (backup == NULL) { // if the calloc fails, print 'memory allocation failed' and return 1
        printf("Memory allocation failed.\n");
        free(grades);
        return 1;
    }

    
    while (1) {  // this keeps showing the menu until the user exits because 1 is a redundant boolean value that is easy to keep a lock on a menu loop until its not 1 or break
        printf("\n Student Grade Manager\n");
        printf("1. Add student grade\n");
        printf("2. View all grades\n");
        printf("3. Calculate average grade\n");
        printf("4. Expand student capacity\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice); // user input function for choice variable value

       
        if (choice == 1) {  // add a studentgrade
    
            if (count == capacity) { // meaning the stored grades equal the current capacity of the array, not max students
                printf("Array is full. Use option 4 to expand capacity first.\n");
            } else {
                printf("Enter grade: ");
                scanf("%f", &new_grade); // %f for float grade and & value for new_grade variable
                grades[count] = new_grade; // count is the index of the grades array and new_grade is the value being added to the index
                count++; // increment the count by 1 to move to the next index input 
                printf("Grade added.\n");
            }
        }
        
        else if (choice == 2) {
            view_grades(grades, count); // view all grades
   
        }
        else if (choice == 3) {      
            average = calculate_average(grades, count);
            printf("Average grade: %.2f\n", average); // average the grades
        }

        else if (choice == 4) {         
            grades = expand_capacity(grades,&capacity); // grow the array & cap value pass by reference
        }
        
        else if (choice == 5) { // free everything and quit
            free(grades);
            free(backup);
            grades = NULL;      // avoid using freed or no memory 
            backup = NULL;
            printf("Memory freed. Goodbye.\n");
            break;
        }
        
        else {
            printf("Invalid choice. Pick 1 through 5.\n"); // anything other value catch block error will reroute player to menu choices again
        }
    }

    return 0;
}
