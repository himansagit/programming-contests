#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
using i64 = long long;
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      i64 ans = 0, n = 1e6;
      for( i64 i = 1; i <= n; i++){
            ans += (n-i+1)*(i);
      }
      cout << ans << '\n';
}

