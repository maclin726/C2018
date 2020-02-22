#include <stdio.h>
#include <math.h>
 
double count_value(double x, int d, double coe[]){
    double ans = 0;
    for( int i = 0; i <= d ; i++ ){
        double tmp = coe[i];
        for( int j = 1; j <= i; j++ )
            tmp *= x;
        ans += tmp;
    }
    return ans;
}
 
int main(){
    double coe[16], dif[16];
    int d;
    scanf("%d", &d);
    for( int i = d; i >= 0; i-- ){
        scanf("%lf", &coe[i]);
    }
    int k;
    double x;
    scanf("%d%lf", &k, &x);
    for( int i = 1; i <= d; i++ ){
        dif[i-1] = coe[i] * i;      //differentiation
    }
 
    for( int i = 0; i < k; i++ ){
        double y = count_value(x,d,coe);
        printf("%.4f %.4f\n", x, y);
        double slope = count_value(x, d-1, dif);
        x = (x - y/slope);
    }
    return 0;
}