#include<stdio.h>

int main(){
	int R, MAX_H, g, bA, eA, cA, bB, eB, cB, bC, eC, cC, base;
	scanf("%d", &R);
	scanf("%d%d", &MAX_H, &g);
	scanf("%d%d%d", &bA, &eA, &cA);
	scanf("%d%d%d", &bB, &eB, &cB);
	scanf("%d%d%d", &bC, &eC, &cC);
	scanf("%d", &base);

	int lastA = -1, lastB = -1, lastC = -1, H = MAX_H;
	for( int round = 0; round < R; round++ ){
		int skill = 4, max_attack = base;
		if( (lastC == -1 && ( (round <= cC && bC >= max_attack) || (round > cC && bC+(round-cC)*eC >= max_attack) ) ) || 
			( lastC != -1 && (round - lastC) >= cC && (bC+(round-lastC-cC)*eC) >= max_attack ) ){
			skill = 3;
			if( lastC == -1 && round <= cC )
				max_attack = bC;
			else if( lastC == -1 && round > cC )
				max_attack = bC+(round-cC)*eC;
			else
				max_attack = bC+(round-lastC-cC)*eC;
		}
		if( (lastB == -1 && ((round <= cB && bB >= max_attack) || (round > cB && bB+(round-cB)*eB >= max_attack))) || 
			( lastB != -1 && (round - lastB) >= cB && (bB+(round-lastB-cB)*eB) >= max_attack) ){
			skill = 2;
			if( lastB == -1 && round <= cB )
				max_attack = bB;
			else if( lastB == -1 && round > cB )
				max_attack = bB+(round-cB)*eB;
			else
				max_attack = bB+(round-lastB-cB)*eB;
		}
		if( (lastA == -1 && ((round <= cA && bA >= max_attack) || (round > cA && bA+(round-cA)*eA >= max_attack))) || 
			( lastA != -1 && (round - lastA) >= cA && (bA+(round-lastA-cA)*eA) >= max_attack) ){
			skill = 1;
			if( lastA == -1 && round <= cA )
				max_attack = bA;
			else if( lastA == -1 && round > cA )
				max_attack = bA+(round-cA)*eA;
			else
				max_attack = bA+(round-lastA-cA)*eA;
		}

		H -= max_attack;
		if( skill == 1 )
			lastA = round;
		else if( skill == 2 )
			lastB = round;
		else if( skill == 3 )
			lastC = round;
		printf("%d", H);
		if( H <= 0 )
			break;
		else{
			H = (H+g) >= MAX_H? MAX_H:H+g;
			printf(" ");
		}
	}
	return 0;
}