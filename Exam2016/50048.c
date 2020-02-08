#include <stdio.h>
#include <stdlib.h>
void count_day(int year, int day, int month, int results[7]){
    int leap_year = 0;
    if ( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        leap_year = 1;
    int days[12],i,count=0;
    for(i = 1; i <= month; i++){
        switch(i){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            days[i-1] = 31;
            break;
        case 4: case 6: case 9: case 11:
            days[i-1] = 30;
            break;
        case 2:
            if(leap_year)
                days[i-1] = 29;
            else
                days[i-1] = 28;
            break;
        }
        if(i != month)
            count += days[i-1];
    }
    for(i = 1; i <= days[month-1]; i++){
        results[ (day + (count-1) + i)%7 ]++;
    }
}

int main(){
    int year, day, month, results[7] = {0}, i;

    while(scanf("%d %d %d", &year, &day, &month) == 3){
        for(i = 0; i < 7; i++)
            results[i] = 0;
        count_day(year, day, month, results);
        for(i = 0; i < 6; i++)
            printf("%d ", results[i]);
        printf("%d\n", results[i]);
    }
    return 0;
}
