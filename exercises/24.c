#include<stdio.h>
#include<ctype.h>

int main(){
    char c;
    int digit=0, letter=0, vowel=0, consonant=0;
    while( scanf("%c",&c) != EOF ){
        if( isdigit(c) )
            digit++;
        if( isalpha(c) ){
            letter++;
            if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'   )
                vowel++;
            else
                consonant++;
        }
    }
    printf("%d %d %d %d",digit, letter, vowel, consonant);
return 0;
}
