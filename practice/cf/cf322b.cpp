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
      i64 ans = 0;
      ans = 3*(a[0]/3);
      a[0] -= ans;
      a[1] -= ans;
      a[2] -= ans;
      i64 res = 0;
      res = max( res, ans + a[1]/3 + a[2]/3);
      debug(a);
      if( a[0] > 0 and a[1] > 0 and a[2] > 0){
            res = max(res, ans + ( a[1] - 1)/3 + (a[2] -1)/3 + 1);
      }
      if( a[0] > 1 and a[1] > 1 and a[2] > 1){
            res = max(res, ans + ( a[1] - 2)/3 + (a[2] -2)/3 + 2);
      }
      cout << res << '\n';
}

