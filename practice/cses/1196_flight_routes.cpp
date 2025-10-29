#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
using i64 = long long;
const int N = 1e5+10;
i64 dp[N][10];
const i64 inf = 1e18;
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      memset(dp,0,sizeof(dp));      
      
      int n,m,k; cin >> n >> m >> k;
      for( int i = 1; i <= n; i++){
            for(int j = 0; j <10; j++){
                  dp[i][j] = inf;
            }
      }
      vector<vector<pair<int,i64>>> G(n+1);

      rep(i,m){
            int a,b,c; cin >> a >> b >> c;
            G[a].push_back({b,c});
      }
      priority_queue< pair<i64,int>, vector< pair<i64,int>>, greater< pair<i64,int>>> q;
      dp[1][0] = 0;
      q.push({0,1});
      while( !q.empty()){
            auto [d,u] = q.top();
            q.pop();
            if( dp[u][9] < d) continue;
            for( auto [v,w]: G[u]){
                  i64 newd = d + w;
                  if( newd >= dp[v][9]) continue;
                  dp[v][9] = newd;
                  for( int j = 8; j >= 0 and dp[v][j] > dp[v][j+1]; j--){
                        swap(dp[v][j], dp[v][j+1]);
                  }
                  q.push({newd,v});
            }
      }
      for( int i = 0; i < k; i++) cout << dp[n][i] << " ";
      cout << '\n';
}

