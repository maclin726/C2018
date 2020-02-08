#include<stdio.h>
unsigned long long int merge( unsigned int UI, unsigned short US, char string[], char pattern[] ){
    unsigned long long int ULLI = 0;
    int index = 0;
    for( int i = 0; i < 4; i++ ){
        if( pattern[i] == 'L' )
            ULLI = ( ULLI << 32 ) | (unsigned long long) UI;
        else if( pattern[i] == 'S' )
            ULLI = ( ULLI << 16 ) | (unsigned long long) US;
        else if( pattern[i] == 'C' ){
            ULLI = ( ULLI << 8 ) | (unsigned long long) string[index];
            index = 1;
        }
    }
    return ULLI;
}
void sort( unsigned long long ULLI, char pattern[] ){
    unsigned int UI = 0;
    unsigned short US = 0;
    char string[3] = {'\0'};
    int merge_count = 64;
    int index = 0;
    for( int i = 0; i < 4; i++ ){
        if( pattern[i] == 'L' ){
            UI |= ( (ULLI) >> (merge_count - 32) );
            merge_count -= 32;
        }
        else if( pattern[i] == 'S' ){
            US |= ( (ULLI) >> (merge_count - 16) );
            merge_count -= 16;
        }
        else if( pattern[i] == 'C' ){
            string[index] |= ( (ULLI) >> (merge_count - 8) );
            merge_count -= 8;
            index = 1;
        }
    }
    printf("%u %hu %c%c\n", UI, US, string[0], string[1]);
}
 
int main(){
    int ins;
    unsigned long long int ULLI;
    unsigned int UI;
    unsigned short US;
    char string[3] = {'\0'};
    char pattern[5] = {'\0'};
    scanf("%d", &ins);
    while( scanf("%s", pattern) != EOF ){
        if( ins == 0 ){
            scanf("%u%hu%s", &UI, &US, &string);
            printf("%llu\n", merge(UI, US, string, pattern) );
        }
        else if( ins == 1 ){
            scanf("%llu", &ULLI);
            sort( ULLI, pattern );
        }
    }
    return 0;
}