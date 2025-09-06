#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int ans = 0;
      for( int i = 1; i < 1000; i++){
            if( i%3 == 0 or i%5 == 0){
                  ans += i;
            }
      }
      cout << ans << '\n';
}

