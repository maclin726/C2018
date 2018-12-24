#include<stdio.h>
int main(){
    int d,w;                        //input digit
    int a[20][20];                  //input array
    int c[22][22]={0};
    int i,j;
    int x,y,dir;                    //coordinate, direction(0, up and down; 1, left and right)
    scanf("%d",&w);                 //表寬度
    scanf("%d",&d);                 //表長度
    for (i=0; i<d; i++){            //read whether each block has glass or not
        for(j=0; j<w; j++){
            scanf("%d",&a[i][j]);
        }
    }
    for (i=1; i<d+1; i++){          //各座標向右下角移一格
        for (j=1; j<w+1; j++){
            c[i][j]=a[i-1][j-1];
        }
    }
    for (i=0; i<w; i++){            //下面to上or右
        x=i+1;
        y=d+1;
        dir=0;
        while( x!=w+1 && y!=0 ){
            if(c[y][x]==1){
                if(dir==1)
                    dir=0;
                else if(dir==0)
                    dir=1;
            }
            if(dir==0){
                y--;
            }
            if(dir==1){
                x++;
            }
        }
        if( x==w+1 )
            printf( "%d\n", w+d-y );
        if( y==0 )
            printf( "%d\n", 2*w+d-x );
    }
    for (i=0; i<d; i++){            //右邊to下or左
        x=w+1;
        y=d-i;
        dir=1;
        while( x!=0 && y!=d+1 ){
            if(c[y][x]==1){
                if(dir==1)
                    dir=0;
                else if(dir==0)
                    dir=1;
            }
            if(dir==0){
                y++;
            }
            if(dir==1){
                x--;
            }
        }
        if( x==0 )
            printf( "%d\n", 2*w+d+y-1 );
        if( y==d+1 )
            printf( "%d\n", x-1 );
    }
    for (i=0; i<w; i++){            //上面to下or左
        x=w-i;
        y=0;
        dir=0;
        while( x!=0 && y!=d+1 ){
            if(c[y][x]==1){
                if(dir==1)
                    dir=0;
                else if(dir==0)
                    dir=1;
            }
            if(dir==0){
                y++;
            }
            if(dir==1){
                x--;
            }
        }
        if( x==0 )
            printf( "%d\n", 2*w+d+y-1 );
        if( y==d+1 )
            printf( "%d\n", x-1 );
    }
    for (i=0; i<d; i++){            //左邊ro上or右
        x=0;
        y=i+1;
        dir=1;
        while( x!=w+1 && y!=0 ){
            if(c[y][x]==1){
                if(dir==1)
                    dir=0;
                else if(dir==0)
                    dir=1;
            }
            if(dir==0){
                y--;
            }
            if(dir==1){
                x++;
            }
        }
        if( x==w+1 )
            printf( "%d\n", w+d-y );
        if( y==0 )
            printf( "%d\n", 2*w+d-x );
    }
return 0;
}
//test data 5 4
//0 1 0 1 0
//0 0 1 0 0
//1 0 0 1 1
//0 1 1 0 0
