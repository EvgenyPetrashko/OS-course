#include <stdio.h>
#include <stdlib.h>

int main() {

    char command[255];

    while(scanf("%s", command) > 0) {
        system(command);
    }
    return 0;
}