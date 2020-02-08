#include<stdio.h>
int value( int infor[20][2], int n, int i, int W ){
    int a,b;
    if( i == n - 1 )
        if( infor[i][0] <= W )
            return infor[i][1];     //如果最後一個放得下，回傳它的價值
        else
            return 0;               //放不下，value就是0
    if( W < infor[i][0] )
        return value(infor, n, i+1, W);     //放不下第i個東西，回傳從下一個開始的價值
    a = value(infor, n, i+1, W - infor[i][0]) + infor[i][1];        //比大小
    b = value(infor, n, i+1, W);                                    //比大小
    if( a > b )
        return a;
    else
        return b;
}
int main(){
    int n, W;
    scanf("%d%d",&n,&W);
    int i;
    int infor[20][2];
    for (i = 0; i < n; i++)
        scanf("%d%d", &infor[i][0], &infor[i][1]);
    printf("%d", value(infor, n, 0, W));
    return 0;
}