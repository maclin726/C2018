#include<stdio.h>
int main(){
    int arrive,a,b,timea=0,timeb=0;
    while(scanf("%d%d%d",&arrive,&a,&b)!=EOF){
        if( arrive<=timea ){
            timea+=a;
        }
        else if( arrive>timea ){
            timea=arrive;
            timea+=a;
        }
        if(timeb<=timea){
            timeb=timea;
            timeb+=b;
        }
        else if(timeb>timea){
            timeb+=b;
        }
        printf("%d\n",timeb);
    }
return 0;
}
