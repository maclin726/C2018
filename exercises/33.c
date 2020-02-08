#include<stdio.h>
int main(){
	int a[102][102]={0};
	int p=0,q=0,r=0,s=0;
	int i,j;
	int n;
	int sum=0;
	scanf("%d",&n);
	for (i=1;i<(n+1);i++){
		for(j=1;j<(n+1);j++){
			scanf("%d",&a[i][j]);
		}
	}
	for (i=1;i<(n+1);i++){
		for(j=1;j<(n+1);j++){
			if(a[i][j]!=0){
				sum=a[i-1][j]+a[i+1][j]+a[i][j-1]+a[i][j+1];
				switch (sum){
					case 4:
						p++;
						break;
					case 3:
						q++;
						break;
					case 2:
						if(a[i-1][j]+a[i+1][j]==1 && a[i][j-1]+a[i][j+1]==1)
						r++;
						break;
					case 1:
						s++;
						break;
				}
				sum=0;
			}
		}
	}
	printf("%d\n%d\n%d\n%d",p,q,r,s);
	return 0;
}
