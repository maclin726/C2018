#include<stdio.h>
int main(){
    int n,m,i,j,quo=0,height,st_h=0,nd_h=0,top_h=0,st_c,nd_c,top_r,top_c;
    scanf("%d%d",&n,&m);
    for (i=1 ;i<=n; i++){
        for (j=1; j<=m; j++){
            scanf("%d",&height);
            if(height>=st_h){
                nd_h=st_h;
                nd_c=st_c;
                st_h=height;
                st_c=j;
            }
            else if(height>=nd_h){
                nd_h=height;
                nd_c=j;
            }
            if(height>=top_h){
                top_r=i;
                top_c=j;
                top_h=height;
            }
        }
        st_h=0;
        nd_h=0;
        printf("%d %d\n",st_c,nd_c);
    }
    printf("%d %d",top_r,top_c);
return 0;
}
