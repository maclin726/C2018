#include<stdio.h>
int k,n,m;
int number[20];
int count = 0;
void pick_number(int k, int m, int index){
    if( k == 0 && m >= 0){
        count++;
        return;
    }
    else if( m < 0 || index == n )
        return;
    pick_number(k-1, m-number[index], index+1);
    pick_number(k, m, index+1);
}
int main(){
    scanf("%d%d%d", &k, &n, &m);
    int i;
    for( i = 0; i < n; i++)
        scanf("%d", &number[i]);
    for( i = k; i <= n; i++ ){
        pick_number( i, m, 0);
    }
    printf("%d",count);
    return 0;
}