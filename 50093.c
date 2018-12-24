#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char s[1024] = {'\0'};
    scanf("%s", s);
    char cmd;
    while( scanf("%c" , &cmd) != EOF ){
        if( cmd == 'p' ){
            printf("%s\n", s);
            continue;
        }
        else if( cmd == 's' ){
            char replace[1024];
            scanf("%s", replace);
            char delimeter[2] = {replace[0],'\0'};
#ifdef DEBUG
            printf("replace:%s, delimeter = %c\n", replace, delimeter[0]);
#endif
            char A[512], B[512];
            char *start;
            int i;
            start = strtok( &replace[1], delimeter );
            for( i = 0; i < 2; i++ ){
                if( !i )
                    strcpy( A, start );
                else
                    strcpy( B, start );
                start = strtok( NULL, delimeter );
            }
            int lengthA = strlen(A), lengthB = strlen(B), lengthS = strlen(s);
            char *ptr;
            ptr = strstr(s, A);
            if( ptr != NULL ){
                char buffer[512];
                strcpy( ptr + lengthB, ptr + lengthA );
                strncpy( ptr, B, lengthB);
            }
#ifdef DEBUG
            printf("s:<%s>\n", s);
            printf("A:<%s>\n", A);
            printf("B:<%s>\n", B);
#endif
        }
    }
    return 0;
}