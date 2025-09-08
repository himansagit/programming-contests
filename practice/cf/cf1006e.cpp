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
      
      int n,q; cin >> n >> q;
      vector<vector<int>> G(n+1);
      for( int i = 2; i <= n; i++){
            int p; cin >> p;
            G[p].push_back(i);
      }
      vector<int> order;
      vector<pair<int,int>> loc(n+1);
      auto dfs = [&](this auto dfs, int u)->void{
            order.push_back(u);
            loc[u].first = order.size();
           for( int v:G[u]){
                 dfs(v);
           }
           loc[u].second = order.size();
      };
      dfs(1);
      assert( order.size() == n);
      while(q--){
            int u,k; cin >> u >> k;
            int l = loc[u].first-1;
            int r = loc[u].second-1;
            if( l + k-1 > r ) cout << -1 << '\n';
            else cout << order[l +k -1] << '\n';
      }
}

