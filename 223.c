#include<stdio.h>
void tileA(int l , int m, int x, int y);
void tileB(int l , int m, int x, int y);
void tileC(int l , int m, int x, int y);
void tileD(int l , int m, int x, int y);

void tileA(int l, int m, int x, int y){
    if( m != l/2 ){
        tileA( l, l/2, x, y );
        tileA( l/2, m, x + l/4, y + l/4);
        return;
    }
    if( l == 2 && m == 1 ){
        printf("1 %d %d\n",x, y);
        return;
    }
    tileA( l/2, l/4, x, y );
    tileA( l/2, l/4, x - l/4, y - l/4);
    tileB( l/2, l/4, x + l/4, y - l/4);
    tileD( l/2, l/4, x - l/4, y + l/4);
    return;
}
void tileB(int l, int m, int x, int y){
    if( l == 2 && m == 1 ){
        printf("2 %d %d\n",x, y);
        return;
    }
    tileB( l/2, l/4, x, y );
    tileB( l/2, l/4, x + l/4, y - l/4);
    tileC( l/2, l/4, x + l/4, y + l/4);
    tileA( l/2, l/4, x - l/4, y - l/4);
    return;
}
void tileC(int l, int m, int x, int y){
    if( l == 2 && m == 1 ){
        printf("3 %d %d\n",x, y);
        return;
    }
    tileC( l/2, l/4, x, y );
    tileC( l/2, l/4, x + l/4, y + l/4);
    tileB( l/2, l/4, x + l/4, y - l/4);
    tileD( l/2, l/4, x - l/4, y + l/4);
    return;
}
void tileD(int l, int m, int x, int y){
    if( l == 2 && m == 1 ){
        printf("4 %d %d\n",x, y);
        return;
    }
    tileD( l/2, l/4, x, y );
    tileD( l/2, l/4, x - l/4, y + l/4);
    tileC( l/2, l/4, x + l/4, y + l/4);
    tileA( l/2, l/4, x - l/4, y - l/4);
    return;
}
int main(){
    int l,m;
    scanf("%d%d",&l,&m);
    tileA(l, m, l/2, l/2);
    return 0;
}