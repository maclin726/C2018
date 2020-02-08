#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLENGTH 16
#define MAXCOMPONENT 64

typedef struct{
    char name[MAXLENGTH];
    int numComponent;
    int componentPartList[MAXCOMPONENT];
    int price;
}ComponentPart;

int countPrice( ComponentPart list[], int index ){
    int sum = 0;
    if( list[index].numComponent == 0 )
        return list[index].price;
    for( int i = 0; i < list[index].numComponent; i++ )
        sum += countPrice(list, list[index].componentPartList[i]);
    return sum;
}

void findPrice(int N, ComponentPart list[]){
    for( int i = 0; i < N; i++ )
        if( !list[i].price )
            list[i].price = countPrice(list, i);
    int order[128];
    for( int i = 0; i < N; i++ )
        order[i] = i;
    for( int i = 0; i < N; i++ )
        for( int j = N-1; j > i; j-- )
            if( strcmp( list[order[j-1]].name, list[order[j]].name ) > 0 ){
                int temp = order[j];
                order[j] = order[j-1];
                order[j-1] = temp;
            }
    for( int i = 0; i < N; i++ )
        printf("%s %d\n", list[order[i]].name, list[order[i]].price);
    return;
}

int main(){
    int N;
    scanf("%d",&N);
    ComponentPart list[N];
    for(int i=0;i<N;i++){
        scanf("%s%d",list[i].name,&list[i].numComponent);
        if(list[i].numComponent){
            for(int j=0;j<list[i].numComponent;j++)
                scanf("%d",&list[i].componentPartList[j]);
            list[i].price=0;
        }
        else
            scanf("%d",&list[i].price);
    }
    findPrice(N,list);
    return 0;
}