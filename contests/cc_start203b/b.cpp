#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n; cin >> n;
      int m = (n*(n-1))/2;
      vector<int> a(m);
      rep(i,m) cin >> a[i];
      sort( a.begin(), a.end());
      int ans = 0;
      int edge = 0;
      for( int i = 0; i< m and edge < n;i++){
            ans += a[i];
            i += edge;
            edge++;
      }
      cout << ans << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

