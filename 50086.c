#include<stdio.h>
    int friendship[32768][256]={{0}};
    int friendnumber[32768]={0};
    int partymember[32768]={0};
int main(){
    int n,e,a,b,i;
    int party;
    scanf("%d%d",&n,&e);
    for(i=0; i<e; i++){
        scanf("%d%d",&a,&b);
        friendship[a][ friendnumber[a] ]=b;
        friendship[b][ friendnumber[b] ]=a;
        friendnumber[a]++;
        friendnumber[b]++;
    }
    while(scanf("%d",&party)==1){
        partymember[party]=1;
        for(i=0; i<friendnumber[party]; i++){
            partymember[ friendship[party][i] ]=1;
        }
    }
    for(i=0; i<n; i++){
        if(partymember[i]==0)
            printf("%d\n",i);
    }
return 0;
}
