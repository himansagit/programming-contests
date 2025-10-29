#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      vector<int> a(4);
      rep(i,4) cin >> a[i];
      sort( a.begin(), a.end());
      if( a[0] == a[3]) cout << "Yes\n";
      else cout << "No\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

