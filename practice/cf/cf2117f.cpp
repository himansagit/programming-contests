#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9+7;
void solve(){
      int n; cin >> n;
      vector<vector<int>> G(n+1);
      vector<int> deg(n+1);
      for( int i = 0; i < n-1; i++){
           int u ,v; 
           cin >> u >> v;
           G[u].push_back(v);
           G[v].push_back(u);
           deg[u]++;
           deg[v]++;
      }
      int lfs = 0;
      for( int i = 2; i <= n; i++){
            if( deg[i] == 1) lfs++;
      }
      if( lfs > 2){
            cout << "0\n";
            return;
      }
      //special cases where graph in line startin from root 1
      // (1)-2-3-4-5-6...
      int mdeg = *max_element(deg.begin(), deg.end());
      if( deg[1] == 1 and mdeg <= 2){
            //special cases where graph in line startin from root 1
            // (1)-2-3-4-5-6...
            int ans = 1;
            for( int i = 0; i < n; i++){
                  ans = (2*ans) % mod;
            }
            cout << ans << '\n';
            return;
      }
      vector<pair<int,int>> depth(n+1);
      vector<int> height(n+1);
      auto dfs = [&](auto self, int u, int p, int d)->int{
            int h = 0;
            if( depth[d].first > 0){
                  depth[d].second = u;
            }else{
                  depth[d].first = u;
            }
            for( int v:G[u]){
                  if( v != p){
                        h = max(h, self(self,v,u,d+1));
                  }
            }
            height[u] = h+1;
            return h+1;
      };
      dfs(dfs,1,0,1);
     int left = -1, right = -1; 
     for( int i = 1; i <= n; i++){
           if( depth[i].first > 0 and depth[i].second > 0){
                 left = depth[i].first;
                 right = depth[i].second;
                 break;
           }
     }
      int d = abs( height[left] - height[right]);
      int rem = n - height[left] - height[right];
      int ans = 1;
      for( int i = 0; i < rem +d; i++){
            ans = (2*ans) % mod;
      }
      if( d > 0){
            int add = 1;
            for( int i = 0; i < rem + d-1; i++){
                  add = (2*add) % mod;
            }
            ans = (ans + add) % mod;
      }else{
            ans = (2*ans) % mod;
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

