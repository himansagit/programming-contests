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
      i64 n; cin >> n;
      vector<i64> a(2*n+1);
      rep(i,2*n) cin >> a[i+1];

      sort( a.begin(), a.end());
      //debug(a);
      vector<i64> c(2*n+10);
      c[n] = a[n+1] - a[n];
      for( int i = 1; i  < n; i++){
            c[n-i] = a[n-i+1] - a[n-i] + a[n+i+1] - a[n+i] + c[n-i+2];
      }
      //for(int i = n-2; i >= 0; i--){
      //      c[i] = a[i+1] - a[i] - c[i+1] + c[i+2] + 
      //}

      i64 sum = 0;
      rep(i,n){
            sum += a[2*n -i] - a[i+1];
      }
      vector<i64> ans(n+1);
      ans[n] = sum;
      for(int i = n-1; i >= 1; i--){
            sum += -a[2*n-i+1] + a[i] + c[i] - c[i+1];
            ans[i] = sum;
      }
      rep(i,n) cout << ans[i+1] << " ";
      cout << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

