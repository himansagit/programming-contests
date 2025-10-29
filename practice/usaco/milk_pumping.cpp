#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int inf = 1e9;
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
#ifndef LOCAL
      freopen("pump.in","r",stdin);
      freopen("pump.out","w",stdout);
#endif
      int n,m; cin >> n >> m;
      vector<array<int,4>> pipe(m);
      rep(i,m){
            cin >> pipe[i][0] >> pipe[i][1] >> pipe[i][2] >> pipe[i][3];
      }
      sort( pipe.begin(), pipe.end(), [](array<int,4> &a, array<int,4> &b)->bool{ return a[3] > b[3];}); 
      vector<vector<array<int,4>>> G(n+1);
      double mul = 1e6;
      int ans = 0;
      vector<int> dist(n+1);
      rep(i,m){
            G[pipe[i][0]].push_back(pipe[i]);
            swap(pipe[i][0], pipe[i][1]);
            G[pipe[i][0]].push_back(pipe[i]);
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
            q.push({0,1});
            fill(dist.begin(),dist.end(),inf);
            dist[1] = 0;
            while( !q.empty()){
                  auto [d,u] = q.top();
                  q.pop();
                  debug(d,u);
                  if( dist[u] < d) continue;
                  debug(d,u);
                  for(const auto [x,v,c,f]: G[u]){
                        debug(x,v,c,f);
                        if( dist[v] > d + c){
                              dist[v] = d + c;
                              q.push({dist[v], v});
                        }
                  }
            }
            debug(dist);
            debug(pipe[i][3], dist[n]);
            int tmp = (mul*pipe[i][3] )/dist[n];
            ans = max(ans,tmp);
      }
      cout << ans << '\n';
}

