#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d", &n);
    int *arr;
    arr = (int*)calloc(n,sizeof(int));
    for (int i = 0; i <n ; ++i) {
        arr[i] = i;
        printf("%d\n",arr[i]);
    }
    free(arr);
}

