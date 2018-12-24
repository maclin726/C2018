#include<stdio.h>
int main(){
	int a[100][100]={0};
	int b[100][100]={0};
	int n,m;
	int i,j;
	scanf("%d", &n);
	scanf("%d", &m);
	for (i=0; i<n; i++){
		for (j=0; j<m; j++)
			scanf("%d", &a[i][j]);
	}
	for (i=1; i<n; i++){		//跟上面比
		for (j=0; j<m; j++){
			if (a[i][j]<=a[i-1][j])
                b[i][j]=1;
		}
	}
	for (i=0; i<(n-1); i++){	//跟下面比
		for (j=0; j<m; j++){
			if (a[i][j]<=a[i+1][j])
                b[i][j]=1;
		}
	}
	for (i=0; i<n; i++){		//跟左邊比
		for (j=1; j<m; j++){
			if (a[i][j]<=a[i][j-1])
                b[i][j]=1;
		}
	}
	for (i=0; i<n; i++){		//跟右邊比
		for (j=0; j<(m-1); j++){
			if (a[i][j]<=a[i][j+1])
                b[i][j]=1;
		}
	}
	for (i=0; i<n; i++){
		for (j=0; j<m; j++)
			if(b[i][j]==0){
            			printf("%d\n",a[i][j]);
			}
	}
	return 0;
}
