#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n;
      cin >> n;
      vector<int> a(n);
      rep(i,n) cin >> a[i];
      sort( a.rbegin(), a.rend());
      bool ok = true;
      if( a[0] == 0)
            ok = false;
      rep(i,n){
            if( a[i] == -1)
                  break;
            if( a[i] != a[0]){
                  ok = false;
                  break;
            }
      }
      cout << (ok ? "YES" : "NO") << "\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

