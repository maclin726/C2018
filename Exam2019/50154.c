#include<stdio.h>

int main(){
	int a, b, c, d, e, f, g;
	scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
	int edge, path;
	edge = a + b + c + d + (a+b+c)*e + (c+d)*f + (e*g) + f + g;
	path = a*e*g + b*e*g + c*e*g + c*f + d*f;
	printf("%d\n%d\n", edge, path);	
	return 0;
}