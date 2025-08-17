#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

using P = array<int,2>;
const int inf = 1e9;
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n,m; cin >> n >> m;
      vector<string> s(n);
      rep(i,n) cin >> s[i];
      vector<vector<int>> dist(n+1, vector<int> (m+1, inf));
      queue<P> q;
      int sr = -1,sc = -1;
      rep(i,n){
            rep(j,m){
                  if( s[i][j] == 'M'){
                        q.push({i,j});
                        dist[i][j] = 0;
                  }
                  if( s[i][j] == 'A'){
                        sr = i;
                        sc = j;
                  }
            }
      }
      vector<P> dir = { { 1,0}, {0,1}, {-1,0}, {0,-1}};
      while( !q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for( auto d:dir){
                  int rr = r + d[0];
                  int cc = c + d[1];
                  if( rr < 0 or cc < 0 or rr >= n or cc >= m) continue;
                  if( s[rr][cc] == '#') continue; 
                  if( dist[rr][cc] > dist[r][c] + 1){
                        dist[rr][cc] = dist[r][c] +1;
                        q.push({ rr,cc});
                  }
            }
      }
      
      map<P,char> dtc;
      dtc[ { 1,0}] = 'D';
      dtc[ { 0,1}] = 'R';
      dtc[ { -1,0}] = 'U';
      dtc[ { 0,-1}] = 'L';
     vector<vector<int>>  dista(n+1, vector<int> (m+1,inf));
     q.push({sr,sc});
     vector<vector<char>> path(n+1, vector<char>(m+1,'#'));
     path[sr][sc] = 'A';
     dista[sr][sc] = 0;
      while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for( auto d:dir){
                  int rr = r + d[0];
                  int cc = c + d[1];
                  if( rr < 0 or cc < 0 or rr >= n or cc >= m) continue;
                  if( s[rr][cc] == '#') continue; 
                  if( dista[rr][cc] > dista[r][c] + 1){
                        dista[rr][cc] = dista[r][c] +1;
                        if( dista[rr][cc] < dist[rr][cc]){
                              path[rr][cc] = dtc[d];       
                              q.push({ rr,cc});
                        }
                  }
            }
      }
      int endr = -1, endc = -1;
      string res;
      rep(i,n){
            rep(j,m){
                  if( i == 0 or i == n-1 or j == 0 or j == m-1){
                        if( path[i][j] != '#'){
                              endr = i;
                              endc = j;
                        }
                  }
            }
      }
      if( endr == -1 or endc == -1){
            cout << "NO\n";
      }else{
            while( path[endr][endc] != 'A'){
                  char c = path[endr][endc];
                  res += c;
                  if( c == 'L') endc += 1;
                  else if(c  == 'R') endc -=1;
                  else if( c == 'U') endr += 1;
                  else{
                        assert( c == 'D');
                        endr -= 1;
                  }
                  
                  assert( endr >= 0 and endr < n and endc >= 0 and endc < m);
            }
            reverse( res.begin(), res.end());
            cout << "YES\n";
            cout << res.length() << '\n';
            cout << res << '\n';
      }
      
}

