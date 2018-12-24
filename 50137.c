#include<stdio.h>
#include<math.h>

int can_stack( int w1, int l1, int w2, int l2 ){
    return (w1 <= l1 && w2 <= l2);
}

int stack(int n, int size[][2], int max_stack[], int w, int l, int now){
    if( now == n )
        return 0;
    int can_stack = ( size[now][0] <= w && size[now][1] <= l )? 1: 0;

    int stack_not_with_now = stack(n, size, max_stack, w, l, now + 1);
    
    if( can_stack &&  max_stack[now]*100000 > stack_not_with_now ){
        int stack_with_now = stack(n, size, max_stack, size[now][0], size[now][1], now + 1) + 100000 + now;
        if( stack_with_now >= stack_not_with_now )
            return stack_with_now;
    }
    return stack_not_with_now;
}

int main(){
    int n;
    scanf("%d", &n);
    int size[200][2];
    for( int i = 0; i < n; i ++ ){
        int l, d;
        scanf("%d%d", &l, &d);
        size[i][0] = fmin(l,d);
        size[i][1] = fmax(l,d);
    }
    int max_stack[200] = {0};
    for( int i = 0; i < n; i++ )
        for( int j = i; j < n; j++ )
            if( can_stack( size[j][0], size[i][0], size[j][1], size[i][1] ) )
                max_stack[i]++;

    int max_number = stack(n, size, max_stack, 10000, 10000, 0);
    printf("%d %d", max_number / 100000, max_number % 100000);
}