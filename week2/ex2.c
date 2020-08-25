#include <stdio.h>
#include <string.h>
int main() {
    char s[100];
    gets(s);
    strrev(s);
    printf(s);
    return 0;
}

