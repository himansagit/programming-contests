#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      i64 n;
      cin >> n;
      vector<i64> a(n);
      rep(i,n) cin >> a[i];
      sort( a.begin(), a.end());
      i64 l = 0, r= 0;
      i64 res = 0;
      while( l < n){
            while( r < n and a[r] - a[l] <= 2){
                  r++;
            }
            i64 w = r-l-1;
            // w choose m-1;
            res = res + ((w*(w-1))/2);
            l++;
      }
      cout << res << "\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}
