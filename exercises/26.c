#include<stdio.h>
int main(){
    int year,month,day,date,mark2,i,check=0;
    scanf("%d%d%d",&year,&month,&day);
    if(year%400==0 || (year%100!=0 && year%4==0) )
        mark2=1;
    else
        mark2=0;
    switch (month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            date=31;
            break;
        case 4: case 6: case 9: case 11:
            date=30;
            break;
        case 2:
            if(mark2==1)
                date=29;
            if(mark2==0)
                date=28;
            break;
        default:
            printf("invalid");
            check=1;
            break;
    }
    if((day<0 || day>6) && check==0){
        printf("invalid");
        check=1;
    }
    if(check==0){
        printf(" Su Mo Tu We Th Fr Sa\n");
        printf("=====================\n");
        switch(day){
        case 1:
            printf("   ");
            break;
        case 2:
            printf("      ");
            break;
        case 3:
            printf("         ");
            break;
        case 4:
            printf("            ");
            break;
        case 5:
            printf("               ");
            break;
        case 6:
            printf("                  ");
            break;
        }
        for(i=1; i<=date; i++){
            printf("%3d",i);
            if(day%7==6){
                printf("\n");
            }
            day++;
        }
        if((day%7)!=0)
            printf("\n");
        printf("=====================\n");
    }
return 0;
}
