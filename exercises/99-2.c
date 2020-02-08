#include<stdio.h>
    int a[10][65536][2];
    int b[10][256][256]={0};
    int order[65536];
    char c[10][65];
int main(){
    int n,m;
    int i,j,k,l,find=0;
    scanf("%d%d",&n,&m);
    int winner[10],winnumber=0,winsign=0;
    int check1=0,check2=0,end=0,number;
    for(i=0; i<n; i++){
        scanf("%s", c[i]);
        for (j=0; j<m; j++){
            for(k=0; k<m; k++){
                scanf("%d",&number);
                a[i][number-1][0]=j;
                a[i][number-1][1]=k;
            }
        }
    }
    for (i=0; i<m*m; i++){
        scanf("%d",&order[i]);
    }
    for (i=0; i<m*m && winsign==0; i++){
        for(j=0; j<n; j++){
            b[j][ a[j][ order[i]-1 ][0] ][ a[j][ order[i]-1 ][1] ]=1;
        }
        for(j=0; j<n; j++){
            for(k=0; k<m && end==0; k++){
                for(l=0; l<m && (check1==0 || check2==0); l++){
                    if( b[j][k][l]!=1 && check1==0)
                        check1=1;
                    if( b[j][l][k]!=1 && check2==0)
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
                if(b[j][k][k]!=1)
                    check1=1;
                if(b[j][k][m-1-k]!=1)
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
