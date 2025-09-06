#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif


using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int mod = 1e9+7;
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
     i64 n,m; cin >> n >> m;

     vector<vector<i64>> dp( m+1, vector<i64>(n+1));

     for(i64 i = 1; i <= n; i++) dp[1][i] = 1;

     for( i64 i = 2; i <= m; i++){
           for( i64 j = 1; j <= n; j++){
                 for( i64 k = 1; k <= j; k++){
                       dp[i][j] = ( dp[i-1][k] + dp[i][j]) % mod;
                 }
           }
     }
     //debug(dp);
     i64 ans = 0;
     for( i64 i = 1; i <= n; i++){
           for( int j = 1; j <= n-i+1; j++){
                 ans += (dp[m][i] * dp[m][j]) %mod;
                 ans = ans%mod;
           }
     }
     cout << ans << '\n';
}

