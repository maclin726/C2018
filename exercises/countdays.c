#include<stdio.h>

struct Date{
    unsigned year;
    unsigned month;
    unsigned day;
};

int yearcount( unsigned int year ){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)? 366:365;
}

int monthcount( unsigned int year, unsigned int month ){
    switch (month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            if( yearcount(year) == 366 )
                return 29;
            else
                return 28;
    }
}

int countDays( struct Date date_borrowed, struct Date date_returned ){
    int days = 0;
    for( unsigned int i = date_borrowed.year + 1; i < date_returned.year; i++ )
        days += yearcount(i);
    if( date_returned.year > date_borrowed.year ){
        for( unsigned int i = date_borrowed.month + 1; i <= 12; i++ )
            days += monthcount(date_borrowed.year, i);
        for( unsigned int i = 1; i < date_returned.month; i++ )
            days += monthcount(date_returned.year, i);
        days += monthcount(date_borrowed.year, date_borrowed.month) - date_borrowed.day + 1;
        days += date_returned.day;
    }
    else{
        for( unsigned int i = date_borrowed.month + 1; i < date_returned.month; i++ )
            days += monthcount(date_borrowed.year, i);
        if( date_returned.month > date_borrowed.month ){
            days += monthcount(date_borrowed.year, date_borrowed.month) - date_borrowed.day + 1;
            days += date_returned.day;
        }
        else
            days += date_returned.day - date_borrowed.day + 1;
    }
    return days;
}

int main(){
    struct Date Date1, Date2;
    scanf("%d%d%d%d%d%d", &Date1.year, &Date1.month, &Date1.day, &Date2.year, &Date2.month, &Date2.day);
    printf("%d", countDays(Date1, Date2));
    return 0;
}