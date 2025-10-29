#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
using i64 = long long;
const i64 inf = 1e18;

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n,m; cin >> n >> m;
      vector<vector<pair<int,int>>> G(n+1);
      rep(i,m){
            int a,b,c; cin >> a >> b >> c;
            G[a].push_back({b,c});
      }
      vector<i64> dist(n+1,inf);
      priority_queue<pair<i64,int>> q;
      dist[1] = 0;
      q.push({0,1});
      while(!q.empty()){
            auto [d,u] = q.top();
            q.pop();
            d = -d;
            if( dist[u] < d) continue;
            for(auto &v:G[u]){
                  if( d + v.second < dist[v.first]){
                        dist[v.first] = d + v.second;
                        q.push({-dist[v.first], v.first});
                  }
            }
      }
      for(int i = 1; i <= n; i++) cout << dist[i] << " \n"[i == n];
}

