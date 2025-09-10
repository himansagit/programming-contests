#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,m,k; cin >> n >> m >> k;
      vector<int> a(n+1);
      rep(i,k){
            int x; cin >> x;
            assert( x <= n);
            a[x] = 1;
      }
      debug(a);
      vector<int> piles(n+1);
      int ans = 0;
      auto dfs = [&](auto self,int idx)->void{
          if(idx == n +1){
                //process
                bool ok = false;
                int cnt = 0;
                for( int i = 1; i <= n; i++){
                      if( i == n or a[i+1] == 1){
                             if( piles[i] == 2){
                                   if( n - i <= cnt){
                                         ok = true;
                                   }
                             }
                             cnt = 0;
                      }
                      cnt++;
                }
                if( ok ) ans += 2;
                else ans += 1;
                return;
          }
          piles[idx] = 1;
          self(self,idx+1);
          piles[idx] = 2;
            self(self,idx+1);
      };
      dfs(dfs,1);
      cout << ans <<'\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

