#include <stdio.h>


void swap(int *a, int *b){
    int temp;
    temp  = *b;
    *b = *a;
    *a = temp;
}

int main() {
    int a;
    int b;
    scanf("%d %d", &a, &b);
    swap(&a,&b);
    printf("%ld\n",a);
    printf("%ld\n", b);
    return 0;
}
