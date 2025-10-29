#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
using i64 = long long;
const i64 inf = 1e18;

void dfs(int,int s,vector<i64> &dist, vector<vector<pair<i64,int>>> &G){
      fill(dist.begin(), dist.end(), inf); 
      dist[s] = 0;
      priority_queue<pair<i64,int>> q;
      q.push({0,s});
      while( !q.empty()){
            auto [d,u] = q.top();
            q.pop();
            d = -d;
            if( dist[u] < d) continue;
            for(auto v:G[u]){
                  if( d + v.second < dist[v.first]){
                        dist[v.first] = d + v.second;
                        q.push({-dist[v.first], v.first});
                  }
            }
      }
}
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n,m; cin >> n >> m;
      vector<vector<pair<i64,int>>> G1(n+1);
      vector<vector<pair<i64,int>>> G2(n+1);
      vector<array<int,3>> edge(m);
      rep(i,m){
            int a,b,c; cin >> a >>b >> c;
            G1[a].push_back({b,c});
            G2[b].push_back({a,c});
            edge[i] = {a,b,c};
      }
      vector<i64> dist1(n+1), distn(n+1);
      dfs(n,1,dist1,G1);
      dfs(n,n,distn,G2);
      i64 ans = inf;
     for(int i = 0; i < m; i++){
           auto [a,b,c] = edge[i];
           ans = min( ans, dist1[a] + distn[b] + c/2);
     }
     cout << ans << '\n';
}

