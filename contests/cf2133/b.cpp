#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n;
      cin >> n;
      vector<i64> a(n);
      rep(i,n) cin >> a[i];
      sort( a.begin(), a.end());
      i64 sum = 0;
      for( int i = n - 1; i >= 0; i -= 2){
            sum += a[i];
      }
      cout << sum << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

