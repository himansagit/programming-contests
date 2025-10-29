#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
using i64 = long long;
const i64 inf = 1e18;
const int mod = 1e9+7;
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n,m; cin >> n >> m;
      vector<vector<pair<i64,int>>> G(n+1);
      rep(i,m){
            int a,b,c; cin >> a >> b >> c;
            G[a].push_back({b,c});
      }
      vector<i64> dist(n+1,inf);
      vector<int> routes(n+1), min_f(n+1,m+1), max_f(n+1,0);
      dist[1] = 0;
      routes[1] = 1;
      min_f[1] = 0;
      max_f[1] = 0;
      priority_queue<pair<i64,int>> q;
      q.push({0,1});
      while( !q.empty()){
            auto [d,u] = q.top();
            q.pop();
            d =  -d;
            if( dist[u] < d) continue;
            for( auto v:G[u]){
                  i64 newd = d + v.second;
                  if( newd == dist[v.first]){
                        routes[v.first] += routes[u];
                        if( routes[v.first] >= mod) routes[v.first] -= mod;
                        min_f[v.first] = min( min_f[ v.first ], min_f[ u ] +1);
                        max_f[v.first] = max( max_f[ v.first ], max_f[ u ] +1);
                  }else if( newd < dist[v.first]){
                        dist[v.first] = newd;
                        q.push({-newd,v.first});
                        routes[v.first] = routes[u];
                        min_f[v.first] = min_f[u] + 1;
                        max_f[v.first] = max_f[u] + 1;
                  }
            }
      }
      cout << dist[n] << " " << routes[n] << " " << min_f[n] << " " << max_f[n] << '\n';
}

