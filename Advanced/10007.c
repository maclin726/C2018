#include<stdio.h>
int main(){
    int n,d,s,i,segment=1;
    while(scanf("%d",&n)!=EOF){
        for (i=0; i<n; i++){
            scanf("%d",&d);
            if(i!=0 && s!=d){
                segment++;
            }
            s=d;
        }
        printf("%d\n",segment);
        segment=0;
    }
return 0;
}
