#include<stdio.h>

int main(){
	int N;
	int map[128];
	int card[100000];
	scanf("%d", &N);
	for( int i = 0; i < 128; i++ )
		map[i] = -1;
	for(int i = 0; i < N; i++){
		scanf("%d", &card[i]);
		if( map[card[i]] != -1 ){
			printf("%d %d %d\n", i, map[card[i]], card[i]);
			map[card[i]] = -1;
		}
		else{
			printf("%d\n", i);
			map[card[i]] = i;
		}
	}
	return 0;
}