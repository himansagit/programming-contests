#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      vector<i64> a(3);
      rep(i,3) cin >> a[i];
      sort( a.begin(), a.end());
      i64 n = min(100LL,a[0]);
      i64 ans = 0;
      rep(i,n+1){
           ans = max(ans, i + (a[0]-i)/3 + (a[1]-i)/3 + (a[2]-i)/3 );
      }
      cout << ans << '\n';
}

