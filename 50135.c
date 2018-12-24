#include<stdio.h>
#include<string.h>

int main(){
    int T;
    scanf("%d", &T);
    if( !T ){
        char word[100000] = {'\0'};
        scanf("%s", word);
        long long int number = 0;
        int length = strlen(word);
        for( int i = 0; i <= length; i++ ){
            number |= ((long long int)word[i]) << (8 * ( 7-(i%8) ));
            if( i % 8 == 7 || i == length ){
                printf("%lld\n", number);
                number = (long long int)0; 
            }
        }
    }
    else if( T == 1){
        int size;
        scanf("%d", &size);
        for( int i = 0; i < size; i++ ){
            long long int number = 0;
            scanf("%lld", &number);
            for( int j = 7; j >=0; j-- ){
                char c = (char)( (number >> (8 * j)) % 256 );
                if( c != 0 )
                    printf("%c", c);
            }
        }
    }
    else{
        printf("invalid instruction!");
    }
    return 0;
}