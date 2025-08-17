#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n;
      cin >> n;
      vector<vector<int>> grid(n+1, vector<int> (n+1,-1));

      rep(i,n){
            rep(j,n){
                  vector<int> m(2*n);
                 for( int k = i-1; k >= 0 ; k--) 
                        m[ grid[k][j]]++;
                  for( int k = j-1; k >= 0; k--)
                        m[ grid[i][k]]++;
                  for( int k = 0; k < 2*n; k++){
                        if( m[k] == 0){
                              grid[i][j] = k;
                              cout << k << ' ' ;
                              break;
                        }

                  }
            }
            cout << '\n';
      }

}


int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

