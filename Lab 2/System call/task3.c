#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


void check_odd(int pid, int *tot_process);



int main() {
    int a, b,c,tot_process = 1;

    a = fork();
    b = fork();
    c = fork();

    if (a == 0) {
        check_odd(getpid(), &tot_process);

    }
    else if (a > 0) {
        wait(NULL);
        tot_process++;
    }

    if (b == 0) {
        check_odd(getpid(), &tot_process);
    }
    else if (b > 0) {
        wait(NULL);
        tot_process++;
    }

    if (c == 0) {
        check_odd(getpid(), &tot_process);

    }
    else if (c > 0) {
        wait(NULL);
        tot_process++;
    }

    printf("Total processes created: %d\n", tot_process);

    return 0;
}


void check_odd(int pid, int *tot_process) {
    if (pid % 2 == 1) {
        int tmp = fork();
        if (tmp== 0 ||tmp % 2 == 1) {
            check_odd(getpid(), tot_process);
            exit(0);
        } else {
            wait(NULL);
            (*tot_process)++;
        }
    }
}

