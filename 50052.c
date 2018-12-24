#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int dis( char A[16], char B[16] ){
    int sum = 0;
    for( int i = 0; i < strlen(A); i++ )
        sum += abs(A[i] - B[i]);
    return sum;
}
int meanDis( char A[16], int mean[16] ){
    int sum = 0;
    for( int i = 0; i < strlen(A); i++ )
        sum += abs( A[i] - mean[i] );
    return sum;
}
void meancnt( char word[64][16], int group[3][50], int groupcnt[3], int mean[3][16] ){
    for( int i = 0; i < 3; i++ ){
        for( int j = 0; j < groupcnt[i]; j++ )
            for( int k = 0; k < strlen(word[0]); k++ )
                mean[i][k] += word[ group[i][j] ][k];
        for( int j = 0; j < strlen(word[0]); j++ )
            mean[i][j] /= groupcnt[i];
    }
    return;
}
void compare( char word[64][16], int index[], int number ){
    for( int i = 0; i < number; i++ )
        for( int j = number - 1; j > i; j-- )
            if( strcmp( word[index[j]], word[index[j-1]] ) < 0 ){
                int temp = index[j];
                index[j] = index[j-1];
                index[j-1] = temp;
            }
    return;
}
int newleader( char word[64][16], int group[], int groupcnt, int mean[]){
    int min = 2147482647, leader = -1;
    compare( word, group, groupcnt );
    for( int i = 0; i < groupcnt; i++ )
        if( meanDis( word[ group[i] ], mean ) < min ){
            leader = group[i];
            min = meanDis( word[ group[i] ], mean );
        }
    return leader;
}
int whichLeader( char word[64][16], int index , int leader[] ){
    int min = 2147483647, belong = (-1);
    for( int i = 0; i < 3; i++ )
        if( dis( word[index], word[ leader[i] ] ) < min ){
            belong = i;
            min = dis( word[index], word[ leader[i] ] );
        }
    return belong;
}
int main(){
    int N, L, R;
    scanf("%d%d%d", &N, &L, &R);
    char word[64][16];
    for( int i = 0; i < N; i++)
        scanf("%s", word[i]);
    int leader[3] = {0, 1, 2};
    for( int i = 0; i < R; i++){
        compare( word, leader, 3 );
        int group[3][50] = { {leader[0]}, {leader[1]}, {leader[2]} }, groupcnt[3] = {1, 1, 1};
        for( int j = 0; j < N; j++ ){                       //determine which group a word belong
            if( j == leader[0] || j == leader[1] || j == leader[2] )
                continue;
            else{
                int belong = whichLeader(word, j, leader);
                group[belong][ groupcnt[belong] ] = j;
                groupcnt[belong]++;
            }
        }
        int mean[3][16] = {0};
        meancnt( word, group, groupcnt, mean );
        for( int j = 0; j < 3; j++ )
            leader[j] = newleader( word, group[j], groupcnt[j], mean[j] );
    }
    compare( word, leader, 3 );
    printf("%s\n%s\n%s\n", word[leader[0]], word[leader[1]], word[leader[2]] );
    return 0;
}