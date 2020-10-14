#include <stdio.h>
#include <stdlib.h>

struct pageFrame {
    unsigned int age;
    int numberOfPage;
};

int main(int argc, char *argv[]) {

    FILE *input = fopen("Lab_09_input.txt", "r");

    int hit = 0;
    int miss = 0;
    int numFrames;
    int page;
    sscanf(argv[1], "%d", &numFrames);
    struct pageFrame *frames = malloc(sizeof(struct pageFrame) * numFrames);
    for (int i = 0; i < numFrames; ++i) {
        frames[i].numberOfPage = -1;
        frames[i].age = 0;
    }
    while (fscanf(input, "%d", &page) != EOF) {
        int find = 0;
        for (int i = 0; i < numFrames; ++i) {
            if (frames[i].numberOfPage == page) {
                find = 1;
                break;
            }
        }
        if (find) {
            hit++;
            for (int i = 0; i < numFrames; ++i) {
                if (frames[i].numberOfPage != -1) {
                    frames[i].age >>= 1;
                    if (frames[i].numberOfPage == page)
                        frames[i].age |= (1 << 31);
                }
            }
        }
        else {
            miss++;
            int indexOfMinAge = 0;
            int index;
            int EmptyWasFound = 0;
            for (int i = 0; i < numFrames; ++i) {
                if (frames[i].numberOfPage == -1) {
                    index = i;
                    EmptyWasFound = 1;
                    frames[i].numberOfPage = page;
                    frames[i].age = 1 << 31;
                    break;
                }
                if (frames[i].age < frames[indexOfMinAge].age)
                    indexOfMinAge = i;
            }
            if (EmptyWasFound) {
                for (int i = 0; i < numFrames; ++i) {
                    if (frames[i].numberOfPage != -1 && i != index) {
                        frames[i].age >>= 1;
                    }
                }
            }
            else {
                for (int i = 0; i < numFrames; ++i) {
                    if (frames[i].numberOfPage != -1) {
                        frames[i].age >>= 1;
                        if (indexOfMinAge == i) {
                            frames[i].age = 1 << 31;
                            frames[i].numberOfPage = page;
                        }
                    }
                }
            }
        }
    }
    printf("hits:\t%d\n", hit);
    printf("misses:\t%d\n", miss);
    printf("hit/miss:\t%f\n", (double)hit/(double)miss);

    return 0;
}
