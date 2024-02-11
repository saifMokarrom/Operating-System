#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char input[1000];
    file = fopen(argv[1], "a+");
    while (1) {
        fgets(input, 1000, stdin);
        if (strcmp(input, "-1\n") == 0) {
            break;
        }
        fputs(input, file);
    }

    fclose(file);
    return 0;
}

