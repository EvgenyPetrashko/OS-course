#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char s[1000];
    while (1){
        fgets(s,1000,stdin);
        char *words[1000];

        for (int k = 0; k < 1000 ; ++k) {
            words[k] = NULL;
        }
        int i = 0;
        int j= 0;
        int n = 0;
        words[0] = (char *)malloc(1000);
        while (1){
            if (s[i]==' '){
                i++;
                j=0;
                n++;
                words[n] = (char *)malloc(1000);
            }else if (s[i]!=' ' && s[i] != '\n' && s[i] != '\0'){
                words[n][j] = s[i];
                i++;
                j++;
            } else{
                break;
            }
        }
        if (strcmp(words[n-1], "exit")==0) return 0;
        int pid = fork();
        if (pid==0){
            execvp(words[0], words, NULL);
        }
    }
    return 0;
}