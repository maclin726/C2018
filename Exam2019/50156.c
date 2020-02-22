#include<stdio.h>

int main(){
	int a, b, v, w, x, y, z;
	scanf("%d%d%d%d%d%d%d", &a, &b, &v, &w, &x, &y, &z);
	int maxS = 0, maxM = 1; //M for mother, S for som

	if( a % 2 == 1 ){
		if( maxS * a < maxM * v )
			maxS = v, maxM = a;
		if( maxS * (a+1) < maxM * w )
			maxS = w, maxM = (a+1);
	}
	else{
		if( maxS * a < maxM * w )
			maxS = w, maxM = a;
		if( maxS * (a+1) < maxM * v )
			maxS = v, maxM = (a+1);
	}

	if( b % 3 == 0 ){
		if( maxS * b < maxM * x )
			maxS = x, maxM = b;
		if( maxS * (b+1) < maxM * y )
			maxS = y, maxM = (b+1);
		if( maxS * (b+2) < maxM * z )
			maxS = z, maxM = (b+2);
	}
	else if( b % 3 == 1 ){
		if( maxS * b < maxM * y )
			maxS = y, maxM = b;
		if( maxS * (b+1) < maxM * z )
			maxS = z, maxM = (b+1);
		if( maxS * (b+2) < maxM * x )
			maxS = x, maxM = (b+2);
	}
	else{
		if( maxS * b < maxM * z )
			maxS = z, maxM = b;
		if( maxS * (b+1) < maxM * x )
			maxS = x, maxM = (b+1);
		if( maxS * (b+2) < maxM * y )
			maxS = y, maxM = (b+2);
	}

	printf("%d\n", maxM);
	return 0;
}