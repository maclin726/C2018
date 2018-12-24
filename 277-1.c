#include<stdio.h>
void top(char c, int width){
    int i;
    if(c != '1' && c != '4'){
        for(i=0; i<width; i++){
            if(i == 0 || i == (width-1) || i == (width-2) )
                printf(" ");
            else
                printf("%c",c);
        }
    }
    else{
        for(i=0; i<width; i++)
                printf(" ");
    }
    return;
}
void up(char c, int width){
    int i;
    if(c == '1' || c == '2' || c == '3'){
        for(i=0; i<width; i++){
            if(i == (width-2))
                printf("%c",c);
            else
                printf(" ");
        }
    }
    else if(c == '5' || c == '6'){
        for(i=0; i<width; i++){
            if(i == 0)
                printf("%c",c);
            else
                printf(" ");
        }
    }
    else{
        for(i=0; i<width; i++){
            if(i == 0 || i == (width-2) )
                printf("%c",c);
            else
                printf(" ");
        }
    }
    return;
}
void middle(char c, int width){
    int i;
    if(c == '0' || c == '1' || c == '7'){
        for(i=0; i<width; i++)
            printf(" ");
    }
    else{
        for(i=0; i<width; i++){
            if(i == 0 || i == (width-1) || i == (width-2) )
                printf(" ");
            else
                printf("%c",c);
        }
    }
    return;
}
void down(char c,int width){
    int i;
    if(c == '2'){
        for(i=0; i<width; i++){
            if(i == 0)
                printf("%c",c);
            else
                printf(" ");
        }
    }
    else if(c == '0' || c == '6' || c == '8'){
        for(i=0; i<width; i++){
            if(i == 0 || i == (width-2) )
                printf("%c",c);
            else
                printf(" ");
        }
    }
    else{
        for(i=0; i<width; i++){
            if(i == (width-2))
                printf("%c",c);
            else
                printf(" ");
        }
    }
    return;
}
void last(char c, int width){
    int i;
    if(c != '1' && c != '4' && c != '7' && c != '9'){
        for(i=0; i<width; i++){
            if(i == 0 || i == (width-1) || i == (width-2) )
                printf(" ");
            else
                printf("%c",c);
        }
    }
    else{
        for(i=0; i<width; i++)
                printf(" ");
    }
    return;
}
int main(){
    char c,A[11];
    int count=0,i;
    while( scanf("%c",&c)!=EOF ){
        if( c == ' ' ){
            int width, height;
            scanf("%d%d",&width,&height);
            int line;
            for(line=1; line <= height; line++){
                if(line == 1)
                    for(i=0; i<count; i++)
                        top(A[i],width);
                if(line > 1 && line < (height+1)/2 )
                    for(i=0; i<count; i++)
                        up(A[i],width);
                if(line == (height+1)/2 )
                    for(i=0; i<count; i++)
                        middle(A[i],width);
                if(line < height  && line > (height+1)/2 )
                    for(i=0; i<count; i++)
                        down(A[i],width);
                if(line == height )
                    for(i=0; i<count; i++)
                        last(A[i],width);
                printf("\n");
            }
            count=0;
        }
        else if(c != '\n' && c != EOF){
            A[count] = c;
            count++;
        }
    }
return 0;
}
