#include<stdio.h>
#include<string.h>
int main(){
    char last = 'z' + 1;
    char word[32] = {'\0'};
    char vowel[] = "aeiou";
    int count = 0;
    while( scanf("%s", word) != EOF ){
        char *next = strtok(word, vowel);
        while( next != NULL ){
            while( *next != '\0' ){
                if( last < *next )
                    count++;
                last = *next;
                next++;
            }
            next = strtok( NULL, vowel );
        }
    }
    printf("%d",count);
}