#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
const int mod = 1e9+7;

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n,m; cin >> n >> m;
      vector<vector<int>> G(n+1);
      vector<int> deg(n+1);
      rep(i,m){
            int a,b; cin >> a>>b;
            G[a].push_back(b);
            deg[b]++;
      }
      queue<int> q;
      vector<int> dp(n+1);
      rep(i,n){
            if( deg[i+1] == 0) q.push(i+1);
      }
      vector<int> order;
      while(!q.empty()){
            int u = q.front();
            q.pop();
            order.push_back(u);
            for(int v:G[u]){
                  deg[v]--;
                  if( deg[v] == 0) q.push(v);
            }
      }
      dp[1] = 1;
      for(int u:order){
            for(int v:G[u]){
                  dp[v] += dp[u];
                  if(dp[v] >= mod) dp[v] -= mod;
            }
      }
      cout << dp[n] << '\n';
}

