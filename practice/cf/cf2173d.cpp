#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
i64 inf = 1e9;
void solve(){
      i64 n,k; cin >> n >> k;
      vector<int> A(32,0);
      for( int i = 0; i < 31; i++){
            if( (n>>i&1) > 0){
                  A[i] = 1;
            }
      }
      vector<vector<vector<i64>>> dp(32, vector<vector<i64>> (32, vector<i64> (3,-inf)));
      for( int i = 0; i < 32; i++){
            dp[i][0][0] = 0;
            if( A[i] == 1){
                  dp[i][0][1] = 0;
            }
      }
      for( int j = 1; j < 32; j++){
            for( int i = 0; i < 32; i++){
                  if( A[i] == 1){
                        dp[i][j][2] = max( { dp[i-1][j-1][0] + 1, dp[i-1][j-1][1] + 2, dp[i-1][j][2] +1});
                        dp[i][j][1] = max( { dp[i-1][j][0], dp[i-1][j][1]});
                        //dp[i][j][0] = max( { dp[i-1][j][0], dp[i-1][j][1], dp[i-1][j][2]});
                        //dp[i][j][0]
                  }else{
                        dp[i][j][2] = max( { dp[i-1][j-2][0] + 1, dp[i-1][j-2][1] + 2, dp[i-1][j-1][2] +1});
                        dp[i][j][1] = max( { dp[i-1][j-1][0], dp[i-1][j-1][1] + 1, dp[i-1][j][2]});
                        dp[i][j][0] = max( { dp[i-1][j][0], dp[i-1][j][1]});
                  }
            }
      }
      int ans = 0;
      if( k < 32){
            ans = max({dp[31][k][2], dp[31][k][1], dp[31][k][0]});
      }else{
            ans =  k - 32 + max({dp[31][k][2], dp[31][k][1], dp[31][k][0]});
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

