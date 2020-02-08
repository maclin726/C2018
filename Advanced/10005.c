#include <stdio.h> 
#include <string.h>    // strlen(s)
#include <ctype.h>
 
int main() {
    char s[1024];
    int count = 0;
    while (scanf("%s", s)!=EOF) {
        int n = (int) strlen(s);    // strlen("CSIE") = 4, actually use "CSIE\0" in memory.
        int number = 0;
        int digit = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if( isdigit(c) ){
                digit = 1;
                number *= 10;
                number += (c - '0');
            }
            else if( digit ){
                digit = 0;
                printf("%d\n", number);
                number = 0;
            }
        }
        if( digit ){
            printf("%d",number);
        }
    }
    return 0;
}