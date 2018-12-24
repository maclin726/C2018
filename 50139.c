#include <stdio.h>
#include <string.h>
#include <math.h>

struct Class{
    int academic_credit;  
    char score[3];
};
struct Student{
    char name[20];
    int N_class; // total number of classes the student takes.
    int N_credit; // total number of academic credits.
    double GPA;
    struct Class all_class[10];
};

double char2GPA(char score[]){
    if( strcmp("A+", score) == 0 )
        return 4.3;
    else if( strcmp("A", score) == 0 )
        return 4.0;
    else if( strcmp("A-", score) == 0 )
        return 3.7;
    else if( strcmp("B+", score) == 0 )
        return 3.3;
    else if( strcmp("B", score) == 0 )
        return 3.0;
    else if( strcmp("B-", score) == 0 )
        return 2.7;
    else if( strcmp("C+", score) == 0 )
        return 2.3;
    else if( strcmp("C", score) == 0 )
        return 2.0;
    else if( strcmp("C-", score) == 0 )
        return 1.7;
    else if( strcmp("F", score) == 0 )
        return 0;
}

void countGPA( struct Student *student ){
    student->N_credit = 0;
    for( int i = 0; i < student->N_class; i++ ){
        student->N_credit += student->all_class[i].academic_credit;
        student->GPA += char2GPA(student->all_class[i].score) * student->all_class[i].academic_credit;
    }
    student->GPA /= student->N_credit;
    return; 
}
 
void GPA_calculation(struct Student all_student[], int N){
    for( int i = 0; i < N; i++ )
        countGPA( &all_student[i] );
    struct Student *ptr[10000];
    for( int i = 0; i < N; i++ )
        ptr[i] = &all_student[i];
    for( int i = 0; i < N; i++ )
        for( int j = N-1; j > i; j-- )
            if( ptr[j]->GPA > ptr[j-1]->GPA ){
                struct Student *temp = ptr[j];
                ptr[j] = ptr[j-1];
                ptr[j-1] = temp;
            }
    int people;
    if( N % 20 == 0 )
        people = N/20;
    else
        people = N/20 + 1 ;
    for( int i = 0; i < people; i++ )
        if( ptr[i]->GPA >= 3.38 && (ptr[i]->N_credit) >= 15 )
            printf("%d %s %lf\n", i+1, ptr[i]->name, ptr[i]->GPA);
    return;
}

int main(int argc, char const *argv[])
{
    struct Student all_student[10000];
    int N, i, j;
 
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%s%d", all_student[i].name, &all_student[i].N_class);
        for(j = 0; j < all_student[i].N_class; j++){
            scanf("%d%s", &all_student[i].all_class[j].academic_credit, all_student[i].all_class[j].score);
        }
        all_student[i].N_credit = 0;
        all_student[i].GPA = 0.0;
    }
 
    GPA_calculation(all_student, N);
 
    return 0;
}