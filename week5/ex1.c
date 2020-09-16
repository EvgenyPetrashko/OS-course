#include <stdio.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

void* foo(void* p){
    printf("THREAD: ");
    printf("%i\n", (int*)p);
}

int main1(void){
    int n;
    scanf("%d", &n);
    pthread_t threads[n];
    int id[n];
    for (int j = 0; j <n ; ++j) {
        id[j] = j;
        pthread_create(&threads[j],NULL, foo, &id[j]);
        pthread_join(threads[j], NULL);
    }
}