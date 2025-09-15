#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n; cin >>  n;
      int cost = 0;
      if( n <= 2) cost = 200;
      else if( n == 3) cost = 300;
      else cost = n*100;
      cout << cost << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

