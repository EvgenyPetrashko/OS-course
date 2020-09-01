#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int *array, int size){
    for (int i = 0; i < size  ; ++i) {
        for (int j = i + 1; j < size ; ++j) {
            if (array[j] < array[i]){
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
}
int main() {
    //dynamic approach
    printf("Enter the amount of numbers:\n");
    int n;
    scanf("%d", &n);
    int *array= malloc(sizeof(int)*n);
    printf("Enter the all numbers:\n");
    for (int i=0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    bubble_sort( array, n);
    for (int i = 0; i <n ; ++i) {
        printf("%d\n", array[i]);
    }
    free(array);

    // static approach
    /* int array[6] = {7,0,3,5,1,2};
     bubble_sort(array, 6);
     for (int i = 0; i <6 ; ++i) {
         printf("%d\n", array[i]);
     }*/
    return 0;
}
