#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int N = 101;
const int inf = 1e9;
int dist[N][N][3];
int field[N][N][3];
using P = array<int,4>;
vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
#ifndef LOCAL
      freopen("visitfj.in","r",stdin);
      freopen("visitfj.out","w",stdout);
#endif

      int n,T; cin >> n >> T;
      rep(i,n){
            rep(j,n){
                  rep(k,3) {
                        dist[i][j][k] = inf;
                        field[i][j][k] = 0;
                  }
                  cin >> field[i][j][2];
            }
      }
      priority_queue< P, vector<P>, greater<P>> q;
      dist[0][0][0] = 0;
      q.push({0,0,0,2});
      while( !q.empty()){
            auto [d, x, y, t] = q.top();
            q.pop();
            if( dist[x][y][t] < d) continue;
            t = (t+1)%3;
            for( pair<int,int>  mov:dir){
                  int r = x + mov.first;
                  int c = y + mov.second;
                  if( min(r,c) < 0 or max(r,c) >= n) continue;
                  int newd = d + T + field[r][c][t];
                  if( newd < dist[r][c][t]){
                        dist[r][c][t] = newd;
                        q.push({newd, r, c, t});
                  }
            }
      }
      int ans = inf;
      rep(i,3) ans = min(ans, dist[n-1][n-1][i]);
      cout << ans << '\n';
}

