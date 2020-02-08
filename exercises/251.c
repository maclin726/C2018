#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct employee {
  char first_name[32];
  char last_name[32];
  struct employee *boss;
} Employee;
 
int relation(Employee *employee1, Employee *employee2){
    Employee *boss1[32] = {employee1->boss};
    Employee *boss2[32] = {employee2->boss};
    int boss_cnt1 = 1, boss_cnt2 = 1;
    while( boss1[boss_cnt1-1] != boss1[boss_cnt1-1]->boss ){
        boss1[boss_cnt1] = boss1[boss_cnt1-1]->boss;
        boss_cnt1++;
    }
    while( boss2[boss_cnt2-1] != boss2[boss_cnt2-1]->boss ){
        boss2[boss_cnt2] = boss2[boss_cnt2-1]->boss;
        boss_cnt2++;
    }
    for( int i = 0; i < boss_cnt1; i++ )
        if( boss1[i] == employee2 )
            return 1;
    for( int i = 0; i < boss_cnt2; i++ )
        if( boss2[i] == employee1 )
            return 2;
    for( int i = 0; i < boss_cnt1; i++ )
        for( int j = 0; j < boss_cnt2; j++ )
            if( boss1[i] == boss2[j] )
                return 3;
    return 4;
}

typedef struct me {
    int id;
    char first_name[32];
    char last_name[32];
    int boss_id;
} employee;
void readName(employee *e) {
    scanf("%s %s", e->first_name, e->last_name);
}
int nameToIndex(employee *e, employee A[], int n) {
    for (int i = 0; i < n; i++) {
        if (!strcmp(A[i].first_name, e->first_name) &&
            !strcmp(A[i].last_name, e->last_name))
            return i;
    }
    return -1;
}
int main() {
    int n, m;
    employee A[32];
    Employee B[32];
    const char out[4][32] = {"subordinate", "supervisor", "colleague", "unrelated"};
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i].id);
            readName(&A[i]);
            scanf("%d", &A[i].boss_id);
        }
        for (int i = 0; i < n; i++) {
            strcpy(B[i].first_name, A[i].first_name);
            strcpy(B[i].last_name, A[i].last_name);
            B[i].boss = NULL;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i].boss_id == A[j].id)
                    B[i].boss = &B[j];
            }
        }
        scanf("%d", &m);
        employee x, y;
        for (int i = 0; i < m; i++) {
            readName(&x);
            readName(&y);
            int ix = nameToIndex(&x, A, n), iy = nameToIndex(&y, A, n);
            assert(ix != -1);
            assert(iy != -1);
            printf("%d\n", relation(&B[ix], &B[iy]));
        }
    }
    return 0;
}