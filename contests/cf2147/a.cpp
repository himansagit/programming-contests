#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int x,y;
      cin >> x >> y;
      int ans = -1;
      if( y > x) ans = 2;
      else if( y > 1 and x-y > 1) ans = 3;
      cout << ans << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

