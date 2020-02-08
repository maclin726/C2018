#include<stdio.h>
#include<ctype.h>
void print_digit(char digit[], int count){
    int end = count-1, i;
    while( digit[end-1] == ' ')
        end--;
    for (i = 0; i <= end; i++)
        printf("%c",digit[i]);
}
void top(char a[], int width){
    int i,number,count=0;
    char digit[91];
    for( number = 0; isdigit(a[number]) == 1; number++ ){
        if(a[number] != '1' && a[number] != '4')
            for(i=0; i<width; i++){
                if(i == 0 || i == (width-1) || i == (width-2) )
                    digit[count] = ' ';
                else
                    digit[count] = a[number];
                count++;
            }
        else
            for(i=0; i<width; i++){
                digit[count] = ' ';
                count++;
            }
    }
    print_digit(digit,count);
    return;
}
void up(char a[], int width){
    int i,number,count = 0;
    char digit[91];
    for( number = 0; isdigit(a[number]) == 1; number++)
        if(a[number] == '1' || a[number] == '2' || a[number] == '3'){
            for(i = 0; i < width; i++){
                if(i == (width-2))
                    digit[count] = a[number];
                else
                    digit[count] = ' ';
                count++;
            }
        }
        else if(a[number] == '5' || a[number] == '6'){
            for(i=0; i<width; i++){
                if(i == 0)
                    digit[count] = a[number];
                else
                    digit[count] = ' ';
                count++;
            }
        }
        else{
            for(i=0; i<width; i++){
                if(i == 0 || i == (width-2) )
                    digit[count] = a[number];
                else
                    digit[count] = ' ';
                count++;
            }
        }
    print_digit(digit,count);
    return;
}
void middle(char a[], int width){
    int i,number,count = 0;
    char digit[91];
    for( number = 0; isdigit(a[number]) == 1; number++)
        if(a[number] == '0' || a[number] == '1' || a[number] == '7')
            for(i=0; i<width; i++){
                digit[count] = ' ';
                count++;
            }
        else
            for(i=0; i<width; i++){
                if(i == 0 || i == (width-1) || i == (width-2) )
                    digit[count] = ' ';
                else
                    digit[count] = a[number];
                count++;
            }
    print_digit(digit,count);
    return;
}
void down(char a[], int width){
    int i,number,count = 0;
    char digit[91];
    for( number = 0; isdigit(a[number]) == 1; number++)
        if(a[number] == '2')
            for(i=0; i<width; i++){
                if(i == 0)
                    digit[count] = a[number];
                else
                    digit[count] = ' ';
                count++;
            }
        else if(a[number] == '0' || a[number] == '6' || a[number] == '8')
            for(i=0; i<width; i++){
                if(i == 0 || i == (width-2) )
                    digit[count] = a[number];
                else
                    digit[count] = ' ';
                count++;
            }
        else
            for(i=0; i<width; i++){
                if(i == (width-2))
                    digit[count] = a[number];
                else
                    digit[count] = ' ';
                count++;
            }
    print_digit(digit,count);
    return;
}
void last(char a[], int width){
    int i,number,count = 0;
    char digit[91];
    for( number = 0; isdigit(a[number]) == 1; number++)
        if(a[number] != '1' && a[number] != '4' && a[number] != '7' && a[number] != '9'){
            for(i=0; i<width; i++){
                if(i == 0 || i == (width-1) || i == (width-2) )
                    digit[count] = ' ';
                else
                    digit[count] = a[number];
                count++;
            }
        }
        else{
            for(i=0; i<width; i++){
                digit[count] = ' ';
                count++;
            }
        }
    print_digit(digit,count);
    return;
}
int main(){
    char c,A[11];
    int count=0,i;
    while( scanf("%c",&c)!=EOF ){
        if( c == ' ' ){
            char digit[15][91];
            int width, height;
            scanf("%d%d",&width,&height);
            int line;
            for(line=1; line <= height; line++){
                if(line == 1)
                        top(A, width);
                if(line > 1 && line < (height+1)/2 )
                        up(A,width);
                if(line == (height+1)/2 )
                        middle(A,width);
                if(line < height  && line > (height+1)/2 )
                        down(A,width);
                if(line == height )
                        last(A,width);
                if(line != height)
                    printf("\n");
            }
            for(i = 0; i<11; i++){
                A[i] = '\0';
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
