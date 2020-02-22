typedef struct bid {
  int bidderID;
  int itemID;
  int bidPrice;
} Bid;
 
typedef struct itemMinPrice{
  int itemID;
  int minPrice;
} ItemMinPrice;
 
void bidding(Bid bidSeq[], int m, ItemMinPrice minPriceSeq[], int n);