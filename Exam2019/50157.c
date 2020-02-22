#include<stdio.h>

int main(){
	int k, CP;
	int deputySUM = 0;
	int wind = 0, fire = 0, water = 0;
	int first = 0, second = 0, complete = 0;
	scanf("%d", &k);
	while( scanf("%d", &CP) != EOF ){
		complete = 0;

		if( CP % 3 == 0 )
			wind++;
		else if( CP % 3 == 1 )
			fire++;
		else if( CP % 3 == 2 )
			water++;

		if( CP >= first ){
			second = first;
			first = CP;
		}
		else if( CP >= second )
			second = CP;

		if( wind >= k && fire >= k && water >= k ){
			deputySUM += second;
			wind = fire = water = first = second = 0;
			complete = 1;
		}
	}
	if( !complete )
		deputySUM += (wind+water+fire == 1)? first: second;

	printf("%d\n", deputySUM);
	return 0;
}