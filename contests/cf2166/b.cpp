#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
void solve(){
      i64 a,b,n; cin >> a >> b >> n;
      i64 ans = 0;
      if( a == b or b*n <= a) ans = 1;
      else ans =2;
      cout << ans << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

