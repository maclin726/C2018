#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct member{
    char name[64];
    struct member *left;
    struct member *right;
}Member;

typedef struct club{
  char clubName[64];
  struct member *leader;
  struct club *left;
  struct club *right;
}Club;

Member *insert_name( Member *leader, char people[] ){
    Member *current;
    if( leader == NULL ){
        current = (Member*)malloc(sizeof(Member));
        assert(current != NULL);
        strcpy( current->name, people );
        current->left = current->right = NULL;
        return current;
    }
    if( strcmp(leader->name, people) > 0 )
        leader->left = insert_name(leader->left, people);
    else
        leader->right = insert_name(leader->right, people);
    return leader;
}

Club *insert_club(Club *root, char people[], char ClubName[])
{
  Club *current;
  if (root == NULL) {
    current = (Club*)malloc(sizeof(Club));
    assert(current != NULL);
    strcpy( current->clubName, ClubName );
    current->left = current->right = NULL ;
    current->leader = insert_name(NULL, people);
    return(current);
  }
  if ( strcmp(root->clubName, ClubName) > 0 )
    root->left = insert_club(root->left, people, ClubName);
  else 
    root->right = insert_club(root->right, people, ClubName);
  return(root);
}

Club *findClub(Club *root, char ClubName[]){
    if( root == NULL )
        return NULL;
    int compare = strcmp(root->clubName, ClubName);
    if( compare == 0 )
        return root;
    else if(compare > 0)
        return findClub(root->left, ClubName);
    else
        return findClub(root->right, ClubName);
}

int findStudent(Member *leader, char people[]){
    if(leader == NULL)
        return 0;
    int compare = strcmp(leader->name, people);
    if( compare == 0 )
        return 1;
    else if( compare > 0 )
        return (findStudent(leader->left, people));
    else
        return (findStudent(leader->right, people));
}

int main(void)
{
    int K,Q;
    scanf("%d", &K);
    Club *root = NULL;
    for( int i = 0; i < K; i++ ){
        int ins;
        char student[64] = {'\0'}, ClubName[64] = {'\0'};
        scanf("%d", &ins);
        scanf("%s%s", student, ClubName);
        if( !ins )
            root = insert_club(root, student, ClubName);
        else{
            Club *ptr = findClub(root, ClubName);
            ptr->leader = insert_name(ptr->leader, student);
        }
    }
    scanf("%d", &Q);
    for( int i = 0; i < Q; i++ ){
        int ins;
        char people[64] = {'\0'}, ClubName[64] = {'\0'};
        scanf("%d", &ins);
        if( !ins ){
            scanf("%s", ClubName);
            Club *ptr = findClub(root, ClubName);
            if( ptr == NULL )
                printf("None\n");
            else
                printf("%s\n", ptr->leader->name);
        }
        else{
            scanf("%s%s", people, ClubName);
            if( findClub(root, ClubName) == NULL ){
                printf("-1\n");
                continue;
            }
            printf( "%d\n", findStudent(findClub(root, ClubName)->leader, people) );
        }
    }
    return 0;
}