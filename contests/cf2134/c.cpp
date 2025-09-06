#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n; cin >> n;
      vector<i64> a(n);
      rep(i,n) cin >> a[i];
      i64 ans = 0;
      for( int i = 1; i < n; i += 2){
            if( i == n-1){
                  i64 d = a[i-1] - a[i];
                  if( d > 0){
                        ans += d;
                  }
            }else{
                  i64 d = a[i-1] + a[i+1] - a[i];
                  d = max(0LL,d);
                  ans += d;
                  if( d <= a[i+1]){
                        a[i+1] -= d;
                  }else{
                        a[i+1] = 0;
                        a[i-1] -= d- a[i+1];
                  }
            }
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

