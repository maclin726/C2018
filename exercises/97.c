#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
    int park[10][3],bike[100000][2],count[10]={0};
    int n,m;
    int i,j,end=0,distance=40001,x,y,location;
    scanf("%d",&n);
    for (i=0; i<n; i++){
        scanf("%d%d%d",&park[i][0],&park[i][1],&park[i][2]);
    }
    scanf("%d",&m);
    for (i=0; i<m; i++){
        scanf("%d%d",&bike[i][0],&bike[i][1]);
        for (j=0; j<n; j++){
            if( abs(bike[i][0]-park[j][0])+abs(bike[i][1]-park[j][1])<distance && count[j]<park[j][2] ){
                x=park[j][0];
                y=park[j][1];
                location=j;
                distance=abs(bike[i][0]-park[j][0])+abs(bike[i][1]-park[j][1]);
            }
            else if( abs(bike[i][0]-park[j][0])+abs(bike[i][1]-park[j][1])==distance && count[j]<park[j][2] ){
                if(park[j][0]<x){
                    x=park[j][0];
                    y=park[j][1];
                    location=j;
                }
                else if(park[j][0]==x && park[j][1]<y){
                    x=park[j][0];
                    y=park[j][1];
                    location=j;
                }
            }
        }
        count[location]++;
        distance=400001;
        end=0;
    }
    for (i=0; i<n; i++){
        printf("%d\n",count[i]);
    }
return 0;
}
