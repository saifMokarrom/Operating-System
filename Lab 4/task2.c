#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
/*
This program provides a possible solution using mutex and semaphore.
use 5 Farmers and 5 ShopOwners to demonstrate the solution.
*/
#define MaxCrops 5 // Maximum crops a Farmer can produce or a Shpoowner can take
#define warehouseSize 5 // Size of the warehouse
sem_t empty;
sem_t full;
int in = 0;
int out = 0;
char crops[warehouseSize]={'R','W','P','S','M'}; //indicating room for different crops
char warehouse[warehouseSize]={'N','N','N','N','N'}; //initially all the room is empty
pthread_mutex_t mutex;

void *Farmer(void *far) {
    for (int i = 0; i < MaxCrops; i++){
        int value = rand() % 5;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        warehouse[in] = crops[value];
        printf("Farmer %d:Insert crops %c at %d\n", *((int *)far), crops[value], in);
        in = (in + 1) % warehouseSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}
void *ShopOwner(void *sho) {
    for (int i = 0; i < MaxCrops; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        printf("Shop owner %d:Remove crops %c from %d\n", *((int *)sho), warehouse[out], out);
        warehouse[out] = 'N';
        out = (out + 1) % warehouseSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
    printf("Shop Owner%d:", *(int*)sho);
    for (int i = 0; i < warehouseSize; i++){
        printf("%c", warehouse[i]);
    }
    printf("\n");
}

int main() {
    pthread_t Far[5], Sho[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, warehouseSize);
    sem_init(&full, 0, 0);
    int a[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        pthread_create(&Far[i], NULL, (void *)Farmer, (void *)&a[i]);
    }
    for (int i = 0; i < 5; i++) {
        pthread_create(&Sho[i], NULL, (void *)ShopOwner, (void *)&a[i]);
    }
    for (int i = 0; i < 5; i++) {
        pthread_join(Far[i], NULL);
    }
    for (int i = 0; i < 5; i++) {
        pthread_join(Sho[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}
