#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a, arr[9];
    cin>>a;
    for ( int i = 0; i < a; i++ )
        cin>>arr[i];
    sort(arr,arr+a);
    do{
        for( int i = 0; i < a; i++ ){
            if(i) cout<<" ";
            cout<<arr[i];
        }
        cout<<endl;
    }while( next_permutation(arr, arr+a) );
return 0;
}
