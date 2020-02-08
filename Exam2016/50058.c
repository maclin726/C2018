#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAXWORD 20
#define MAXLENGTH 64
 
int check( int alphabet[] ){
    for( int i = 0; i < 26; i++ )
        if( !alphabet[i] )
            return 0;
    return 1;
}
 
void printAlphabet( int alphabet[] ){
    for( int i = 0; i < 26; i++ )
        printf( !alphabet[i]? "0": "1" );
    printf("\n");
}
 
void find(char word[][MAXLENGTH], int cost[], int alphabet[], int index, int N, int nowmin, int *min){
#ifdef DEBUG
    printf("index = %d, nowmin = %d, min = %d\n", index, nowmin, *min);
#endif
    if( index >= N || nowmin > *min ){
        return;
    }
    int temp[26] = {0};
    for( int i = 0; i < 26; i++ )
        temp[i] = alphabet[i];
    find( word, cost, temp, index+1, N, nowmin, min );
    for( int i = 0; i < strlen(word[index]); i++ )
        alphabet[ word[index][i]- 'a' ]++;
    if( check(alphabet) && (nowmin+cost[index] < *min) )
        *min = nowmin + cost[index];
    find(word, cost, alphabet, index+1, N, nowmin+cost[index], min);
    return;
}
 
int main(){
    int N;
    char word[MAXWORD][MAXLENGTH]={'\0'};
    int cost[MAXWORD] = {0};
    int alphabet[26] = {0};
    scanf("%d", &N);
    for( int i = 0; i < N; i++ )
        scanf("%s%d", word[i], &cost[i]);
    int min = 2147483647;
    find(word, cost, alphabet, 0, N, 0, &min);
    printf("%d", min);
    return 0;
}
