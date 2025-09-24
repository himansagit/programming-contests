#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,m; cin >> n >> m;
      vector<vector<int>> v(n+1);
      vector<int> cnt(m+1);
      for( int i = 1; i <= n; i++){
            int l; cin >> l;
            v[i].resize(l);
            rep(j,l){
                  cin >> v[i][j];
                  cnt[v[i][j]]++;
            }
      }
      for(int i = 1; i <= m; i++){
            if( cnt[i] == 0){
                  cout << "NO\n";
                  return;
            }
      }
      int d = 0;
      for( int i = 1; i <= n; i++){
            bool ok = true;
            for(int x:v[i]){
                  if( cnt[x] == 1){
                        ok = false;
                        break;
                  }
            }
            if(ok) d++;
      }
      if( d >= 2) cout << "YES\n";
      else  cout << "NO\n"; 
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

