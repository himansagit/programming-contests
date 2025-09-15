#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void bfs( vector<vector<int>> &G, int source, vector<i64> &dist){
      queue<int> q;
      q.push(source);
      vector<bool> V(dist.size()+1);
      dist[source] = 0;
      V[source] = true;
      while( !q.empty()){
            int u = q.front();
            q.pop();
           for( int v:G[u]){
                 if( !V[v]){
                       V[v] = true;
                        dist[v] = dist[u]+1;
                        q.push(v);
                 }
           }
      }
}
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      #ifndef LOCAL
      freopen("piggyback.in","r",stdin);
      freopen("piggyback.out","w",stdout);
      #endif
      
      i64 b,e,p,n,m; cin >> b >> e >> p >> n >> m;
      //debug(b,e,p,n,m);
      vector<vector<int>> G(n+1);
      rep(i,m){
            int u,v; cin >> u >> v;
           G[u].push_back(v);
            G[v].push_back(u);
      }
      vector<i64> B(n+1), E(n+1), P(n+1);
      bfs(G,1,B);
      bfs(G,2,E);
      bfs(G,n,P);
      i64 ans = 1e10;
      for( int i = 1; i <= n; i++){
            ans = min( ans, E[i]*e + B[i]*b + P[i]*p);
      }
      cout << ans << '\n';
}

