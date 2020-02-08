#include<stdio.h>
#include<ctype.h>
int main(){
    char s[101];
    int count = 0;
    int head, end;
    while ( scanf("%c", &s[count]) != EOF ){
        if( s[count] == '\n' ){
            int head = 0, end = (count - 1),i;
            while ( isspace( s[head] ) )
                head++;
            while ( isspace( s[end] ) )
                end--;
            for( i = head; i <= end; i++ )
                printf( "%c",s[i] );
            printf("\n");
            count = 0;
        }
        else{
            count++;
        }
    }
return 0;
}
