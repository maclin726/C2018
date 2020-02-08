#include<stdio.h>

int countSol(int map[][100], int R, int C){
	int solution[100][100] = {1};
	solution[0][0] = 1;
	for( int i = 1; i < R; i++ ){
		solution[i][0] = (map[i][0] == 0)? solution[i-1][0]:0; 
	}
	for( int j = 1; j < C; j++ ){
		solution[0][j] = (map[0][j] == 0)? solution[0][j-1]:0;
	}

	for( int i = 1; i < R; i++ ){
		for( int j = 1; j < C; j++ ){
			if( map[i][j] == 0 )
				solution[i][j] = solution[i][j-1] + solution[i-1][j];
			if( solution[i][j] >= 10000 )
				solution[i][j] %= 10000;
		}
	}
	return solution[R-1][C-1];
}

int main(){
	int R = 0, C = 0;
	int map[100][100] = {0};
	while( scanf("%d%d", &R, &C) != EOF ){
		for( int i = 0; i < R; i++ ){
			for( int j = 0; j < C; j++ ){
				scanf("%d", &map[i][j]);
			}
		}
		printf("%d\n", countSol(map, R, C));
	}
	return 0;
}