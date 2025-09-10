#include<bits/stdc++.h>

using i64 = long long;
using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      i64 x;
      cin >> x;
      i64 y = pow(10, to_string(x).length()+1 );
      cout << y-x-1 << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

