#include<stdio.h>
#include<stdlib.h>
int dis(int a, int b, int c, int d, int e, int f){
    int minus;
    minus = abs(a-d) + abs(b-e) + abs(c-f);
    return minus;
}

int main(){
    int x0,y0,z0,mx,my,mz,bx,by,bz;
    scanf("%d%d%d%d%d%d%d%d%d",&x0,&y0,&z0,&mx,&my,&mz,&bx,&by,&bz);
    int n,instruction;
    scanf("%d",&n);
    int i, mine = 0 ,hole = 0 ,count = 0;
    for (i=0; i<n && mine == 0; i++){
        scanf("%d",&instruction);
        count++;
        switch(instruction){
        case 1:
            x0++;
            break;
        case 2:
            x0--;
            break;
        case 3:
            y0++;
            break;
        case 4:
            y0--;
            break;
        case 5:
            z0++;
            break;
        case 6:
            z0--;
            break;
        }
        if( dis(x0,y0,z0,mx,my,mz) < 10 ){
            x0 = mx;
            y0 = my;
            z0 = mz;
            mine = 1;
        }
        else if( dis(x0,y0,z0,bx,by,bz) < 10 && mine == 0 && hole == 0){
            x0 = bx;
            y0 = by;
            z0 = bz;
            hole = 1;
        }
        if(count % 5 == 0 && mine != 1){
            printf("%d %d %d\n",x0,y0,z0);
        }
    }
return 0;
}
