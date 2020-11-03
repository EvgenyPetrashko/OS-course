#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#define BUF_SIZE 4096

int main(int argc, char const *argv[])
{
    int fd, flags, opt;
    ssize_t nread, nwrite,nwrite2;
    char buf[BUF_SIZE+1];
    int has_file = 0;
    if (argc > 1)
        has_file = 1;

    if (has_file) {
        flags = O_WRONLY | O_CREAT | O_TRUNC;
        if ((opt = getopt(argc, argv, "a")) != -1 && opt == 'a'){
            flags = O_WRONLY | O_APPEND | O_CREAT;
        }
        fd = open(argv[argc-1], flags, S_IWUSR);
        if (fd == -1) {
            perror("open");
            return EXIT_FAILURE;
        }
        while ((nread = read (STDIN_FILENO, buf, BUF_SIZE)) != 0) {
                nwrite = write(STDOUT_FILENO, buf, nread);
                nwrite2 = write(fd, buf, nread);
                if (nwrite == -1 || nwrite2 == -1) {
                    perror("write");
                    exit(EXIT_FAILURE);
                }
        }
    }
    return 0;
}
