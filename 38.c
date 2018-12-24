#include<stdio.h>
int lotion(int D, int a, int b, int c, int A, int B, int C){
    if( a < 0 || b < 0 || c < 0 || D < 0 )
        return 0;
    if( D == 0 )
        return 1;
    if( lotion(D-A, a-1, b, c, A, B, C) )
        return 1;
    if( lotion(D-B, a, b-1, c, A, B, C) )
        return 1;
    if( lotion(D-C, a, b, c-1, A, B, C) )
        return 1;
    return 0;
}

int main(){
    int n;
    scanf("%d",&n);
    int i;
    for( i = 0; i < n; i++ ){
        int D, a,b,c, A,B,C;
        scanf("%d%d%d%d%d%d%d",&D,&a,&b,&c,&A,&B,&C);
        if(lotion(D, a, b, c, A, B, C))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}