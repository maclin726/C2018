#include<stdio.h>
#include<stdlib.h>
    int a[1024][1024]={0};
int main(){
    int i,j;
    int row[1024], column[1024];
    int n,m,sx,sy,ex,ey;
    scanf("%d%d%d%d%d%d",&n,&m,&sx,&sy,&ex,&ey);
    int length;
    length = abs(sx-ex) + abs(sy-ey) + 1;
    int head = 0, tail = length-1;
    int check = 0;
    if( sx == ex ){
        if(sy > ey)
            for(i = 0 ; i < length; i++){
                row[i] = sx;
                column[i] = sy - i;
            }
        else
            for(i = 0 ; i < length; i++){
                row[i] = sx;
                column[i] = sy + i;
            }
    }
    else if( sy == ey ){
        if(sx > ex)
            for(i = 0 ; i < length; i++){
                row[i] = sx - i;
                column[i] = sy;
            }
        else
            for(i = 0 ; i < length; i++){
                row[i] = sx + i;
                column[i] = sy;
            }
    }
#ifdef DEBUG
    for(i=0; i<length; i++){
        printf("%d ",row[i]);
    }
    printf("\n");
    for(i=0; i<length; i++){
        printf("%d ",column[i]);
    }
    printf("\n");
    printf("head=%d, tail=%d\n",head,tail);
#endif
    int q,d;
    scanf("%d",&q);
    for (i = 0; i < q && check == 0; i++){
        scanf("%d",&d);
        if(d == 0){
            if(row[head]+1 < n){
                for(j=0; j<length; j++){
                    if(j!= tail && row[head]+1 == row[j] && column[head] == column[j])
                    check = 1;
                }
                if(check == 0){
                    row[tail] = row[head]+1;
                    column[tail] = column[head];
                    head = tail;
                    if(tail > 0)
                        tail--;
                    else
                        tail = length-1;
                }
            }
            else
                check = 1;
        }
        else if(d == 1){
            if(row[head]-1 >= 0){
                for(j=0; j<length; j++){
                    if(j!=tail && row[head]-1 == row[j] && column[head] == column[j])
                    check = 1;
                }
                if(check == 0){
                    row[tail] = row[head]-1;
                    column[tail] = column[head];
                    head = tail;
                    if(tail > 0)
                        tail--;
                    else
                        tail = length-1;
                }
            }
            else
                check = 1;
        }
        else if(d == 2){
            if(column[head]+1 < m){
                for(j=0; j<length; j++){
                    if(j!=tail && row[head] == row[j] && column[head]+1 == column[j])
                    check = 1;
                }
                if(check == 0){
                    column[tail] = column[head]+1;
                    row[tail] = row[head];
                    head = tail;
                    if(tail > 0)
                        tail--;
                    else
                        tail = length-1;
                }
            }
            else
                check = 1;
        }
        else if( d == 3){
            if(column[head]-1 >= 0){
                for(j=0; j<length; j++){
                    if(j!=tail && row[head] == row[j] && column[head]-1 == column[j])
                    check = 1;
                }
                if(check == 0){
                    column[tail] = column[head]-1;
                    row[tail] = row[head];
                    head = tail;
                    if(tail > 0)
                        tail--;
                    else
                        tail = length-1;
                }
            }
            else
                check = 1;
        }
#ifdef DEBUG
        for(j=0; j<length; j++){
            printf("%d ",row[j]);
        }
        printf("\n");
        for(j=0; j<length; j++){
            printf("%d ",column[j]);
        }
        printf("\n");
        printf("head=%d tail=%d\n",head,tail);
#endif
    }
    for (i = 0; i < length; i++){
        a[ row[i] ][ column[i] ] = 1;
    }
    for (i = 0; i < n; i++){
        for(j = 0; j < m; j++)
            printf("%d",a[i][j]);
        printf("\n");
    }
return 0;
}
