#include<bits/stdc++.h>

using namespace std;

void solve(){
      int n,x; cin >> n;
      vector<int> a(n);
      for( int &a:a) cin >> a;
      cin >> x;
      sort( a.begin(), a.end());
      if( a[0] <= x and a[n-1] >= x) cout << "YES\n";
      else cout << "NO\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

