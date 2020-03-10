// Copyright 2020 Tobias Hueldau. All Rights Reserved.
// SPDX-License-Identifier: MIT
#include <unistd.h>

#ifdef DEBUG
#include <stdio.h>
#endif

// str2uint - parses string into unsigned integer
// Arguments:
//  str: The string to be parsed. Pointer to null terminated string.
//  return_value: Pointer to unsigned int to store the result in.
// Returns the following errors:
//  0: No error
//  1: String empty
//  2: String contains other characters than 0-9
//  3: Value too large for unsigned int
int str2uint(const char *str, unsigned *return_value) {
    unsigned number = 0;
    unsigned n = 0;
    int length;
    int i;
    unsigned tens = 1;

    //get length of input string
    for (length = 0; str[length] != '\0'; length++);
    
    //return error if input string is empty
    if (length == 0) {
        return 1;
    }

    //parse string from end to beginning
    for (i = 1; i <= length; i++) {
	//convert character to integer
	//48 is ASCII code of character '0'
        int digit = str[length - i] - 48;

	//return error if character was not within 0-9
        if (digit < 0 || digit > 9) {
            return 2;
        } 
        n = number + (tens*digit);
        
	//return error if roll-over occured
	//ie. value is too big for unsigned int
	if (n < number) {
            return 3;
        } else { 
            number = n; 
        }

	//advance decimal place
        tens = tens * 10;
    }
    *return_value = number;
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc == 2) {

	//convert first argument to integer
        unsigned seconds = 0;
        int error = str2uint(argv[1],&seconds);

        switch (error)
        {
            case 0:
                #ifdef DEBUG
		printf("Sleeping %u seconds.\n", seconds);
		#endif
                sleep(seconds);
                return 0;
                break;
            case 3:
                write(1,"Argument too large, max value is 4294967295.\n",45);
                break;
            default:
                write(1,"Error parsing argument, must be positive integer.\n",50);
        }
        return 1;
    }
    write(1,"Usage: sleep <seconds>\n",23);
    return 1;
}
