#include <stdio.h>
#include <math.h>

typedef struct{
	int x;
	int y;
	int area;
}rectangle;

typedef struct{
	int number;
	int sumArea;
}solution;

solution better(solution a, solution b);
solution stack(int topx, int topy, rectangle Rec[], int n, int i, solution Sol);

int canStack( rectangle a, int topx, int topy ){
	#ifdef LARGEONSMALL
	return( (a.x >= topx && a.y >= topy) || (a.x >= topy && a.y >= topx) );
	#endif

	#ifdef SMALLONLARGE
	return( (a.x <= topx && a.y <= topy) || (a.x <= topy && a.y <= topx) );
	#endif
}

solution better(solution a, solution b){
	if( a.number > b.number )
		return a;
	else if( a.number < b.number )
		return b;

	#ifdef MAXAREASUM
		return (a.sumArea >= b.sumArea)? a: b;
	#endif

	#ifdef MINAREASUM
		return (a.sumArea <= b.sumArea)? a: b;
	#endif
}

solution stack(int topx, int topy, rectangle Rec[], int n, int i, solution Sol){
	if( n == i )
		return Sol;
	if( canStack(Rec[i], topx, topy) ){
		solution topped = Sol;
		topped.number ++;
		topped.sumArea += Rec[i].area;
		return better( stack(topx, topy, Rec, n, i+1, Sol), 
					   stack(Rec[i].x, Rec[i].y, Rec, n, i+1, topped) );
	}
	else
		return stack(topx, topy, Rec, n, i+1, Sol);
}

int main(){
	int n;
	rectangle Rec[1000];

	scanf("%d", &n);
	for( int i = 0; i < n; i++ ){
		scanf("%d%d", &Rec[i].x, &Rec[i].y);
		Rec[i].area = Rec[i].x * Rec[i].y;
	}

	int topx, topy;
	#ifdef SMALLONLARGE
		topx = 2147483647;
		topy = 2147483647;
	#endif

	#ifdef LARGEONSMALL
		topx = 0;
		topy = 0;
	#endif
	solution bestsolution;
	bestsolution.number = 0;
	bestsolution.sumArea = 0;
	bestsolution = stack(topx, topy, Rec, n, 0, bestsolution);

	printf("%d %d\n", bestsolution.number, bestsolution.sumArea);
	return 0;
}