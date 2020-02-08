#include<stdio.h>
#include<ctype.h>
#include<string.h>

enum Type {NOVEL, COMICS, MANUAL, TEXTBOOK};
struct Book {
    char title[128];
    enum Type type;
    char ISBN[128];
    char authors[128];
    unsigned int importance;
};

struct Date {
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

int priority( unsigned int importance ){
    int index[2], count = 0;
    for(int i = 0; i < 32; i++){
        if( ( (importance & ( ((unsigned int)1 << i) )  )!= (unsigned int) 0) && !count ){
            index[0] = i;
            count = 1;
        }
        else if( ( (importance &  ((unsigned int)1 << i ) ) != ((unsigned int) 0) ) && count ){
            index[1] = i;
        }
    }
    return (index[1] - index[0] - 1);
}

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

unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned){
    int days = countDays(date_borrowed, date_returned);
    if( book.type == NOVEL && days > 90 )
        return (days - 90) * priority(book.importance);
    else if( book.type == COMICS && days > 10 )
        return (days - 10) * priority(book.importance);
    else if( book.type == MANUAL && days > 100 )
        return (days - 100) * priority(book.importance);
    else if( book.type == TEXTBOOK && days > 5 )
        return (days - 5) * priority(book.importance);
    return 0;
}

int main(){
    struct Book book = {
        "Neon Genesis Evangelion",
        COMICS,
        "978-159-116-400-5",
        "Yoshiyuki Sadamoto",
        17
    };
    struct Date date_borrowed, date_returned;
    date_borrowed.year  = 2007;
    date_borrowed.month = 11;
    date_borrowed.day   = 14;
    date_returned.year  = 2007;
    date_returned.month = 12;
    date_returned.day   = 3;
    printf("The fine is $%d.\n", library_fine(book, date_borrowed, date_returned));
    return 0;
}