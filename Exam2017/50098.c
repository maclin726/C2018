#include<stdio.h>
#define LL long long int
int disjoint( LL club[], int total, int num, int c_index, int ans[], int ans_index, LL common){
    if( !num )
        return 1;
    if( c_index >= total && (total - c_index) < num )
        return 0;
    for( int i = c_index; i < total; i++ ){
        int conflict = (common & club[i])? 1:0;
        ans[ans_index] = i;
        if( !conflict && disjoint(club, total, num-1, i, ans, ans_index+1, common|club[i] ) )
            return 1;
    }
    return 0;
}
int main(){
    LL club[100] = {0}, s= 1;
    int N, K;
    scanf("%d%d", &N, &K);
    for( int i = 0; i < N; i++ ){
        int M, student;
        scanf("%d", &M);
        for( int j = 0; j < M; j++ ){
            scanf("%d", &student);
            club[i] |= s << student;
        }
    }
    int ans[100];
    long long int common = 0;
    disjoint( club, N, K, 0, ans, 0, common);
    for( int i = 0 ; i < K; i++ )
        printf("%d\n", ans[i]);
    return 0;
}