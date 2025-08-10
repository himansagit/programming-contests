#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n;
      cin >> n;
      vector<int> a(n), b(n);
      rep(i,n) cin >> a[i];
      rep(i,n) cin >> b[i];
      bool ok = true;
      if( a[n-1] != b[n-1]) ok = false;
      rep(i,n-1){
           if( a[i] != b[i] and (a[i]^a[i+1]) != b[i] and (a[i]^b[i+1]) != b[i]) ok = false; 
      }
      cout << ( ok ? "YES" : "NO") << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

