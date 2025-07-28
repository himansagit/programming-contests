#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int MOD = 1e9+7;

const int N = 1005;
int dp[N+1][N+1];


void solve(int){
      int n,k;
      cin >> n >> k;
      memset(dp,0,sizeof(dp));
      rep(i,k) dp[i+1][0] = 1; // if no plane, particles just passes
      rep(i,n+1) dp[1][i] = 1; // if k == 1, particles just passes

      dp[0][0] = 0;
      for(int i = 2; i <= k; i++){
            for(int j = 1; j <= n; j++){
                  dp[i][j] = dp[i][j-1] + dp[i-1][n-j];
                  if( dp[i][j] >= MOD)
                        dp[i][j] -= MOD;
            }
      }
      
      int ans = dp[k][n];
      cout << ans << "\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc = 1;
      cin>>tc;
      for(int i = 1; i <= tc; i++){
            solve(i);
      }
      //TIME
}

