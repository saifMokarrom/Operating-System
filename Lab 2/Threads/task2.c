#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *run_thread(void *args);

int start_thread = 0;


int main() {
    for (int i=0;i<5;i++ ){
    pthread_t thread;
    pthread_create(&thread, NULL, run_thread, NULL);
    pthread_join(thread, NULL);
    start_thread++;
}
return 0;
}



void *run_thread(void *args) {
   int total_thread = 5;
   for (int i = 1; i <= 5; i++) {
   printf("thread %d prints %d\n", start_thread, (start_thread * total_thread)+i);
   //I used this (start_thread * total_thread)+i formula to print the integers,
}

}

