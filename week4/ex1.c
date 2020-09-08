#include <stdio.h>
#include <sys/types.h>
#include <process.h>

void main()
{
    //if the  "fork" of current process is 0, then executable process is the "child process" with PID = n
    pid_t n;
    if (fork()==0){
        n = getpid();
        printf("Hello from child [PID - %d]\n", n);
    }else{
        n = getpid();
        printf("Hello from parent [PID - %d]\n", n);
    }

}