#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *reallocation(void *ptr, size_t initial, size_t new){
    if (new <= initial){
        //trim the array
        void *ptr2 = malloc(new);
        memcpy(ptr2,ptr,new);
        free(ptr);
        return ptr2;
    }else if(ptr == NULL){
        return malloc(new);
    }else if (new == 0){
            free(ptr);
            return NULL;
    } else{
        //stretch the array
        void *ptr2 = malloc(new);
        memcpy(ptr2,ptr,initial);
        free(ptr);
        return ptr2;
    }
}

int main(){
    int initial = 16;
    int final = 20;
    int* a = (int)calloc(initial, sizeof(int));
    printf("Initial array:\n");
    for (int i = 0; i < initial ; ++i) {
        a[i] = 1;
        printf("%d ", a[i]);
    }
    printf("\n");
    a = reallocation(a,initial*sizeof(int),final*sizeof(int));
    printf("New array:\n");
    for (int j = 0; j < final ; ++j) {
        printf("%d ", a[j]);
    }
    // 1 - is numbers from the first version of the array, 0 - is the numbers from the reallocated array
    free(a);
}