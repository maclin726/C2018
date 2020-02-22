#include <stdio.h>
#include "50176.h"
 
int main(int argc, char const *argv[]) {
  int m, n;
  scanf("%d%d", &m, &n);
  Bid bidSeq[m];
  ItemMinPrice minPriceSeq[n];
  for(int i = 0; i < m; i++) {
    scanf("%d%d%d", &bidSeq[i].bidderID, &bidSeq[i].itemID, &bidSeq[i].bidPrice);
  }
  for(int i = 0; i < n; i++) {
    scanf("%d%d", &minPriceSeq[i].itemID, &minPriceSeq[i].minPrice);
  }
  bidding(bidSeq, m, minPriceSeq, n);
  return 0;
}