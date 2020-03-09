#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc == 2) {
        char *tail;
        errno = 0;
        unsigned long seconds = strtoul(argv[1], &tail,10);
        if (errno == 0 && tail[0] == 0 && argv[1][0] != '-') {
            sleep(seconds);
            return 0;
        } else {
            printf("Error parsing argument, must be positive integer.\n");
        }
    }
    printf("Usage: %s <seconds>\n",argv[0]);
    return 1;
}