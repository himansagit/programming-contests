#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n; cin >>n;
      vector<vector<int>> G(n);
      for( int i = 0; i < n-1; i++){
            int u,v; cin >> u >> v;
            u--; v--;
            G[u].push_back(v);
            G[v].push_back(u);
      }
      vector<bool> visited(n); 
      vector<int> sz(n);
      vector<int> tier(n);
      queue<pair<int,int>> comp;
      auto dfs = [&](this auto &&dfs, int u, int p)->int{
            int c = 0;

            for( int v:G[u]){
                  if( v != p and !visited[v]){
                        c += dfs(v,u);
                  }
            }
            sz[u] = c+1;
            return c+1;
      };
      auto getc = [&](this auto &&getc, int u, int p,int s)->int{
            for( int v:G[u]){
                  if( v != p and !visited[v]){
                        if( sz[v] > s/2){
                              return getc(v,u,s);
                        }
                  }
            }
            return u;
      };
      comp.push({0,0});
     while( !comp.empty()){
           auto [u,t] = comp.front();
           comp.pop();
           dfs(u,-1);
           int c = getc(u,-1,sz[u]);
           assert( visited[c] == false);
           visited[c] = true;
           tier[c] = t;
            for( int v:G[c]){
                  if( !visited[v]){
                        comp.push({v,t+1});
                  }
            }
     }
     for( int i = 0; i < n; i++){
           char ch = 'A' + tier[i];
           cout << ch << ' ';
     }
     cout << '\n';
}


