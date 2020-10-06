#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    for (int i = 0; i < 10 ; ++i) {
        struct rusage* memory = malloc(sizeof(struct rusage));
        getrusage(RUSAGE_SELF, memory);
        printf("Usage: %ld\n", memory->ru_ixrss);
        printf("Usage: %ld\n", memory->ru_isrss);
        printf("Usage: %ld\n", memory->ru_idrss);
        printf("Max: %ld\n", memory->ru_maxrss);
        sleep(1);
    }



    return 0;
}