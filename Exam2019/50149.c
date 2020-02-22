#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int id;
	int m;			//math
	int e;			//English
	int s;			//science;
	int c;			//Chinese
	int ss;			//social society
	int total;
}student;

int compare( const void *data1, const void *data2 ){
	student *ptr1 = (student *)data1;
	student *ptr2 = (student *)data2;
	if( ptr1->total < ptr2->total )
		return 1;
	else if( ptr1->total > ptr2->total )
		return -1;
	else if( ptr1->m < ptr2->m )
		return 1;
	else if( ptr1->m > ptr2->m )
		return -1;
	else if( ptr1->e < ptr2->e )
		return 1;
	else if( ptr1->e > ptr2->e )
		return -1;
	else if( ptr1->s < ptr2->s )
		return 1;
	else if( ptr1->s > ptr2->s )
		return -1;
	else if( ptr1->c < ptr2->c )
		return 1;
	else if( ptr1->c > ptr2->c )
		return -1;
	else if( ptr1->ss < ptr2->ss )
		return 1;
	else if( ptr1->ss > ptr2->ss )
		return -1;
	else if( ptr1->id > ptr2->id )
		return 1;
	else
		return -1;
}

int main(){
	int M, N;
	student Student[20000];
	scanf("%d%d", &M, &N);
	for( int i = 0; i < N; i++ ){
		scanf("%d%d%d%d%d%d", &Student[i].id, &Student[i].c, &Student[i].e, 
							  &Student[i].m, &Student[i].s, &Student[i].ss);
		Student[i].total = Student[i].c + Student[i].e + Student[i].m + Student[i].s + Student[i].ss;
	}
	qsort( Student, N, sizeof(student), compare );
	for( int i = 0; i < M; i++ ){
		printf("%d\n", Student[i].id);
	}
	while( (Student[M-1].m == Student[M].m) && (Student[M-1].c == Student[M].c) && (Student[M-1].e == Student[M].e)
			&& (Student[M-1].ss == Student[M].ss) && (Student[M-1].s == Student[M].s) ){
		printf("%d\n", Student[M].id);
		M++;
	}
}