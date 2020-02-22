#include <stdio.h>
#include <stdlib.h>

typedef struct bid {
  int bidderID;
  int itemID;
  int bidPrice;
} Bid;
 
typedef struct itemMinPrice{
  int itemID;
  int minPrice;
} ItemMinPrice;
 
typedef struct{
    int itemID, bidderId, price;
}Result;

#define MAXM 10000
#define MAXN 1000
int compare(const void *a, const void *b){
    Result *ptr1 = (Result *)a, *ptr2 = (Result *)b;
    if( ptr1->bidderId > ptr2->bidderId )
        return 1;
    else if( ptr1->bidderId < ptr2->bidderId )
        return -1;
    else
        return ptr1->itemID > ptr2->itemID;
}
void bidding(Bid bidSeq[], int m, ItemMinPrice minPriceSeq[], int n){
    int minPrice[MAXN];
    for( int i = 0; i < n; i++ )
        minPrice[minPriceSeq[i].itemID] = minPriceSeq[i].minPrice;
    Result result[MAXN];
    for( int i = 0; i < n; i++ ){
        result[i].itemID = i;
        result[i].bidderId = -1;
        result[i].price = minPrice[i];
    }
    for( int i = 0; i < m; i++ ){
        int item = bidSeq[i].itemID;
        if( bidSeq[i].bidPrice > result[item].price || 
            ((bidSeq[i].bidPrice == result[item].price) && (result[item].bidderId == -1)) ){
            result[item].price = bidSeq[i].bidPrice;
            result[item].bidderId = bidSeq[i].bidderID;       
        }
    }
    qsort(result, n, sizeof(Result), compare);
    for( int i = 0; i < n; i++ ){
        if( result[i].bidderId != -1 )   
            printf("Bidder %d gets item %d with %d dollars\n", result[i].bidderId, result[i].itemID, result[i].price);
    }
    return;
}