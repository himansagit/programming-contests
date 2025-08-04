#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,m,k;
      cin >> n >> m>>k;
      vector<string> s(n);
      rep(i,n) cin >> s[i];
      int e = 0;
      rep(i,n){
            rep(j,m){
                  if( s[i][j] == '.') e++;
            }
      }
      int l = e-k;
      vector<pair<int,int>> dir = { {1,0}, {0,1}, {-1,0}, {0,-1}};
      vector<vector<int>> mark(n+1, vector<int> (m+1));
      int cnt = 0;
      auto dfs = [&](auto self, int r,int c)->void{
            if( cnt == l)
                  return;
            if( r < 0 or c < 0 or r >= n or c >= m)
                  return;
            if( mark[r][c] or s[r][c] == '#')
                  return;
            mark[r][c] = 1;
            cnt++;
            for( auto& d:dir){
                  self(self, r + d.first, c + d.second);
            }
      };
      rep(i,n){
            bool ok = false;
            rep(j,m){
                  if( s[i][j] == '.'){
                        dfs(dfs,i,j);
                        ok = true;
                        break;
                  }
            }
            if( ok) break;
      }
      rep(i,n){
            rep(j,m){
                  if( s[i][j] == '.' and mark[i][j] == false){
                        s[i][j] = 'X';
                  }
            }
      }
      rep(i,n) cout << s[i] << "\n";

}


int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

