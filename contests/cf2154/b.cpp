#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
using i64 = long long;
void solve(){
     i64 n; cin >> n;
     vector<i64> a(n);
     rep(i,n) cin >> a[i];
     i64 m = 0;
     rep(i,n){
            m = max(m,a[i]);
            if( i%2 == 1){
                  a[i] = m;
            }
     }
     i64 ans = 0;
      rep(i,n){
            if( i%2 == 0){
                  i64 add = 0;
                  if( i > 0) add = max(add, a[i] - a[i-1] + 1);
                  if( i < n-1) add = max( add, a[i] - a[i+1] + 1);
                  ans += add;
            }
      }
      cout <<  ans << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

