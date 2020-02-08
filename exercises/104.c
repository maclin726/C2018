#include<stdio.h>
int good[3][3];
int i,j;

int use_good( int A, int B, int C){
    int conflict = 0;
    if( A == 0 && B == 0 && C == 0)
        return 1;
    if( A < 0 || B < 0 || C < 0 )
        return 0;
    if( use_good( A - good[0][0], B - good[0][1], C - good[0][2] ))
        return 1;
    if( use_good( A - good[1][0], B - good[1][1], C - good[1][2] ))
        return 1;
    if( use_good( A - good[2][0], B - good[2][1], C - good[2][2] ))
        return 1;
}
void countdown(int N){
    if( N == 0 )
        return;
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if( use_good(a,b,c) )
        printf("yes\n");
    else
        printf("no\n");
    countdown(N-1);
}
int main(){
    scanf("%d%d%d%d%d%d%d%d%d",&good[0][0],&good[0][1],&good[0][2],&good[1][0],&good[1][1],&good[1][2],&good[2][0],
    &good[2][1],&good[2][2]);
    int N;
    scanf("%d",&N);
    countdown(N);
    return 0;
}