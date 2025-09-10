#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      i64 n,m; cin >> n >> m;
      vector<i64> a(n);
      rep(i,n) cin >> a[i];
      sort( a.rbegin(), a.rend());
      i64 ans = 0;
      for( int i = 0; i < n and m > 0; i++){
            ans += m*a[i];
            m--;
      }
      cout << ans << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

