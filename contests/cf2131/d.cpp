#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n; cin >> n;
      vector<vector<int>> G( n+1);
      vector<int> deg(n+1);
      rep(i,n-1){
            int u,v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
            deg[u]++;
            deg[v]++;
      }
      if( n == 2){
            cout << "0\n";
            return;
      }
      int ans = 1e9;
      int leafs = count( deg.begin(), deg.end(), 1);
      for( int u = 1; u <= n; u++){
            int l = 0;
            for(int v:G[u]){
                  if( deg[v] == 1) l++;
            }
            ans = min( ans, leafs - l);
      }
      cout << ans << "\n";

}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

