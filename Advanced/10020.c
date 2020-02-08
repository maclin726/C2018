#include<stdio.h>
#include<math.h>
int main(){
    double a,b,c;
    while( scanf("%lf%lf%lf",&a,&b,&c) != EOF ){
        double f;
        f = ( -b - sqrt(b * b - 4 * a * c) ) / (2 * a);
        printf("%.20lf ", f);
        f = ( -b + sqrt(b * b - 4 * a * c) ) / (2 * a);
        printf("%.20lf\n", f);
    }
return 0;
}
