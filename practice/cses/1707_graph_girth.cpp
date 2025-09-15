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
      vector<bool> V(n+1);
      vector<int> parent(n+1);
      vector<int> depth(n+1);
      queue<pair<int,int>> q;
      q.push({1,0});
      while( !q.empty()){
            pair<int,int> node = q.front();
            int u = node.first;
            int d = node.second;
            q.pop();
           if(V[u]){
                 ans = min( ans, d - depth[u]);
           }else{
                 V[u] = true;
                 depth[u] = d;
                 for( int v:G[u]){
                        
                       q.push({v,d+1});
                 }
           }
      }
      if( ans == n+1) cout << "-1\n";
      else cout << ans << '\n';
}

