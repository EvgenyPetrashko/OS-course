#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define max 1000000

int buff = 0;
pthread_t consumer_th;
pthread_t producer_th;

void* producer(void *arg){
    int i = 0;
    for (int j = 0; j < 100000; ++j) {
        while (buff==max);
        if (i % 1000 == 0)  printf("Producer %d %d\n", i, buff);
        if (buff<max){
            i++;
            buff++;
        }
    }
}

void* consume(void *arg){
    int j = 0;
    for (int i = 0; i < 100000 ; ++i) {
        while (buff == 0);
        if (j % 1000 == 0)
            printf("Consumer %d %d\n", j, buff);
        if (buff>0){
            j++;
            buff--;
        }
    }
}

int main(void){
    pthread_create(&producer_th, NULL, producer, NULL);
    pthread_create(&consumer_th, NULL, consume, NULL);
    pthread_join(producer_th, NULL);
    return 0;
}