#include<stdio.h>
int main(){
    int k,n,divide=0,ok=0,count=0;
    scanf("%d",&k);
    while(scanf("%d",&n)!=EOF){
        count++;
        divide+=n;
        if( ok == 0 && divide >= k){
            printf("%d\n",divide/k);
            divide=(divide%k)*10;
            ok=1;
        }
        else if(ok == 0 && divide < k){
            divide*=10;
        }
        else if(ok == 1){
            printf("%d\n",divide/k);
            divide=(divide % k)*10;
        }

    }
    if(count == 1 && divide/10 < k){
        printf("0");
    }
return 0;
}
