#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int inf = 1e8;
const vector<pair<int,int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
void solve(){
     int r,c,s; cin >> r >> c >> s;
     vector<string> house(r);
     rep(i,r) cin >> house[i];
      vector<vector<int>> dist(r+2,vector<int>(c+2,inf));
      vector<vector<int>> mark(r+2,vector<int>(c+2));
      queue<pair<int,int>> q;
      for(int i = 0; i <= r+1; i++){
            dist[i][0] = -1;
            dist[i][c+1] = -1;
            q.push({i,0});
            q.push({i,c+1});
      }
      for( int i = 1; i <= c; i++){
            dist[0][i] = -1;
            dist[r+1][i] = -1;
            q.push({0,i});
            q.push({r+1,i});
      }
      for( int i = 1; i <= r; i++){
            for( int j = 1; j <= c; j++){
                  if(house[i-1][j-1] == '#'){
                        dist[i][j] = -1;
                        q.push({i,j});
                  }
            }
      }
      while( !q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for( auto [dx,dy] : dir){
                  int nx = x + dx;
                  int ny = y + dy;
                  if( nx >= 0 and ny >= 0 and nx <= r+1 and ny <= c+1){
                        if( dist[x][y] + 1 < dist[nx][ny]){
                              dist[nx][ny] = dist[x][y] +1;
                              q.push({nx,ny});
                        }
                  }
            }
      }
      int ans = 0;
      auto dfs = [&](auto self,int x, int y)->int{
            int cnt = 0;
            for( auto [dx,dy] : dir){
                  int nx = x + dx;
                  int ny = y + dy;
                  if( nx >= 0 and ny >= 0 and nx <= r+1 and ny <= c+1){
                        if( mark[nx][ny] == 0 and dist[nx][ny] >= s){
                              mark[nx][ny] = 1;
                              cnt += self(self,nx,ny);
                        }
                  }
            }
            return cnt + 1;
      };

      rep(i,r+2){
            rep(j,c+2){
                  if(mark[i][j] == 0 and dist[i][j] >= s){
                        //debug(i,j);
                        mark[i][j] = 1;
                        ans = max(ans, dfs(dfs,i,j));
                  }
            }
      }
      cout << ans << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      for(int i = 1; i <= tc; i++){
            cout << "Case #" << i << ": ";
            solve();
      }
}

