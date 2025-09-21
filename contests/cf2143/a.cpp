#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n; cin >> n;
      vector<int> a(n);
      rep(i,n) cin >> a[i];
      int l = 0, r = n-1, f = 1;
      while( l <= r){
            if( a[l] == f){
                  l++;
            }else if( a[r] == f){
                  r--;
            }else{
                  break;
            }
            f++;
      }
      if( l > r) cout << "YES\n";
      else cout << "NO\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

