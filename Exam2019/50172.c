#include <stdio.h>
#include <string.h>

void printStar(int num){
    for( int i = 0; i < num; i++ )
        printf("*");
    return;
}

int main(){
    int dir = 0; //o for horizontal, 1 for vertical
    int starCnt = 0;
    char prev = '0';
    char str[32];
    while( scanf("%s", str) != EOF ){
        if( dir == 0 ){
            if( prev == str[0] ){
                printf("%s\n", &str[1]);
                starCnt += (strlen(str)-1);
            }
            else{
                if( prev != '0' )
                    printf("\n");
                printStar(starCnt);
                printf("%s\n", str);
                starCnt += (strlen(str)-1);
            }
            prev = str[strlen(str)-1];
            dir = 1;
        }
        else{
            if( prev != str[0] ){
                printStar(starCnt);
                printf("%c%s", str[0], strlen(str) == 1? "": "\n");
            }
            for( int i = 1; i < strlen(str); i++ ){
                printStar(starCnt);
                printf("%c%s", str[i], i == strlen(str)-1? "": "\n");
            }
            prev = str[strlen(str)-1];
            dir = 0;
        }
    }
    return 0;
}