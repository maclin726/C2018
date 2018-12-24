#include<stdio.h>
int main(){
    int year,mark2,day;
    int n,month,date;
    int i,j,delta=0;
    int check=0;
    scanf("%d%d%d",&year,&day,&n);
    if(year%400==0 || (year%100!=0 && year%4==0) )
        mark2=1;
    else
        mark2=0;
    for(i=0; i<n; i++){
        scanf("%d%d", &month, &date);
        if( month<1 || month>12 ){
            printf("-1\n");
            check=1;
        }
        switch (month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if((date<1 || date>31)&&check!=1){
                printf("-2\n");
                check=1;
            }
            break;
        case 4: case 6: case 9: case 11:
            if((date<1 || date>30)&&check!=1){
                printf("-2\n");
                check=1;
            }
            break;
        case 2:
            if(mark2==1 && check!=1){
                if(date<1 || date>=30){
                    printf("-2\n");
                    check=1;
                }
            }
            if(mark2==0 && check!=1){
                if(date<1 || date>=29){
                    printf("-2\n");
                    check=1;
                }
            }
            break;
        }
        if(check==0){
            for(j=1; j<month; j++){
                switch(j){
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    delta+=31;
                    break;
                case 4: case 6: case 9: case 11:
                    delta+=30;
                    break;
                case 2:
                    if(mark2==1)
                        delta+=29;
                    else
                        delta+=28;
                    break;
                }
            }
            delta+=date;
            printf("%d\n",(delta+day-1)%7);
        }
        check=0;
        delta=0;
    }
return 0;
}
