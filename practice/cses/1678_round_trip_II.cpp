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
      rep(i,m){
            int a,b;
            cin >> a >> b;
            G[a].push_back(b);
      }
      vector<int> ans;
      vector<int> mark(n+1);
      int cyc = 0;
      auto dfs = [&](auto self, int u)->void{
            if( mark[u] == 2) return;
            if( mark[u] == 1){
                  mark[u] = 2;
                  cyc = 1;
                  ans.push_back(u);
                  return;
            }
            mark[u] = 1;
            for( int v:G[u]){
                  if( cyc == 0) // no cycle found yet;
                        self(self,v);
            }
            if(cyc == 1){
                  ans.push_back(u);
                  if( mark[u] == 2) cyc = 2;
            }
            mark[u] = 2;
      };
      for( int i= 1; i <= n and cyc == 0; i++){
            dfs(dfs,i);
      }
      if( ans.size() == 0){
            cout << "IMPOSSIBLE\n"; return 0;
      }
      cout << ans.size() << '\n';
      for( int i = ans.size()-1; i >= 0; i--) cout << ans[i] << " ";
      cout << '\n';
}

