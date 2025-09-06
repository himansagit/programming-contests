#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n;
      cin >> n;
      vector<vector<int>> G(n+1);
      vector<int> deg(n+1);
      rep(i,n-1){
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
            deg[u]++;
            deg[v]++;
      }
      if( *max_element(deg.begin(), deg.end()) <= 2){
            cout << -1 << '\n';
            return;
      }
      vector<int> depth(n+1);
      auto dfs = [&](auto self, int u, int p,int d)->int{
            depth[u] = d;
            int cd = 0;
            for( int v: G[u]){
                  if( v == p)
                        continue;
                  cd = max( cd, self(self,v,u,d+1));
            }
            depth[u] = max( depth[u], cd);
            return cd + 1;
      };
      int leaf = 0;
      for(; leaf <= n; leaf++){
            if( deg[leaf] == 1) break;
      }
      assert( leaf > 0 and leaf <= n);
      dfs(dfs,leaf,-1,0);
      int c = 0;
      int d = 0;
      for( int i = 1; i <= n; i++){
            if( deg[i] <= 2)
                  continue;
            if( depth[i] > d){
                  d = depth[i];
                  c = i;
            }
      }
      auto dfs2 = [&](auto self, int u, int p)->int{
            int de = 0;
            for( int v:G[u]){
                  if( v == p) continue;
                  de = max( de, self(self,v,u));  
            }
            depth[u] = de;
            return de+1;
      };
      dfs2(dfs2,c,-1);
      assert( c > 0 and c <= n);
      vector<pair<int,int>> nbh;
      for( int v: G[c]){
            nbh.push_back({depth[v],v});
      }
      sort( nbh.begin(), nbh.end());
      debug(nbh);
      int k = nbh.size();
      cout << nbh[1].second << " " << c << " " << nbh[0].second << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

