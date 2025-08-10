#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n;
      cin >> n;
      for( int i = 2; i <= n; i += 2){
            cout << i << " " ;
      }
      if( n % 2 == 1){
            for( int i = 1 ; i  <= n; i += 2){
                  cout << i << " ";
            }
      }else{
            for( int i = 3 ; i  <= n; i += 2){
                  cout << i << " ";
            }
            cout << 1 << " " ;
      }
}

