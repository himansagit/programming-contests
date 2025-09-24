#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
const int N = 1005;
int mark[N][N];
int dist[N][N];
int edge[N][3];
const int inf = 1e8;

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      memset(mark,0,sizeof(mark));
      int n,m; cin >> n >> m;
      rep(i,n+1) rep(j,n+1)  dist[i][j] = inf;
      vector<vector<pair<int,int>>> G(n+1);
      rep(i,m){
            int a,b;
            char c; 
            cin >> a >> b >> c;
            edge[i][0] = a;
            edge[i][1] = b;
            edge[i][2] = c - 'a';
            G[a].push_back({b,c});
            G[b].push_back({a,c});
      }
      dist[1][n] = 0;
      mark[1][n] = 1;
      queue<pair<int,int>> q;
      q.push({1,n});
      while(!q.empty()){
            pair<int,int> node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
            for(auto &u:G[x]){
                  for(auto &v:G[y]){
                        if( mark[u.first][v.first] == 0 and u.second == v.second){
                              mark[u.first][v.first] = 1;
                              q.push({u.first,v.first});
                              dist[u.first][v.first] = dist[x][y] + 2;
                        }
                  }
            }
      }
      int ans = inf;
      rep(i,n){
            ans = min(ans, dist[i][i]);
      }
      rep(i,m){
            ans = min( ans, dist[edge[i][0]][edge[i][1]] +1);
            ans = min( ans, dist[edge[i][1]][edge[i][0]] +1);
      }
      if( ans == inf) cout << "-1\n";
      else cout << ans << '\n';
}

