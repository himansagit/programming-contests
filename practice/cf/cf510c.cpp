#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif


#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      // first attempt failed because did not 
      // account for multiple edges
      // i.e. an edge a -> b can appear multiple time
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n; cin >> n;
      vector<string> s(n);
      rep(i,n) cin >> s[i];
      vector<vector<int>> from(26),to(26);
      rep(i,n-1){
            int t = min( s[i].length(), s[i+1].length());
            bool ok = false;
            rep(j,t){
                  if( s[i][j] != s[i+1][j]){
                        to[ s[i][j] - 'a'].push_back( s[i+1][j] - 'a');
                        from[ s[i+1][j] - 'a'].push_back( s[i][j] - 'a');
                        ok = true;
                        break;
                  }
            }
            if( !ok and s[i].length() > s[i+1].length()){
                  cout << "Impossible\n";
                  return 0;
            }
      }
      debug(to);
      string res;
     // vector<bool> V(26);
     // auto dfs = [&](auto self,int u)->void{
     //       if( V[u]) return;
     //      bool ok = true;
     //      for( int v:from[u]){
     //            if( !V[v]) ok = false;
     //      }
     //      if( !ok) return;
     //      V[u] = true;
     //      res.push_back( 'a' + u);
     //      for(int v:to[u]){
     // //           assert( ! V[v]); // this assertion is incorrent 
     // //                            // when graph have multiple edges
     //            self(self,v);
     //      }
     // };

      //topological sort
     vector<int> state(26);
     bool cyc = false;
      auto dfs = [&](auto self, int u)->void{
            if( state[u] == 2) return;
            state[u] = 1;
            for(int v:to[u]){
                  if( state[v] == 1 ){
                        cyc = true;
                        return;
                  }
                  self(self,v);
            }
            res.push_back(u + 'a');
            state[u] = 2;
      };
      rep(i,26){
                  dfs(dfs,i);
      }
      reverse(res.begin(), res.end());
      if(cyc) cout << "Impossible\n";
      else cout << res << '\n';

}

