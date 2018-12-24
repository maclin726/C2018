#include <stdio.h>
#include<math.h>
int value(int type, int width, int height, int length){
    int money,w,h,temp,i;
    if(type==79 || type==47 || type==29 || type==82 || type==26 || type==22 ){
        switch(type){
        case 79:
            money=30;
            break;
        case 47:
            money=10;
            break;
        case 29:
            money=4;
            break;
        case 82:
            money=5;
            break;
        case 26:
            money=3;
            break;
        case 22:
            money=9;
            break;
        }
        if(width>0 && height>0 && length>0){
            w=fmax(width,height);
            h=fmin(width,height);
            while(w%h!=0){
                temp=h;
                h=w%h;
                w=temp;
            }
            w=fmax(h,length);
            h=fmin(h,length);
            while(w%h!=0){
                temp=h;
                h=w%h;
                w=temp;
            }
            return money*width*height*length*h*h*h;
        }
        else
            return -2;
    }
    else
        return -1;
}

int main(){
		int type, width, height, length;
			while( scanf("%d%d%d%d", &type, &width, &height, &length) != EOF)
						printf("The metal value is %d.\n", value(type,width,height,length));
		return 0;
}
