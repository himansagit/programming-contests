#include<bits/stdc++.h>

using namespace std;

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n,m; cin >> n >> m;
      vector<string> s(n);
      for( int i = 0; i < n; i++){
            cin >> s[i];
      }
      int r = -1, c = -1;
      for(; r < n; r++){
            bool ok = false;
            for(; c < m; c++){
                  if( s[r][c] != '.'){
                        ok = true;
                        break;
                  }
            }
            if( ok) break;
      }
      assert( r != -1 and c != -1);
      
      auto dfs = [&](this auto &&self, int i, int j, pair<int,int> &d,char m, int depth)->void{
            if( i < 0 or j < 0 or i >= n or j >= m){
                  d = {i,j};
                  return;
            }
            if( s[i][j] == '.'){
                  dfs(
            }else if( s[i][j] == '\'){

            }else{

            }

      };
      if( s[r][c] == '/'){
            pair<int,int> d1 = {-2,-2};
            pair<int,int> d2 = {-2,-2};
            int c = dfs(r-1,c,d,0,);
            c += dfs(r
      
      }else{

      }
}

