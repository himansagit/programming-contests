#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)


void solve(){
      int n,m; cin >> n >> m;
      vector<int> a(m);
      rep(i,m) cin >> a[i];
      bool ok = true;
      int x = *max_element(a.begin(), a.end());
      for( int i = 1; i < m; i++){
            if( a[i] - a[i-1] != 1) ok = false;
      }
      int ans = 1;
      if(ok) ans = n-x+1;
      cout << ans << '\n';
}


int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

