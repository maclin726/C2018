#include<stdio.h>
int main(){
    int n,m;
    int i,j,k;
    scanf("%d%d",&n,&m);
    int w[16][16],array[16][16];
    int T=2*m*m;
    for(i=0; i<m; i++)
        for(j=0; j<m; j++)
            w[i][j] = 1;
    for(i=0; i<n; i++){
        int c;
        scanf("%d",&c);
        int h_p=0,end;
        for(j=0; j<m; j++){
            for(k=0; k<m; k++){
                scanf("%d",&array[j][k]);
                h_p += array[j][k]*w[j][k];
            }
        }
        if(h_p >= T)
            end = 1;
        else
            end = 0;
        if(end == 0 && c == 1){
            for(j=0; j<m; j++)
                for(k=0; k<m; k++)
                    if(array[j][k] == 1)
                        w[j][k]*=2;
        }
        else if(end == 1 && c == 0){
            for(j=0; j<m; j++)
                for(k=0; k<m; k++)
                    if(array[j][k] == 1 && w[j][k] >= 2)
                        w[j][k]/=2;
        }
    }
    int Q;
    scanf("%d",&Q);
    for(i=0; i<Q; i++){
        int h_p = 0;
        for(j=0; j<m; j++){
            for(k=0; k<m; k++){
                scanf("%d",&array[j][k]);
                h_p += array[j][k]*w[j][k];
            }
        }
        if( h_p >= T )
            printf("1\n");
        else
            printf("0\n");
    }
return 0;
}
