#include<stdio.h>
int main(){
    int n;
    int i,x[1000],y[1000];
    int p,q,end=0;
    int a[3][3]={0};
    scanf("%d",&n);
    for (i=0; i<n; i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    for (i=0; (i<n&&end==0); i++){
        if(i%2==0 && x[i]<=2 && y[i]<=2 && a[x[i]][y[i]]==0)
            a[x[i]][y[i]]=1; //black
        if(i%2==1 && x[i]<=2 && y[i]<=2 && a[x[i]][y[i]]==0)
            a[x[i]][y[i]]=2; //white
        for(p=0; p<3; p++){
            if(a[p][0]==a[p][1] && a[p][1]==a[p][2]){
                if(a[p][0]==1){
                    printf("Black wins.");
                    end=1;
                }
                if(a[p][0]==2){
                    printf("White wins.");
                    end=1;
                }
            }
            if(a[0][p]==a[1][p] && a[1][p]==a[2][p] && end==0){
                if(a[0][p]==1){
                    printf("Black wins.");
                    end=1;
                }
                if(a[0][p]==2){
                    printf("White wins.");
                    end=1;
                }
            }
        }
        if(a[0][0]==a[1][1]&&a[1][1]==a[2][2]&&end==0){
            if(a[0][0]==1){
                printf("Black wins.");
                end=1;
            }
            if(a[0][0]==2){
                printf("White wins.");
                end=1;
            }
        }
        if(a[0][2]==a[1][1]&&a[1][1]==a[2][0]&&end==0){
            if(a[0][2]==1){
                printf("Black wins.");
                end=1;
            }
            if(a[0][2]==2){
                printf("White wins.");
                end=1;
            }
        }
    }
    if(end==0){
        printf("There is a draw.");
    }
return 0;
}
