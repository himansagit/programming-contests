#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n; cin >> n;
      vector<int> a(n);
      int m = 0, z = 0;
      rep(i,n){
            int x; cin >> x;
            if( x == 0) z++;
            else if( x == -1) m++;
      }
      if( m%2 == 1) z += 2;
      cout << z << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

