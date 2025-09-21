#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n,m; cin >> n >> m;
      vector<vector<int>> G(n+1);
      rep(i,m) {
            int u, v; cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
      }
      int ans = n+1;
      for( int node = 1; node <= n; node++){
            queue<pair<int,int>> q;
            q.push({node,0});
            vector<int> depth(n+1,n+1);
            depth[node] = 0;
            while( !q.empty()){
                 pair<int,int> x = q.front();
                  int u = x.first;
                  int p = x.second;
                 q.pop();
                 for( int v:G[u]){
                       if( v == p) continue;
                       if( depth[v] < n+1){
                             // avoid parent
                             ans = min(ans, depth[v] + depth[u] +1);
                             debug(node,u,v,ans);
                       }else{
                             depth[v] = depth[u]+1;
                             q.push({v,u});
                       }
                 }
            }
      }
      if( ans == n+1) ans = -1;
      cout << ans << '\n';
}

