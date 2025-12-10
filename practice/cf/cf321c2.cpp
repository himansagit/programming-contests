#include<bits/stdc++.h>

using namespace std;

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n; cin >> n;
      vector<vector<int>> G(n);
      for( int i = 0; i < n-1; i++){
            int u,v; cin >> u >> v;
            u--, v--;
            G[u].push_back(v);
            G[v].push_back(u);
      }
      vector<int> sz(n);
      vector<bool> visited(n);
      vector<char> res(n);
      auto getsz = [&](this auto &&getsz, int u, int p)->void{
            sz[u] = 1;
            for( int v:G[u]){
                  if( v != p and !visited[v]){
                        getsz(v,u);
                        sz[u] += sz[v];
                  }
            }
      };
      auto centroid = [&](this auto &&centroid, int u, int p, int comp_size)->int{
            for( int v:G[u]){
                  if( v != p and !visited[v]){
                        if( sz[v] > comp_size/2){
                              return centroid(v,u,comp_size);
                        }
                  }
            }
            return u;
      };
      auto decompose = [&](this auto &&decompose, int u, int level)->void{
            getsz(u,-1);
            int comp_size = sz[u];
            int cent = centroid(u,-1,comp_size);
            res[cent] = 'A' + level;
            visited[cent] = true;
            for( int v:G[cent]){
                  if( !visited[v]){
                        decompose(v,level+1);
                  }
            }
      };
      decompose(0,0);
      for( char &c:res) cout << c << ' ';
      cout << '\n';
}

