#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,k; cin >> n >> k;
      vector<vector<int>> G(n+1);
      rep(i,n-1){
            int u,v; cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
      }
      vector<vector<int>> C(n+1);
      auto dfs = [&](auto dfs, int u, int p)->int{
            int c = 0;
            for( int v:G[u]){
                  if( v == p) continue;
                  int t = dfs(dfs,v,u);
                  C[u].push_back(t);
                  c += t;
            }
            C[u].push_back(n-c-1);
            return c+1;
      };
      dfs(dfs,1,0);
      i64 ans = n;
      for( int u = 1; u <= n; u++){
            for( int &x:C[u]){
                  if( x <= n-k){
                        ans += (long long)x;
                  }
            }
      }
      cout << ans << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

