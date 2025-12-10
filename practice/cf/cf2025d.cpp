#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
const int N = 5005;
int dp[N][2*N];
int pre[4*N];

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);

      memset(dp,0,sizeof(dp));
      memset(pre,0,sizeof(pre));
      
      int n,m; cin >> n >> m;
      vector<int> a(n);
      for( int i = 0; i < n; i++) cin >> a[i];
      int w = 0; 
      int ans = 0;
      for( int i = 0; i <= n; i++){
            if( i == n or a[i] == 0){
                  if( w > 0){
                        for( int j = 1; j < 4*N; j++){
                              pre[j] += pre[j-1];
                        }
                        for( int j = 0; j <= w; j++){
                              if( j == 0) 
                                   dp[w][j] = dp[w-1][j] + pre[j+N] - pre[j-w-1+N]; 
                              else
                                   dp[w][j] = max( dp[w-1][j], dp[w-1][j-1]) + pre[j+N] - pre[j-w-1+N]; 
                             ans = max(ans, dp[w][j]);
                        }
                  }
                  for( int j = 0; j < 4*N; j++) pre[j] = 0;
                  w++;
            }else{
                  pre[ a[i] + N]++;
            }
      }

      cout << ans << '\n';
}

