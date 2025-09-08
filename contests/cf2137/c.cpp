#include<bits/stdc++.h>

using namespace std;
using i64 = long long; 
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      i64 a,b; cin >> a >> b;
      int x = a%2, y = b%2;
      i64 res = -1;
      if( x == 1 and y == 1){
            res = a*b+1;
      }else if( x == 0 and y == 1){
            res = -1;
      }else if( x == 1 and y == 0){
            b /= 2;
            a *= 2;
            if( b%2 == 1){
                  res = -1;
            }else{
                  res = a*b/2 + 2;
            }
      }else{
            res = a*b/2 + 2; 
      }
      cout << res << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

