#include<stdio.h>
void intersection(int map[100][100], int result[4]){
    int i,j,sum=0;
    result[0]=0;
    result[1]=0;
    result[2]=0;
    result[3]=0;
    for (i=0;i<100;i++){
		for(j=0;j<100;j++){
			if(map[i][j]!=0){
                if(i!=0)
                    sum+=map[i-1][j];
                if(i!=99)
                    sum+=map[i+1][j];
                if(j!=0)
                    sum+=map[i][j-1];
                if(j!=99)
                    sum+=map[i][j+1];
				switch (sum){
					case 4:
						result[0]+=1;
						break;
					case 3:
						result[1]+=1;
						break;
					case 2:
						if( ( (i!=0&&map[i-1][j]==1) || (i!=99&&map[i+1][j]==1) ) && ((j!=0&&map[i][j-1]==1)||(j!=99&&map[i][j+1]==1)) )
						result[2]+=1;
						break;
					case 1:
						result[3]+=1;
						break;
				}
				sum=0;
			}
		}
	}
    return;
}
int main(){
	int m[100][100];
	int r[4] = { -1, -1, -1, -1 };
	int i, j;
	for(i=0; i<100; i++)
		for(j=0; j<100; j++){
			scanf("%d", &m[i][j]);
		}
	intersection(m, r);
	for(i=0; i<4; i++)
		printf("%d ", r[i] );
	printf("\n");
	return 0;
}
