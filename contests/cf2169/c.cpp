#include<bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve(){
      int n; cin >> n;
      vector<i64> a(n);
      for( i64 &e: a) cin >> e;
      i64 sum = 0;
      vector<i64> b(n);
      for( int i = 0; i < n; i++){
            sum += a[i];
            b[i] = 2*(i+1) - a[i];
      }
      i64 cur = 0, m = 0;
      for( int i = 0; i < n; i++){
            cur += b[i];
            m = max( m, cur);
            if( cur < 0) cur = 0;
      }
      cout << sum + m << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

