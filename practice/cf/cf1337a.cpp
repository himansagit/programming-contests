#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,k;
      cin >> n >> k;
      vector<i64> D(n+1);
      vector<vector<int>> G(n+1);
      rep(i,n-1){
            int u,v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
      }
      auto dfs = [&](auto self, int u, int p,i64 d)->int{
            D[u] = d;
            i64 c = 0; 
            for(int v:G[u]){
                  if( v == p)
                        continue;
                  c += self(self,v,u,d+1);
            }
            D[u] -= c;
            return c+1;
      };
      dfs(dfs,1,-1,0);
      D[0] = -1e9;
      sort( D.rbegin(), D.rend());
      i64 res = 0;
      rep(i,k) res += D[i];
      cout << res;

}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

