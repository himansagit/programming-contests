//https://usaco.org/index.php?page=viewproblem2&cpid=814
#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
using i64 = long long;

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      #ifndef LOCAL
            freopen("dirtraverse.in","r",stdin);
            freopen("dirtraverse.out","w",stdout);
      #endif

      
      int n; cin >> n;
      vector<vector<int>> G(n+1);
      vector<i64> w(n+1);
      //int cnt = 0;
      for( int i = 1; i <= n; i++){
            string s; cin >> s;
            int t; cin >> t;
            w[i] = s.length();
            if( t > 0) w[i]++;
            for( int j = 0; j < t; j++){
                  int x; cin >> x;
                  G[i].push_back(x);
            }
      }
      vector<i64> sum(n+1);
      vector<i64> cnt(n+1);
      auto dfs1 = [&](auto self, int u)->void{
            if( G[u].size() == 0){
                  cnt[u] = 1;
                  return;
            }
            for( int v:G[u]){
                  self(self,v);
                  cnt[u] += cnt[v];
                  sum[u] += w[v]*cnt[v] + sum[v];
            }
      };
      dfs1(dfs1,1);

      auto dfs2 = [&](auto self, int u)->void{
            for(int v:G[u]){
                  sum[v] = sum[u] + (cnt[1]-cnt[v])*3 - cnt[v]*w[v];
                  self(self,v);
            }
     };
      dfs2(dfs2,1);
      
      i64 ans = *min_element(sum.begin()+1, sum.end());

      cout << ans << '\n';
}

