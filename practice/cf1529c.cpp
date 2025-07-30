#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

using P2 = array<i64,2>;
void solve(){
      int n;
      cin >> n;
      vector<P2> R(n+1);
      rep(i,n) cin >> R[i+1][0] >> R[i+1][1];
      vector<vector<int>> G(n+1);
      rep(i,n-1){
            int u, v;
            cin >> u >>v;
            G[u].push_back(v);
            G[v].push_back(u);
      }
      vector<P2> bt(n+1);
      auto dfs = [&](auto self,int u,int p)->void{
            for(int v:G[u]){
                  if( v != p){
                        self(self,v,u);
                  }
            }
            i64 l = 0, r = 0;
            for(int v:G[u]){
                  if( v != p){
                        l += max( abs(R[u][0] - R[v][0]) + bt[v][0], abs(R[u][0] - R[v][1]) + bt[v][1]); 
                        r += max( abs(R[u][1] - R[v][0]) + bt[v][0], abs(R[u][1] - R[v][1]) + bt[v][1]); 
                  }
            }
            bt[u] = {l,r};
      };
      dfs(dfs,1,0);
      cout << max(bt[1][0], bt[1][1]) << "\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
      //TIME
}

