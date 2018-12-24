#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct data{
    char lastname[128];
    char firstname[128];
    char ID[128];
    int salary;
    int age;
}Data;
int judge( Data *people, char compare, char op, char value[] ){
    if( compare == 'l' ){
        if( op == '=' && strcmp( people->lastname, value ) == 0 )
            return 1;
        else if( op == '!' && strcmp( people->lastname, value ) != 0 )
            return 1;
    }
    if( compare == 'f' ){
        if( op == '=' && strcmp( people->firstname, value ) == 0 )
            return 1;
        else if( op == '!' && strcmp( people->firstname, value ) != 0 )
            return 1;
    }
    if( compare == 'I' ){
        if( op == '=' && strcmp( people->ID, value ) == 0 )
            return 1;
        else if( op == '!' && strcmp( people->ID, value ) != 0 )
            return 1;
    }
    if( compare == 's' ){
        int number = atoi(value);
        if( op == '=' && (people->salary == number) )
            return 1;
        else if( op == '>' && (people->salary > number) )
            return 1;
        else if( op == '<' && (people->salary < number) )
            return 1;
    }
    if( compare == 'a' ){
        int number = atoi(value);
        if( op == '=' && people->age == number )
            return 1;
        else if( op == '>' && people->age > number )
            return 1;
        else if( op == '<' && people->age < number )
            return 1;
    }
    return 0;
}
void print( Data *people, char class[][16], int count ){
    for( int i = 0; i < count; i++ ){
        if( class[i][0] == 'f' )                    //firstname
            printf("%s", people->firstname);
        else if( class[i][0] == 'l' )               //lastname 
            printf("%s", people->lastname);
        else if( class[i][0] == 'I' )               //ID
            printf("%s", people->ID);
        else if( class[i][0] == 's' )               //salary
            printf("%d", people->salary);
        else if( class[i][0] == 'a' )               //age
            printf("%d", people->age);
        printf((i == count-1)? "\n":" ");
    }
    return;
}
int main(){
    int N;
    Data people[50];
    scanf("%d", &N);
    for( int i = 0; i < N; i++ ){
        scanf("%s", people[i].lastname);
        scanf("%s", people[i].firstname);
        scanf("%s", people[i].ID);
        scanf("%d", &people[i].salary);
        scanf("%d", &people[i].age);
    }
    int M;
    scanf("%d", &M);
    char select[8];
    for( int i = 0; i < M; i++ ){
        scanf("%s", select);
        int count = 0;
        char input[8] = {'\0'};
        char class[8][16] = {'\0'};
        while( scanf("%s",input) != 0 ){
            if( strcmp( input, "where" ) == 0 )
                break;
            else{
                strcpy( class[count], input );
                count++;
            }
        }
        char compare[16], op[4], value[128];
        scanf("%s%s%s", compare, op, value);
        for( int j = 0; j < N; j++ )
            if( judge( &(people[j]), compare[0], op[0], value) )
                print( &(people[j]), class, count );
    }
    return 0;
}