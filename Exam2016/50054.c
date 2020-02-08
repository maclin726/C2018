#include<stdio.h>
#include<string.h>
#include<ctype.h>
char *hashTable[1000][10000];
char word[10000][128];
int count[1000] = {0};
int hashIndex( char word[128], int S ){
    int sum = 0;
    for( int i = 0; i < strlen(word); i++ ){
        if( isdigit(word[i]) )
            sum += word[i] - '0';
        else
            sum += word[i];
    }
    return sum % S;
}
int main(){
    int S, N, Q;
    scanf("%d%d%d", &S, &N, &Q);
    for( int i = 0; i < N; i++ ){
        scanf("%s", word[i]);
        word[i][strlen(word[i])] = '\0';
        int index = hashIndex(word[i], S);
        hashTable[index][ count[index] ] = word[i];
        count[index]++;
    }
    for( int i = 0; i < Q; i++){
        char query[128];
        scanf("%s", query);
        int index = hashIndex(query, S);
        int same = 0;
        for(int j = 0; j < count[index] && !same; j++)
            if( strcmp(query, hashTable[index][j]) == 0 ){
                printf("%d\n", index);
                same = 1;
            }
        if( !same )
            printf("-1\n");
    }
    return 0;
}