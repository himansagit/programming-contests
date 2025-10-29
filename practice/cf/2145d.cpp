#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
const int N = 31;
int dp[N][N*N];
int p(int n){
      return (n*(n+1))/2;
}
void solve(){
     int n,k; cin >> n >> k; 
     k = p(n) - k;
     //int x = n;
     if( dp[n][k] == 0){
           cout << "0\n";
           return;
     }
     while( n > 0 or k > 0){
            int d = dp[n][k];
            for( int i = n-d+1; i <= n; i++) cout << i << " ";
            n -= d;
            k -= p(d);
     }
     cout << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      memset(dp,0,sizeof(dp));
      dp[0][0] = 1;
      for( int n = 1; n < N; n++){
            for(int k = 1; k <= N*N-1; k++){
                  for( int d = 1; d <= n; d++){
                        if( p(d) <= k and dp[n-d][k - p(d)] > 0){
                              dp[n][k] = d;
                        }
                  }
            }
      }

      int tc; cin >> tc;
      while(tc--) solve();
}

