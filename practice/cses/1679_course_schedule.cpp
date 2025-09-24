#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n,m; cin >> n >> m;
      vector<int> V(n+1);
      vector<vector<int>> G(n+1);
      rep(i,m){
            int a,b; cin >> a >> b;
            G[b].push_back(a);
      }
      vector<int> ans;
      bool ok = true;
      auto dfs = [&](auto self,int u)->void{
           if( V[u] == 1){
                 ok = false;
                 return;
           }
           if( V[u] == 2) return;
           V[u] = 1;
           for(int v:G[u]){
                 self(self,v);
           }
           ans.push_back(u);
           V[u] = 2;
      };
      for(int i = 1; i <= n and ok; i++){
            dfs(dfs,i);
      }
      if(!ok){
            cout << "IMPOSSIBLE\n";
            return 0;
      }
      assert( ans.size() == n);
      for(int &x:ans) cout << x << " ";
      cout << '\n';
}

