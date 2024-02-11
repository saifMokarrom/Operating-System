#include <pthread.h>
#include <stdio.h>
#include <string.h>
#define MAX 10 //producers and consumers can produce and consume upto MAX
#define BUFLEN 6
#define NUMTHREAD 2      /* number of threads */
void * consumer(int *id);
void * producer(int *id);

char buffer[BUFLEN];
char source[BUFLEN]; //from this array producer will store it's production into buffer
int pCount = 0;
int cCount = 0;
int buflen;

//initializing pthread mutex and condition variables
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t nonEmpty  = PTHREAD_COND_INITIALIZER;
pthread_cond_t full  = PTHREAD_COND_INITIALIZER;
int thread_id[NUMTHREAD]  = {0,1};
int i = 0;
int j = 0;

int main() {

    pthread_t thread[NUMTHREAD];
    strcpy(source, "abcdef");
    buflen = strlen(source);

    pthread_create(&thread[0], NULL, (void *)producer, &thread_id[0]);
    pthread_create(&thread[1], NULL, (void *)consumer, &thread_id[1]);
    for (int i=0;i<NUMTHREAD;i++){
        pthread_join(thread[i], NULL);
    }
}

void *producer(int *id) {

    for ( ; i < MAX; i++){
        pthread_mutex_lock(&count_mutex);
        while ((pCount + 1) % BUFLEN == cCount) {
            pthread_cond_wait(&nonEmpty, &count_mutex);
        }
        buffer[pCount] = source[pCount % buflen];
        printf("%d produced %c by Thread %d\n", i, buffer[pCount], *id);
        pCount = (pCount + 1) % BUFLEN;
        pthread_cond_signal(&full);
        pthread_mutex_unlock(&count_mutex);
        sleep(1);
    }
}
void *consumer(int *id) {
     for ( ; j < MAX; j++){
        pthread_mutex_lock(&count_mutex);
        while (cCount == pCount) {
            pthread_cond_wait(&full, &count_mutex);
        }
        printf("%d consumed %c by Thread  %d\n", j, buffer[cCount], *id);
        cCount = (cCount + 1) % BUFLEN;
        pthread_cond_signal(&nonEmpty);
        pthread_mutex_unlock(&count_mutex);
        sleep(4);
    }
}
