#include<stdio.h>
#include<string.h>
int distance(char wordA[], char wordB[], int lengthA, int lengthB ){
    if( lengthA == 0 )
        return lengthB;
    else if( lengthB == 0 )
        return lengthA;
    if( wordA[0] == wordB[0] )
        return distance( &wordA[1], &wordB[1], lengthA-1, lengthB-1 );
    int p = distance( &wordA[1], wordB, lengthA-1, lengthB );
    int q = distance( wordA, &wordB[1], lengthA, lengthB-1);
    if( p > q )
        return 1 + q;
    else
        return 1 + p;
}
int main(){
    char word[128][16] = {'\0'};
    int length[128];
    int i = 1;
    while( scanf("%s", word[i]) != EOF ){
        length[i] = strlen(word[i]);
        i++;
    }
    int min = 2147483647, ID1, ID2;
    for( int m = 1; m < i; m++ )
        for( int n = m + 1; n < i; n++ )
            if( distance( word[m], word[n], length[m], length[n] ) < min && n != m){
                min = distance( word[m], word[n], length[m], length[n] );
                ID1 = m;
                ID2 = n;
            }
    printf("%d %d %d", min, ID1, ID2);
    return 0;
}