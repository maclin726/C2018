#include <stdio.h>
#define MAXN 10000

void swap(int *a, int *b){
    int tmp = *a;
    (*a) = (*b);
    (*b) = tmp;
    return;
}

int singleLineDistance(int R_distance[], int G_distance[], int B_distance[], int start, int end, int line){
    if( start > end )
        swap(&start, &end);
    int singleSum = 0;
    if( line == 0 ){
        for( int i = start-1; i < end-1; i++ )
            singleSum += R_distance[i];
    }
    else if( line == 1 ){
        for( int i = start-1; i < end-1; i++ )
            singleSum += G_distance[i] ;
    }
    else{
        for( int i = start-1; i < end-1; i++ )
            singleSum += B_distance[i];
    }
    return singleSum;
}

//0 for R, 1 for G, 2 for B
int stationDistance(int R_distance[],int G_distance[],int B_distance[],int G_origin,int G_destination,int startStation[],int endStation[]){
    int G_cnt = 0;
    while( G_distance[G_cnt] != 0 )
        G_cnt++;
    G_cnt++;
    // printf("cnt = %d\n", G_cnt);
    int distanceSum = 0;
    if( startStation[0] == endStation[0] ){
        distanceSum = singleLineDistance(R_distance, G_distance, B_distance, startStation[1], endStation[1], startStation[0]);
    }
    else if( startStation[0] == 0 && endStation[0] == 1 ){
        distanceSum = singleLineDistance(R_distance, G_distance, B_distance, startStation[1], G_origin, 0) +
                    singleLineDistance(R_distance, G_distance, B_distance, 1, endStation[1], 1);
    }
    else if( startStation[0] == 1 && endStation[0] == 0 ){
        distanceSum = singleLineDistance(R_distance, G_distance, B_distance, 1, startStation[1], 1) +
                    singleLineDistance(R_distance, G_distance, B_distance, G_origin, endStation[1], 0);
    }
    else if( startStation[0] == 1 && endStation[0] == 2 ){
        distanceSum = singleLineDistance(R_distance, G_distance, B_distance, startStation[1], G_cnt, 1) +
                    singleLineDistance(R_distance, G_distance, B_distance, G_destination, endStation[1], 2);
    }
    else if( startStation[0] == 2 && endStation[0] == 1 ){
        distanceSum = singleLineDistance(R_distance, G_distance, B_distance, G_destination, startStation[1], 2) +
                    singleLineDistance(R_distance, G_distance, B_distance, G_cnt, endStation[1], 1);
    }
    else if( startStation[0] == 0 && endStation[0] == 2 ){
        distanceSum = singleLineDistance(R_distance, G_distance, B_distance, startStation[1], G_origin, 0) +
                    singleLineDistance(R_distance, G_distance, B_distance, 1, G_cnt, 1) +
                    singleLineDistance(R_distance, G_distance, B_distance, G_destination, endStation[1], 2);        
    }
    else if( startStation[0] == 2 && endStation[0] == 0 ){
        distanceSum = singleLineDistance(R_distance, G_distance, B_distance, startStation[1], G_destination, 2) +
                    singleLineDistance(R_distance, G_distance, B_distance, 1, G_cnt, 1) +
                    singleLineDistance(R_distance, G_distance, B_distance, G_origin, endStation[1], 0); 
    }
    return distanceSum;
}

int main(int argc, char const *argv[])
{
    int R_distance[MAXN]={0};
    int G_distance[MAXN]={0};
    int B_distance[MAXN]={0};
    int G_origin,G_destination;
    int startStation[2],endStation[2];
 
    int Rindex,Gindex,Bindex;
    Rindex =0; 
    while(scanf("%d",&R_distance[Rindex])){
        if( R_distance[Rindex]==0){
            break;
        }
        Rindex++;
    }
    Gindex=0;
    while(scanf("%d",&G_distance[Gindex])){
        if( G_distance[Gindex]==0){
            break;
        }
        Gindex++;
    }    
    Bindex=0;
    while(scanf("%d",&B_distance[Bindex])){
        if( B_distance[Bindex]==0)
            break;
        Bindex++;
    }
    scanf("%d%d",&G_origin,&G_destination);
    scanf("%d%d",&startStation[0],&startStation[1]);
    scanf("%d%d",&endStation[0],&endStation[1]);
    int distanceSum =stationDistance(R_distance,G_distance,B_distance,G_origin,G_destination,startStation,endStation);
    printf("%d\n",distanceSum );
}