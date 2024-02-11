#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t a;
    a = fork();
    if (a == 0) {

        pid_t gchild = fork();
        if (gchild == 0) {
            printf("I am grandchild\n");
        }
        else {
            wait(NULL);
            printf("I am child\n");
        }
    }
    else {
        wait(NULL);
        printf("I am parent\n");
    }
    return 0;
}

/*I add wait(Null), for this parent process will wait for its child to complete and child process will wait for the grand child to complet"
