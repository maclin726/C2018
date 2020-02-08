#include<stdio.h>
int count = 0;
void sum( int number[15], int n, int total, int current_index){
    if( total == 0 ){
        count++;
        return;
    }
    int i;
    for( i = current_index; i < n; i++ )
        if( total >= number[i] )
            sum(number, n, (total - number[i]), i+1);
}
int main(){
    int n, k;
    int number[15];
    scanf("%d", &n);
    int i;
    for( i = 0; i < n ; i++)
        scanf("%d", &number[i]);
    while( scanf("%d", &k) != EOF ){
        sum(number, n, k, 0);
        printf("%d\n",count);
        count = 0;
    }
    return 0;
}