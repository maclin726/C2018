#include<stdio.h>
int main(){
    int map[500][500]={0},N,M,L,W; //N,M map; L,W tank ªø¼e
    int stop_num; // how many obstacles
    int i,j;
    int x,y,instruction;
    int tankx=0,tanky=0,check=0; //tank x,y means tanks coordinates
    scanf("%d%d%d%d%d",&N,&M,&L,&W,&stop_num);
    for (i=0 ; i<stop_num; i++){
        scanf("%d%d",&x,&y);
        map[y][x]=2;
    }
    for (i=0 ; i<L; i++){
        for (j=0; j<W; j++){
            map[i][j]=1;
        }
    }
    while(scanf("%d",&instruction)!=EOF){
        check=0;
        if(instruction==0){
            for(i=0; i<N; i++){
                for(j=0; j<M; j++){
                    printf("%d",map[i][j]);
                }
                printf("\n");
            }
        }
        else if(instruction == 1 && tankx + W < M){
                for(i=tanky; i<(tanky+L) && check<2; i++){
                    if(map[i][tankx+W]==2)
                        check++;
                }
                if(check<2){
                    for(i=tanky; i<(tanky+L); i++){
                        map[i][tankx+W]=1;
                        map[i][tankx]=0;
                    }
                    tankx++;
                }
        }
        else if(instruction == 2 && tanky + L < N){
                for(i=tankx; i<(tankx+W) && check<2; i++){
                    if(map[tanky+L][i]==2)
                        check++;
                }
                if(check<2){
                    for(i=tankx; i<(tankx+W); i++){
                        map[tanky+L][i]=1;
                        map[tanky][i]=0;
                    }
                    tanky++;
                }
        }
        else if(instruction==3 && tankx - 1 >= 0){
                for(i=tanky; i<tanky+L && check<2; i++){
                    if(map[i][tankx-1]==2)
                        check++;
                }
                if(check<2){
                    for(i=tanky; i<tanky+L; i++){
                        map[i][tankx-1]=1;
                        map[i][tankx+W-1]=0;
                    }
                    tankx--;
                }
        }
        else if(instruction==4 && tanky - 1 >= 0){
                for(i=tankx; i<tankx+W && check<2; i++){
                    if(map[tanky-1][i]==2)
                        check++;
                }
                if(check<2){
                    for(i=tankx; i<tankx+W; i++){
                        map[tanky-1][i]=1;
                        map[tanky+L-1][i]=0;
                    }
                    tanky--;
                }
        }
        else if(instruction == 5 && tankx+W < M && tanky+L < N){
                for(i=tanky+1; i<(tanky+L+1) && check<2; i++)
                    if(map[i][tankx+W]==2)
                        check++;
                for(i=tankx+1; i<(tankx+W) && check<2; i++)
                    if(map[tanky+L][i]==2)
                        check++;
                if(check<2){
                    for(i=tanky; i<(tanky+L); i++){
                        map[i+1][tankx+W]=1;
                        map[i][tankx]=0;
                    }
                    for(i=tankx; i<(tankx+W); i++){
                        map[tanky+L][i+1]=1;
                        map[tanky][i]=0;
                    }
                    tankx++;
                    tanky++;
                }
        }
    }
}
