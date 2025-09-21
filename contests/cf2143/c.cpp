#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n; cin >> n;
      vector<vector<pair<int,int>>> G(n+1);
      rep(i,n-1){
            int u,v,x,y;
            cin >> u >> v >> x >> y;
            if(u > v) swap(u,v);
            if( x > y){
                  G[u].push_back({v,1});
                  G[v].push_back({u,1});
            }else{
                  G[u].push_back({v,0});
                  G[v].push_back({u,0});
            }
      }
      vector<int> perm(n+1);
      iota(perm.begin(), perm.end(), 0);
      auto dfs = [&](this auto dfs, int u, int p,int s)->int{
            // step1: fill lower vertices
            int child = 0;
            for(auto &v:G[u]){
                  if( v.first == p) continue;

                  if( (u < v.first and v.second == 1) or (u > v.first and v.second == 0)){
                        child += dfs(v.first,u,s+child);
                  }
            }
            // setep2: fill   upper vertices 
            perm[u] = s + child;
            child++;
            for(auto &v:G[u]){
                  if( v.first == p) continue;
                  if( u < v.first and v.second == 0)
                        child += dfs(v.first,u,s+child);
                  else if( u > v.first and v.second == 1)
                        child += dfs(v.first,u,s+child);
            }
            return child;
      };
      dfs(1,0,1);
      rep(i,n) cout << perm[i+1] << " ";
      cout << '\n';

}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

