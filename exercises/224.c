#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee{
    int id;
    char first_name[32];
    char last_name[32];
    int boss_id;
};
typedef struct employee Employee; 

void init_storage(Employee **storage, int n)
{
    // allocate memory space to store employee data
    // no need to understand this function now.
 
    (*storage) = (Employee *)malloc(sizeof(Employee) * n);
}
 
void free_storage(Employee **storage)
{
    free(*storage);
    *storage = 0;
}

Employee* find_employee_by_id( Employee *set, int n, int id ){
    for( int i = 0; i < n; i++ )
        if( set[i].id == id )
            return &(set[i]);
}
Employee* find_employee_by_name( Employee *set, int n, const char *first_name, const char *last_name ){
    for( int i = 0; i < n; i++ )
        if( strcmp(set[i].first_name, first_name) == 0 && strcmp( set[i].last_name, last_name ) == 0 )
            return &(set[i]);
}
Employee* find_root_boss( Employee *set, int n, Employee *employee ){
    int boss = employee->boss_id;
    while( boss != find_employee_by_id(set, n, boss)->boss_id ){
        boss = find_employee_by_id(set, n, boss)->boss_id;
    }
    return find_employee_by_id(set, n, boss);
}
int check_relationship(Employee *set, int n, Employee *A, Employee *B){
    int bossA = A->id, bossB = B->id;
    do{ 
        bossA = find_employee_by_id(set, n, bossA)->boss_id;
        if( find_employee_by_id(set, n, bossA) == B )
            return 1;
    }while( bossA != find_employee_by_id(set, n, bossA)->boss_id );

    do{
        bossB = find_employee_by_id(set, n, bossB)->boss_id;
        if( find_employee_by_id(set, n, bossB) == A )
            return 2;
    }while( bossB != find_employee_by_id(set, n, bossB)->boss_id );

    if( bossA == bossB )
        return 3;
    else
        return 0; 
}

int main()
{
    int n, m;
    int i;
    Employee *set = NULL;
 
    scanf("%d", &n);
    init_storage(&set, n);
    for ( i = 0 ; i < n ; i++ )
        scanf("%d %s %s %d", &(set[i].id), set[i].first_name, set[i].last_name, &(set[i].boss_id));
    char first_name_A[32], first_name_B[32];
    char last_name_A[32], last_name_B[32];
    Employee *A, *B;
    int type;
 
    scanf("%d", &m);
    for ( i = 0 ; i < m ; i++ )
    {
        scanf("%s %s", first_name_A, last_name_A);  
        A = find_employee_by_name(set, n, first_name_A, last_name_A);
 
        scanf("%s %s", first_name_B, last_name_B);  
        B = find_employee_by_name(set, n, first_name_B, last_name_B);
 
        type = check_relationship(set, n, A, B);
        switch(type){
            case 1:
                printf("subordinate\n"); break;
            case 2:
                printf("supervisor\n"); break;
            case 3:
                printf("colleague\n"); break;
            default:
                printf("unrelated\n"); break;
        }
    }
    free_storage(&set);
    return 0;
}