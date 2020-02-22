#include<stdio.h>

int seat[1024][24][8];
int last_single[3] = {1,1,1}, last_double[3] = {1,1,1};
int N;

int next_single(){
	while( seat[last_single[0]][last_single[1]][last_single[2]] == 1 ){
		last_single[2]++;
		if( last_single[2] > 5 ){
			last_single[1]++;
			last_single[2] = 1;
		}
		if( last_single[1] > 20 ){
			last_single[0]++;
			last_single[1] = 1;
		}
	}
	if( last_single[0] > N )
		return -1;
	return 0;
}

int next_double(){
	while( last_double[2] == 3 || last_double[2] == 5 || 
		seat[last_double[0]][last_double[1]][last_double[2]] == 1 || 
		seat[last_double[0]][last_double[1]][last_double[2]+1] == 1 ){
		last_double[2]++;
		if( last_double[2] > 5 ){
			last_double[1]++;
			last_double[2] = 1;
		}
		if( last_double[1] > 20 ){
			last_double[0]++;
			last_double[1] = 1;
		}
	}
	if( last_double[0] > N )
		return -1;
	return 0;
}

int main(){
	int R;
	scanf("%d", &N);
	while( scanf("%d", &R) != EOF ){
		if( R == 1 ){
			next_single();
			seat[last_single[0]][last_single[1]][last_single[2]] = 1;
			printf("%d %d %d\n", last_single[0], last_single[1], last_single[2]);
		}
		else if( R == 2 ){
			if( next_double() == 0 ){
				seat[last_double[0]][last_double[1]][last_double[2]] = seat[last_double[0]][last_double[1]][last_double[2]+1] = 1;
				printf("%d %d %d %d %d %d\n", last_double[0], last_double[1], last_double[2], last_double[0], last_double[1], last_double[2]+1);
			}
			else{
				next_single();
				seat[last_single[0]][last_single[1]][last_single[2]] = 1;
				int first[3] = {last_single[0], last_single[1], last_single[2]};
				next_single();
				seat[last_single[0]][last_single[1]][last_single[2]] = 1;
				printf("%d %d %d %d %d %d\n", first[0], first[1], first[2], last_single[0], last_single[1], last_single[2]);
			}
		}
	}
	return 0;
}