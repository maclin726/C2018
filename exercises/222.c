#include<stdio.h>

int main(){
    long long int bookshelf = 0, p = 1;
    int count = 0, book;
    while( scanf("%d", &book) != EOF ){
        int i,j;
        int check = 0;
        for( i = 0; i < count && !check; i++){
            if( (bookshelf >> 8*i) % 256 == book ){      //check whether the book is on the shelf
                check = 1;
                if( i == 0 )
                    break;
                long long int mod = ( p << (8*i) );
                long long int temp = ( (bookshelf % mod) << 8) + book;
                bookshelf = bookshelf >> (8*i) >> 8 << (8*i) << 8;
                bookshelf += temp;
                break;
            }
        }
        if( !check ){                                   //case: book is in the box
            if(count < 8)
                count++;
            bookshelf = bookshelf << 8;
            bookshelf += book;
        }
    }
    int i,j;
    for( i = 7; i >= 0; i-- ){
        int ans = (bookshelf >> (8 * i)) % 256;
        if(ans < 0)
            ans += 256;
        if( !i )
            printf("%d", ans);
        else
            printf("%d ", ans);
    }
    return 0;
}