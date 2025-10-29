#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif
#define int long long
using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
using i64 = long long;
using P = array<int,3>;
const int inf = 1e9;
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      #ifndef LOCAL
            freopen("shortcut.in","r",stdin);
            freopen("shortcut.out","w",stdout);
      #endif
      int n,m; i64 t; cin >> n >> m >> t;
      vector< vector< pair<int, i64>>> G(n+1);
      vector<i64> cnt(n+1);

      rep(i,n) cin >> cnt[i+1];

      rep(i,m){
            int a,b,c; cin >> a >> b >> c;
            G[a].push_back({b,c});
            G[b].push_back({a,c});
      }
      vector<int> dist(n+1,inf),parent(n+1);
      dist[1] = 0;
      priority_queue< P, vector<P>, greater<P>> q;
      q.push({0,0,1});
      vector<int> order;
      //order.push_back(1);
      vector<int> mark(n+1);
      while( !q.empty()){
            auto [d,p,u] = q.top();
            q.pop();

            if( dist[u] < d) continue;
            if( mark[u] ) continue;
            mark[u] = 1;
            order.push_back(u);
            for( auto [v,w]:G[u]){
                  int newd = d + w;
                  if( newd < dist[v] ){ 
                        q.push({ dist[v] = newd, u,v});
                        parent[v] = u;
                        //cnt[u] += cnt[v];
                        //order.push_back(v);
                  }else if( newd == dist[v] and u < parent[v]){
                        parent[v] = u;
                  }
            }
      }
      debug(cnt,dist);
     i64 ans = 0;
     debug(order);
     assert( order.size() == n);
     for(int i = order.size()-1; i >=0; i--){
            int x = order[i];
            cnt[parent[x]] += cnt[x];
     }
      debug(cnt,dist);
     for(int i = 2; i <= n; i++){
            ans = max(ans, 1LL*cnt[i]*(dist[i] - t));
     }
     cout << ans << '\n';
}

