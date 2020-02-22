#include<stdio.h>

int check(int a, int b, int c){
	if( a > b ){
		int tmp = a;
		a = b, b = tmp;
	}
	if( b > c ){
		int tmp = b;
		b = c, c = tmp;
	}
	if( a > b ){
		int tmp = a;
		a = b, b = tmp;
	}
	return (b-a == 1) && (c-b == 1);
}

int main(){
	int a, b, c, d, e, x;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	int x0 = -1, x1 = -1, x2 = -1;
	int c0 = -100, c1 = -100, c2 = -100;
	while( scanf("%d", &x) != EOF && (!check(c0, c1, c2)) ){
		x0 = x1, x1 = x2, x2 = x;
		c0 = c1, c1 = c2, c2 = 0;
		while( !(d <= x && x <= e) ){
			x = (a * x + b) % c;
			c2++;
		}
	}
	if( check(c0, c1, c2) )
		printf("%d %d %d\n", x0, x1, x2);
	else
		printf("Not found\n");
	return 0;
}