#include<stdio.h>
#include<string.h>

typedef struct employee {
  int id;
  char first_name[32];
  char last_name[32];
  int boss_id;
}Employee;

int compare( Employee data[], int N, char first[], char last[] ){
    for( int i = 0; i < N; i++ )
        if( strcmp( first, data[i].first_name ) == 0 && strcmp( last, data[i].last_name ) == 0 )
            return i;
}

int id_compare( int code[], int N, int id ){
    for( int i = 0; i < N; i++ )
        if( code[i] == id )
            return i;
}

int main(){
    Employee data[32];
    int code[32];
    int relative[32][32] = {0};             //[i][j] means "j is i's sup(1) or sub(2)"
    int N, M;
    scanf("%d", &N);
    for( int i = 0; i < N; i++ ){
        scanf("%d", &data[i].id);
        code[i] = data[i].id;
        scanf("%s", data[i].first_name);
        scanf("%s", data[i].last_name);
        scanf("%d", &data[i].boss_id);
    }
    for( int i = 0; i < N; i++ ){
        int next_code = id_compare( code , N, data[i].boss_id);
        while( !relative[i][next_code] ){
            relative[i][next_code] = 1;
            relative[next_code][i] = 2;
            next_code = id_compare( code, N, data[next_code].boss_id );
        }
    }
    scanf("%d", &M);
    for( int i = 0; i < M; i++ ){
        char first1[32], last1[32], first2[32], last2[32];
        int code1, code2;
        scanf("%s%s%s%s", first1, last1, first2, last2);
        code1 = compare( data, N, first1, last1 );
        code2 = compare( data, N, first2, last2 );
        if( relative[code2][code1] == 1 )
            printf("supervisor\n");
        else if( relative[code2][code1] == 2 )
            printf("subordinate\n");
        else{
            int rel = 0;
            for( int j = 0; j < N; j++ )
                if( relative[code2][j] == 1 && relative[code1][j] == 1 ){
                    printf("colleague\n");
                    rel = 1;
                    break;
                }
            if( !rel )
                printf("unrelated\n");
        }
    }
}