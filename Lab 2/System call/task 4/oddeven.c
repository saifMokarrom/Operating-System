#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
int num;
for (int i = 1; i < argc; i++) {
    num = atoi(argv[i]);
    if (num % 2 == 0)
        printf("%d itseven\n", num);

    else
        printf("%d it's odd\n", num);
}
return 0;
}

