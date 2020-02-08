#include<stdio.h>
int main(){
    int m,n;
    int i,j;
    int f[100],g[100],h[200]={0};
    scanf("%d",&m);
    for (i=(m-1); i>=0; i--){
        scanf("%d", &f[i]);
    }
    scanf("%d",&n);
    for (i=(n-1); i>=0; i--){
        scanf("%d", &g[i]);
    }
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            h[i+j]=h[i+j]+f[i]*g[j];
        }
    }
    for (i=m+n-2; i>=0; i--){
        if(i!=0)
            printf("%d ",h[i]);
        else
            printf("%d",h[i]);
    }
return 0;
}
