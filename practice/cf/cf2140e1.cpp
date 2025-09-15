#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif


using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int N = 21;
int dp[N][(1<<N)][2];
void solve(){
      int n,m,k; cin >> n >> m >> k;
      vector<int> good(k);
      rep(i,k){
            cin >> good[i];
      }
      if( m == 1){
            cout << 1 << '\n';
            return ;
      }
      // dp[ i: no. of piles][ mask: arrangement][p: player];
      
 //     memset(dp,0,sizeof(dp));

      //vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (1 << n, vector<int>(2)));

      rep(i,2){
            rep(j,2){
                  dp[1][i][j] = i+1;
            }
      }

      for( int i = 2; i <= n; i++){
            for( int j = 0; j < (1 << i); j++){
                  dp[i][j][0] = 1;
                  dp[i][j][1] = 2;
                  for( int g:good){
                        if( g > i) continue;
                       int bit = (1 << (g-1)); // 000010000 
                       int mask = (j&(~bit));// remove gth bit
                        bit--; // 0001000 -> 0000111
                        int left = mask&bit;
                        int right = mask&(~bit); 
                        mask = (right>> 1)|left;
                        dp[i][j][0] = max( dp[i][j][0], dp[i-1][mask][1]);
                        dp[i][j][1] = min( dp[i][j][1], dp[i-1][mask][0]);
                  }
            }
      }
      //debug(dp);
      int ans = 0;
      for( int i = 0; i < (1 << n); i++){
            ans += dp[n][i][0];
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

