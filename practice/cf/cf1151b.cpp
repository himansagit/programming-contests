#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n,m; cin >> n >> m;
      vector<vector<int>> a(n, vector<int> (m));
      int x = 0;
      rep(i,n){
            rep(j,m) cin >> a[i][j];
            x ^= a[i][0];
      }
      vector<int> res(n);
      bool ok = false;
      if( x == 0){
            for( int i = 0; i  < n and !ok; i++){
                  rep(j,m){
                        if( a[i][j] != a[i][0]){
                              res[i] = j;
                              ok = true;
                              x ^= a[i][0];
                              x ^= a[i][j];
                              assert( x != 0);
                              break;
                        }
                  }
            }
      }
      if( ok or x != 0){
            cout << "TAK\n";
            rep(i,n) cout << res[i] +1 << " ";
            cout << '\n';
      }else{
            cout << "NIE\n";
      }
}

