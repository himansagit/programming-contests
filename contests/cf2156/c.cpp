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
      i64 n,k; cin >> n >> k;
      vector<i64> a(n);
      rep(i,n) cin >> a[i];
      vector<int> c(n+1, n), d(n+2);
      rep(i,n){
            int x = a[i];
            d[x/4 +1]++; 
            if( x%3 == 0) c[x/3]--;
            if( x%2 == 0) c[x/2]--;
            c[x]--;
      }
      int sum = n;
      for(int i = 1; i <= n; i++){
            sum -= d[i];
            c[i] -= sum;
      }
      for( int i = n; i >= 1; i--){
            if( c[i] <= k){
                  cout << i << '\n';
                  return;
            }
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

