#include<stdio.h>
void place(int bucket[1024],int N,int ball[16384],int M,int method,int result[16384]){
    int i,j,check=0,capacity=(-1);
    if(method == 0){
        for(i = 0; i < M; i++){
            for(j = 0; j < N && check == 0; j++){
                if(ball[i] <= bucket[j]){
                    result[i] = j;
                    check = 1;
                }
            }
            if (check == 0){
                result[i]=(-1);
            }
            else
                bucket[ result[i] ]-=ball[i];
            check=0;
        }
    }
    if(method == 1){
        for(i = 0; i < M; i++){
            for(j = 0; j < N ; j++){
                if(ball[i] <= bucket[j] && (bucket[j]-ball[i] < capacity || capacity==-1) ){
                    capacity=bucket[j]-ball[i];
                    result[i] = j;
                    check = 1;
                }
            }
            if (check == 0){
                result[i]=(-1);
            }
            else
                bucket[ result[i] ]-=ball[i];
            check=0;
            capacity=-1;
        }
    }
    if(method == 2){
        for(i = 0; i < M; i++){
            for(j = 0; j < N ; j++){
                if(ball[i] <= bucket[j] && (bucket[j]-ball[i] > capacity) ){
                    capacity=bucket[j]-ball[i];
                    result[i] = j;
                    check = 1;
                }
            }
            if (check == 0){
                result[i]=(-1);
            }
            else
                bucket[ result[i] ]-=ball[i];
            check=0;
            capacity=-1;
        }
    }
}
int main(){
    int N,M,method;
    scanf("%d%d%d",&N,&M,&method);
    int buckets[N];
    for(int i=0;i<N;i++)
        scanf("%d",&buckets[i]);
    int balls[M];
    for(int i=0;i<M;i++)
        scanf("%d",&balls[i]);
    int result[M];
    place(buckets,N,balls,M,method,result);
    for(int i=0;i<M;i++)
        printf("%d%s",result[i],i==M-1?"":" ");
    return 0;
}
