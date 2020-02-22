#include<stdio.h>

int main(){
	int a, b, c, d, e, f, g;
	scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
	int water = a * b * d;
	int waterSurface = a*b - e*f;
	int waterWithIron = waterSurface * g;
	int newHeight;
	if( waterWithIron <= water ){
		newHeight = g + (water - waterWithIron) / (a*b);
	}
	else{
		newHeight = water / waterSurface;
	}
	if( newHeight > c )
		newHeight = c;
	if( (waterSurface == 0 && g >= c) || (d == 0) )
		newHeight = 0;
	printf("%d\n", newHeight);

	return 0;
}