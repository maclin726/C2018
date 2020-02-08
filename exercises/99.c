#include<stdio.h>
    int a[10][256][256];
    int order[65536];
    char c[10][65];
int main(){
    int n,m;
    int i,j,k,l,find=0;
    scanf("%d%d",&n,&m);
    int winner[10],winnumber=0,winsign=0;
    int check1=0,check2=0,end=0;
    for(i=0; i<n; i++){
        scanf("%s", c[i]);
        for (j=0; j<m; j++){
            for(k=0; k<m; k++){
                scanf("%d",&a[i][j][k]);
            }
        }
    }
    for (i=0; i<m*m; i++){
        scanf("%d",&order[i]);
    }
    for (i=0; i<m*m && winsign==0; i++){              //order
        for(j=0; j<n; j++){                           //people
            for(k=0; k<m && find==0; k++){
                for(l=0; l<m && find==0; l++){
                    if(order[i]==a[j][k][l]){
                        a[j][k][l]=0;
                        find=1;
                    }
                }
            }
            find=0;
        }
        for(j=0; j<n; j++){
            for(k=0; k<m && end==0; k++){
                for(l=0; l<m && (check1==0 || check2==0); l++){
                    if( a[j][k][l]!=0 && check1==0)
                        check1=1;
                    if( a[j][l][k]!=0 && check2==0)
                        check2=1;
                }
                if( check1==0 || check2==0 ){
                        winner[winnumber]=j;
                        winnumber++;
                        winsign=1;
                        end=1;
                }
                check1=0;
                check2=0;
            }
            for(k=0; k<m && end==0 && (check1==0||check2==0); k++){
                if(a[j][k][k]!=0)
                    check1=1;
                if(a[j][k][m-1-k]!=0)
                    check2=1;
            }
            if( (check1==0 || check2==0) && end==0){
                    winner[winnumber]=j;
                    winnumber++;
                    winsign=1;
                    end=1;
            }
            check1=0;
            check2=0;
            end=0;
        }
        if(winsign==1){
            printf("%d ",order[i]);
        }
    }
    for(i=0; i<winnumber; i++){
        if(i!=winnumber-1)
            printf("%s ",c[winner[i]]);
        else
            printf("%s",c[winner[i]]);
    }
return 0;
}
