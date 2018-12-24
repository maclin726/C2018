#include <stdio.h>
void shuffle(int *deck[]){
    int i;
    int count=0, half=0;
    while(deck[count] != NULL)
        count++;
    if(count%2 == 0)
        half = count/2;
    else
        half = count/2 +1;
    int *ptr1[5000],*ptr2[5000];
    for(i=0; i < count; i++){
        if(i < half)
            ptr1[i] = deck[i];
        else if(i >= half)
            ptr2[i-half] = deck[i];
    }
    for(i=0 ; i < count ; i++){
        if(i%2 == 0)
            deck[i] = ptr1[i/2];
        else
            deck[i] = ptr2[i/2];
    }
}
void print(int *deck[]){
    int i=0;
    while( deck[i] != NULL ){
        if( (deck[i]+1) == NULL )
            printf("%d", *deck[i]);
        else{
            printf("%d ", *deck[i]);
            i++;
        }
    }
}

int main()
{
  int card[10000];
  int *deck[10000];
  int index = 0;

  while (scanf("%d", &(card[index])) != EOF) {
    deck[index] = &(card[index]);
    index++;
  }
  deck[index] = NULL;
  shuffle(deck);
  print(deck);
  return 0;
}
