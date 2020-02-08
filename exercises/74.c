#include<stdio.h>
int main(){
    int n,m,i,s;
    int a[200000],b[200000]={0};
    scanf("%d",&n);
    for (i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for (i=0; i<n; i++){
        s=a[i]%m;
        b[s]++;
    }
    for (i=0; i<m; i++){
        if(i!=0)
            printf("\n");
        printf("%d",b[i]);
    }
return 0;
}
