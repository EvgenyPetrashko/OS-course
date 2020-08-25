#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(int args, char *argv[]) {
    int n;
    sscanf(argv[1],"%d", &n);
    int i = 1;
    while (i != n + 1){
        int num_spaces = (n - i);
        if (num_spaces != 0){
            printf("%*c", num_spaces, ' ');
        }

        for (int j = 0; j < 2*i - 1 ; ++j) {
            printf("*");
        }
        if (num_spaces != 0){
            printf("%*c", num_spaces, ' ');
        }
        printf("\n");
        i++;

    }
    return 0;
}
