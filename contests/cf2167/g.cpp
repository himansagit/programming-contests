#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void compress( vector<int> &a){
      int n = a.size();
      vector<int> d = a;
      sort( d.begin(), d.end() );
      d.resize( unique( d.begin(), d.end()) - d.begin());
      for( int i = 0; i < n; i++){
            a[i] = lower_bound( d.begin(), d.end(), a[i]) - d.begin();
      }
}

const i64 inf = 1e18;

void solve(){
      int n; cin >> n;      
      vector<int> a(n), c(n);
      rep(i,n) cin >> a[i];
      rep(i,n) cin >> c[i];
      compress(a);
      vector<vector<i64>> dp( 2, vector<i64> (n+2, inf));
      for( int j = 0; j <= n; j++){
            dp[0][j] = c[0];
      }
      dp[0][a[0]] = 0;
      for( int i = 1; i < n; i++){
            i64 m = dp[0][0];
          for( int j = 0; j <= n; j++){
                m = min(m, dp[0][j]);
                if( j == a[i]) dp[1][j] = m;
                else dp[1][j] = m + c[i];
          }
          for( int j = 0; j <= n; j++){
                dp[0][j] = dp[1][j];
                dp[1][j] = inf;
          }
      }
      i64 ans = inf;
      //debug(dp);
      for( int j = 0; j <= n; j++) ans = min(ans, dp[0][j]);
      cout << ans << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

