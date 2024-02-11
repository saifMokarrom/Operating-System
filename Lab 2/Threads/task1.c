#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *run_thread(void *args);


int main() {
  pthread_t thread;
  for (int i = 1; i <= 5; i++) {
     pthread_create(&thread, NULL, run_thread, &i);
     sleep(1);
     pthread_join(thread, NULL);
  }

  return 0;
}

void *run_thread(void *args) {
    int num_thread = *((int *)args);
    printf("thread-%d running\n", num_thread);
    printf("thread-%d closed\n", num_thread);
    pthread_exit(NULL);
}

