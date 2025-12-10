#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
const i64 inf = 1e18;
const int N = 2002;
i64 dp[N][N];

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
     
      for( int i = 0; i < N; i++){
            for( int j = 0; j < N; j++){
                  dp[i][j] = inf;
            }
      }

      int n; cin >> n;
      vector<i64> a(n);
      for( int i = 0; i < n; i++) cin >> a[i];
      sort( a.begin(), a.end());
      for( int w = 1; w <= n; w++){
            for( int l = 0; l < n-w+1; l++){
                  int r = l + w -1;
                  if( l == r) dp[l][r] = 0;
                  else dp[l][r] = min( dp[l+1][r], dp[l][r-1]) + a[r] - a[l];
            }
      }
      cout << dp[0][n-1] << '\n';
}

