#include<stdio.h>

int main(){
	int healer[5000], tank[5000], DPS[5000];
	int h_rear = 0, t_rear = 0, D_rear = 0;
	int h_front = 0, t_front = 0, D_front = 0;
	int N;
	while( scanf("%d", &N) != EOF ){
		if( N % 3 == 0 ){
			DPS[D_rear++] = N;
			D_rear %= 5000;
		}
		else if( N % 3 == 1 ){
			healer[h_rear++] = N;
			h_rear %= 5000;
		}
		else{
			tank[t_rear++] = N;
			t_rear %= 5000;
		}

		if( (h_rear-h_front+5000) % 5000 >= 1 && (t_rear-t_front+5000)%5000 >= 1 && (D_rear-D_front+5000)%5000 >= 3 ){
			printf("%d %d %d %d %d\n", DPS[D_front], DPS[(D_front+1) % 5000], DPS[(D_front+2) % 5000], 
				healer[h_front], tank[t_front]);
			h_front = (h_front + 1) % 5000;
			t_front = (t_front + 1) % 5000;
			D_front = (D_front + 3) % 5000;
		}
	} 
	return 0;
}