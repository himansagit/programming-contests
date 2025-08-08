#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int N = 2e5+100;
i64 fact[N];
const i64 mod = 1e9+7;
void solve(){
      int n,m;
      cin >> n >> m;
      vector<vector<int>> G(n+1);
      rep(i,m){
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
      }
      // check for cycles
      bool cyc = false;
      vector<int> V(n+1);
      auto dfs = [&](auto self, int u, int p)->void{
            if( V[u] == 1)
            {
                  cyc = true;
                  return ;
            }
            V[u] = 1;
            for(int v:G[u]){
                  if( v == p)
                        continue;
                  self(self,v,u);
            }
      };
      dfs(dfs,1,0);
      if( cyc){
            cout << "0\n";
            return;
      }
      i64 res = 1;
      int endp = 0;
      for( int i = 1; i <= n; i++){
            if( G[i].size() == 1)
                  continue;
            int nonleaf = 0;
            for( int v: G[i]){
                  if( G[v].size() > 1 )
                        nonleaf++;
            }
            if( nonleaf > 2){
                  cout << "0\n";
                  return;
            }
            if( nonleaf == 1){
                  endp++;
            }

            int leaf = G[i].size()  - nonleaf;
            res = (res * fact[leaf])%mod;
      }
      assert( endp == 0 or endp == 2);
      res = (res*2)%mod;
      if( endp == 2) res = (res * 2)%mod;
      cout <<res << "\n";
      
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      fact[0] = fact[1] = 1;
      for( i64 i = 2;i < N; i++){
           fact[i] = (fact[i-1]*i)%mod; 
      }
      int tc; cin >> tc;
      while(tc--) solve();
}

