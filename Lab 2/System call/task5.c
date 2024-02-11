#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        printf("2. Child process ID: %d\n", getpid());
        pid_t gcpids;
        for (int i = 0; i < 3; i++) {
            gcpids = fork();
            wait(NULL);
            if (gcpids == 0) {
                printf("%d. Grand Child process ID: %d\n", i+3, getpid());
                _exit(0);
            }
        }
        _exit(0);
     }
     else if (pid > 0) {
        printf("1. Parent process ID: %d\n", getpid());
        wait(NULL);
}
    return 0;
}

