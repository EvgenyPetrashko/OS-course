#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/types.h>

#define MAX_N_FILES 1000
int main(){
    FILE *fp = fopen("ex4.txt", "w");
    DIR *tmp = opendir("tmp");
    struct dirent *dp;
    struct dirent *inode[MAX_N_FILES];
    int num = 0;
    while((dp = readdir(tmp)) != NULL){
        inode[num] = dp;
        num++;
    }
    for(int i = 0; i < num; i++){
        int k = 0;
        int array[MAX_N_FILES];
        for(int j = 0; j < num; j++){
            if(inode[i]->d_ino == inode[j]->d_ino){
                if(j <= i && k != 0){
                    k = 0;
                    break;
                }
                array[k] = j;
                k++;
            }
        }
        if(k > 1){
            fprintf(fp, "%lu\n", inode[i]->d_ino);
            for(int l = 0; l< k; l++)
                fprintf(fp, "%s ", inode[array[l]]->d_name);
            fprintf(fp, "\n");
        }
    }
    return 0;
}
