#include<stdio.h>
#include<stdlib.h>

int main(){
    int trans, pre_trans, a, b, n, money=0;
    int i;
    scanf("%d",&n);
    scanf("%d%d",&a,&b);
    if( a>=b ){
        pre_trans=(-1);
        money+=2*(a-b);
        a=b;
    }
    else if( a<=b ){
        pre_trans=1;
        money+=3*(b-a);
        a=b;
    }
    for(i=2 ; i<n ; i++){
        scanf("%d",&b);
        if( a>=b && pre_trans==(-1) ){
            money+=2*(a-b);
            pre_trans=(-1);
            a=b;
        }
        else if ( a>=b && pre_trans== 1){
            money+=3*(a-b);
            pre_trans=(-1);
            a=b;
        }
        else if( a<b && pre_trans == (-1) ){
            money+=3*(b-a);
            pre_trans=1;
            a=b;
        }
        else if( a<b && pre_trans == 1 ){
            money+=4*(b-a);
            pre_trans=1;
            a=b;
        }
    }
    printf("%d",money);
return 0;
}
