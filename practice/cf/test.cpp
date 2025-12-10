#include<bits/stdc++.h>

using namespace std;

void solve(){
      int n, m; cin >> n >> m;
      cout << n << " " << m << endl;
      for( int i = 20; i >= 0; i--){
            if( (n>>i&1) == 0) cout << 0;
            else cout << 1;
      }
      cout << endl;
      for( int i = 20; i >= 0; i--){
            if( (m>>i&1) == 0) cout << 0;
            else cout << 1;
      }
      cout << endl;
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

