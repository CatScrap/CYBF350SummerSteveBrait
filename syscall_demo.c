// Steve Brait
// 06/14/2026
// CYBF 350

#include <unistd.h>     // write, read, getpid library header for requirements
#include <sys/types.h>  // pid_t type requirement 

// turn a number into text so write can print it
int int_to_str(int value, char *buffer) {
    int length = 0;     // digit count
    char temp[20];      // digits in reverse
    int i = 0;          // temp index

    // zero special case
    if (value == 0) {
        buffer[0] = '0';
        return 1;
    }

    // pull digits off, lowest first
    while (value > 0) {
        temp[i] = '0' + (value % 10);
        value = value / 10;
        i++;
    }

    // flip them back around
    while (i > 0) {
        i--;
        buffer[length] = temp[i];
        length++;
    }

    return length;
}

// runs the program
int main(void) {
    char name[100];     // the user's name
    char pidText[20];   // pid as text
    int nameLength;     // bytes read for the name
    int pidLength;      // length of the pid text
    pid_t pid;          // this program's process id

    // welcome message
    char welcome[] = "Welcome to my system call program!\n";
    write(1, welcome, sizeof(welcome) - 1);

    // prompt for the name
    char askName[] = "Enter your name: ";
    write(1, askName, sizeof(askName) - 1);

    // read() takes the input as name from the keyboard
    nameLength = read(0, name, sizeof(name) - 1);

    // start the greeting
    char greeting[] = "Hello, ";
    write(1, greeting, sizeof(greeting) - 1);

    // write() sends the name to the screen
    write(1, name, nameLength);

    // finish greeting line
    char greetingEnd[] = "! Nice to meet you.\n";
    write(1, greetingEnd, sizeof(greetingEnd) - 1);

    // getpid() gets this program's process id
    pid = getpid();

    // label for the pid
    char pidLabel[] = "Your process ID (PID) is: ";
    write(1, pidLabel, sizeof(pidLabel) - 1);

    // turn the pid into text and write() it
    pidLength = int_to_str(pid, pidText);
    write(1, pidText, pidLength);

    return 0;
}
