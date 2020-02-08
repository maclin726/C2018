#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
    int a,b,c,d,e,f;
    int end=0;
    scanf("%d%d%d",&a,&b,&c);
    if(c==0){
        if(b==0){
            if(a==0)
                printf("0 0 0");
            else if(a<0)
                printf("%d 0 0",a);
            else
                printf("0 0 %d",a);
        }
        else{
            d=(a+sqrt(a*a-4*b))/2;
            e=(a-sqrt(a*a-4*b))/2;
            if(e>0)
                printf("0 %d %d",e,d);
            else if(e<0 && d<0)
                printf("%d %d 0",e,d);
            else if(e<0 && d>0)
                printf("%d 0 %d",e,d);
        }
    }
    else{
        for (d=-abs(c); d<=(a/3)&&end==0; d++){
            if(d!=0 && c%d==0){                         //check d
                for(e=-abs(c/d); e<=abs(c/d)&& end==0; e++){   //check e
                    if(e!=0 && c%e==0){
                        f=a-d-e;
                        if(d*e+d*f+e*f==b && d*e*f==c && d<=e && e<=f){ //check f
                            printf("%d %d %d",d,e,f);
                            end=1;
                        }
                    }
                }
            }
        }
    }
return 0;
}
