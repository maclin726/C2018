#include<stdio.h>
#include<string.h>
#include<ctype.h>
int vowel( char letter ){
    return( letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' );
}
void syllable( char word[], int record[][2] ){
    int count = 0, length = strlen(word);
    for( int i = 0; i < length; i++ )
        if( vowel(word[i]) ){
            record[count][1] = i;
            count++;
            record[count][0] = i + 1;
        }
}
void print( char word[], int *recordi, int *recordj ){
    int length = strlen(word);
    for( int l = 0; l < length; l++ )
        ( l < recordi[0] || l > recordi[1] )? printf("+"): printf("%c", word[l]);
    printf("\n");
    for( int l = 0; l < length; l++ )
        ( l < recordj[0] || l > recordj[1] )? printf("+"): printf("%c", word[l]);
    printf("\n");
    for( int l = 0; l < length; l++ )
        ( (l >= recordi[0] && l <= recordi[1]) || (l >= recordj[0] && l <= recordj[1]) )? 
            printf("+"): printf("%c", word[l]);
    printf("\n");
}
int main(){
    char word[16384] = {'\0'};
    while( scanf("%s", word) != EOF ){
        int i, j;
        scanf("%d%d", &i, &j);
        int record[10000][2] = {0};
        syllable( word, record );
        print( word, record[i], record[j] );
        word[0] = '\0';
    }
    return 0;
}