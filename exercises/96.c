#include<stdio.h>
int main(){
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    double area;
    area=c*c*3.1415926*3/4;
    if(c>=a)
        area+=(c-a)*(c-a)*3.1415926/4;
    if(c>=b)
        area+=(c-b)*(c-b)*3.1415926/4;
    printf("%f",area);
return 0;
}
