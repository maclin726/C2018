#include<stdio.h>
#include<math.h>
int main(){
    int a,b,c,d,e,f,g;
    int h=0,i,j;
    int p;
    scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);
    if(a>=0)                    //´«¦¨°²¤À¼Æ
        b=a*c+b;
    else
        b=a*c-b;
    if(e>=0)
        f=e*g+f;
    else
        f=e*g-f;

    if(d==0){                   //addition
        j=c*g;
        i=c*f+g*b;
    }
    else if(d==1){              //subtraction
        j=c*g;
        i=b*g-c*f;
    }
    else if(d==2){              //multiplication
        j=c*g;
        i=b*f;
    }
    else if(d==3){              //division
        j=abs(c*f);
        i=b*g*(abs(f)/f);
    }
    if(abs(i)>=j){
        h=i/j;
        i=abs(i-h*j);
    }
    if(i==0)
        j=1;
    for(p=2; p<i+1; p++){
        while(i%p==0 && j%p==0){
            i/=p;
            j/=p;
        }
    }
    printf("%d\n%d\n%d",h,i,j);
return 0;
}
