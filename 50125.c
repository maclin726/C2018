#include<stdio.h>
int in_map( int N, int r, int c ){
    return ( r >= 0 && r < N && c >= 0 && c < N );
}
int findLength (int array[][256], int N, int r, int c, int dr, int dc){
    int count = 0;
    int max = 0;
    while( in_map( N, r, c ) ){
        if( array[r][c] )
            count++;
        else
            count = 0;
        if( count > max )
            max = count;
        r += dr;
        c += dc;
    }
    return max;
}