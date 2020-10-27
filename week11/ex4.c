#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

int main() {
    int myFile1 = open("ex1.txt", O_RDWR);
    int myFile2 = open("ex1.memcpy.txt", O_RDWR);
    struct stat st1;
    stat("ex1.txt", &st1);
    off_t size1 = st1.st_size;
    char *addr1;
    char *addr2;
    addr1 = mmap(NULL, size1, PROT_READ|PROT_WRITE, MAP_SHARED, myFile1, 0);
    addr2 = mmap(NULL, size1, PROT_READ|PROT_WRITE, MAP_SHARED, myFile2, 0);
    ftruncate(myFile2, size1);
    memcpy(addr2,addr1,size1);
    return 0;
}
