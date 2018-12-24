#include<stdio.h>
int count = 0;
void seesaw(int start, int end, int element[], int balance[]){
    if( end - start < 2 )
        return;
    for( int i = start; i <= end; i++ ){
        long long int left = 0;
        long long int right = 0;
        for(int  j = start; j < i; j++ )
            left += element[j] * (i - j);
        for(int  j = i+1; j <= end; j++)
            right += element[j] * (j - i);
        if( left == right ){
            balance[count] = i;
            count++;
            seesaw(start, i-1, element, balance);
            seesaw(i+1, end, element, balance);
            return;
        }
    }
    return;
}
int main(){
    int n;
    int element[16384] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &element[i]);
    int balance[16384] = {0};
    seesaw(0, n-1, element, balance);
    for(int i = count-1; i > 0; i--)
        for( int j = 0; j < i; j++ )
            if( balance[j] > balance[j+1] ){
                int temp = balance[j+1];
                balance[j+1] = balance[j];
                balance[j] = temp;
            }
    for(int i = 0; i < count; i++)
        printf("%d\n", balance[i]);
    return 0;
}