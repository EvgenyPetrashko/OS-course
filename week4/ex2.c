#include <stdio.h>
#include <sys/types.h>
#include <process.h>
#include <unistd.h>

void main()
{
    //For n forks 2^n are created
    for (int i = 0; i < 5; ++i) {
        fork();
        sleep(5);
    }

}