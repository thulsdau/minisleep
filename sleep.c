#include <stdio.h>
#include <unistd.h>

unsigned str2u(const char *str, int *error) {
    unsigned number = 0;
    unsigned n = 0;
    int length;
    int i;
    unsigned tens = 1;

    *error = 0;
    for (length = 0; str[length] != '\0'; length++);
    if (length == 0) {
        *error = 1;
        return 0;
    }
    for (i = 1; i <= length; i++) {
        int digit = str[length - i] - 48;
        if (digit < 0 || digit > 9) {
            *error = 2;
            return 0;
        } 
        n = number + (tens*digit);
        if (n < number) {
            *error = 3;
            return 0;
        } else { 
            number = n; 
        }
        tens = tens * 10;
    }
    return number;
}

int main(int argc, char *argv[]) {
    if (argc == 2) {
        int error = 0;
        unsigned seconds = str2u(argv[1],&error);
        switch (error)
        {
            case 0:
                // printf("Sleeping %u seconds.\n", seconds);
                sleep(seconds);
                return 0;
                break;
            case 3:
                printf("Argument too large, max value is %u.\n",(unsigned) -1);
                break;
            default:
                printf("Error parsing argument, must be positive integer.\n");
        }
        return 1;
    }
    printf("Usage: %s <seconds>\n",argv[0]);
    return 1;
}