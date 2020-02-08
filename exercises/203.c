#include <stdio.h>
int main(){
	int x,y,x1,y1,x2,y2,dx1,dy1,dx2,dy2,t;
	int time,temp;
	scanf("%d%d%d%d%d%d%d%d%d%d%d",&x,&y,&x1,&y1,&x2,&y2,&dx1,&dy1,&dx2,&dy2,&t);
	for(time=1; time<=t; time++){
        if(x1==1||x1==x)
			dx1=(-dx1);
		if(x2==1||x2==x)
			dx2=(-dx2);
		if(y1==1||y1==y)
			dy1=(-dy1);
        if(y2==1||y2==y)
			dy2=(-dy2);
		if((x1==x2) && (y1==y2)){
			temp=dx1;
			dx1=dx2;
			dx2=temp;
			temp=dy1;
			dy1=dy2;
			dy2=temp;
		}
		x1+=dx1;
		y1+=dy1;
		x2+=dx2;
		y2+=dy2;
	}
    printf("%d\n%d\n%d\n%d\n",x1,y1,x2,y2);
	return 0;
}
