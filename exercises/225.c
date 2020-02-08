#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

struct person {
    unsigned int id;
    char name[32];
};

struct friends {
    unsigned id1;
    unsigned id2;
};

unsigned int name2id( struct person data[], char nameA[], unsigned int P ){
    for( int i = 0; i < P; i++ )
        if( strcmp(data[i].name, nameA) == 0 )
            return data[i].id;
}

int main(){
    unsigned int P, F;
    FILE *FP = fopen("friends", "r");
    assert(FP != NULL);

    fread(&P, 4, 1, FP);
    struct person data[10000];
    for(int i = 0; i < P; i++)
        fread(&data[i], sizeof(data[0]), 1,FP);

    fread(&F, 4, 1, FP);
    struct friends relation[10000];
    for(int i = 0; i < F; i++)
        fread(&relation[i], sizeof(relation[0]), 1, FP);
    fclose(FP);

    char name1[32], name2[32];
    while(scanf("%s", name1) != EOF){
        if( !strcmp(name1, "end") )
            break;
        scanf("%s", name2);
        int idA = name2id(data, name1, P), idB = name2id(data, name2, P);
        int find = 0;
        for( int i = 0; i < F && !find; i++ )
            if( (relation[i].id1 == idA && relation[i].id2 == idB) 
                || (relation[i].id1 == idB && relation[i].id2 == idA) )
                find = 1;
        if(find)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}