#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int puzzle( char word[3][10], char letter[26],int count[26], int coordinate[26][26][2], int kind, int index ){
    if( index == kind ){
        int a = atoi(word[0]), b= atoi(word[1]), c = atoi(word[2]);
        if( a*b == c )
            return 1;
        else
            return 0;
    }
    for(char i = '1'; i <= '9'; i++){
        for( int c = 0; c < count[index]; c++ )
            word[coordinate[index][c][0]][coordinate[index][c][1]] = i;
        if( puzzle(word, letter, count, coordinate, kind, index+1) )
            return 1;
        for( int c = 0; c < count[index]; c++ )
            word[coordinate[index][c][0]][coordinate[index][c][1]] = letter[index];
    }
    return 0;
}
int main(){
    char word[3][10] = {'\0'};
    scanf("%s%s%s", word[0], word[1], word[2]);
    char letter[26];                    //save different letters in the array, kind means how many type of letters
    int count[26]={0};
    int coordinate[26][26][2];
    int kind = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < strlen(word[i]); j++ )
            if( isalpha(word[i][j]) ){
                int same = 0;
                for( int k = 0; k < kind; k++){
                    if( word[i][j] == letter[k] ){
                        coordinate[k][count[k]][0] = i;
                        coordinate[k][count[k]][1] = j;
                        count[k]++;
                        same = 1;
                    }
                }
                if( !same ){
                    coordinate[kind][count[kind]][0] = i;
                    coordinate[kind][count[kind]][1] = j;
                    count[kind]++;
                    letter[kind] = word[i][j];
                    kind++;
                }
            }
    if( puzzle(word, letter, count, coordinate, kind, 0) )
        printf("%s x %s = %s\n",word[0], word[1], word[2]);
    return 0;
}