#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int a,b;
      cin >> a >> b;
      int ans = 0;
      if( a == b) ans = 0;
      else if( a%b == 0 or b%a == 0) ans = 1;
      else ans = 2;
      cout << ans << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

