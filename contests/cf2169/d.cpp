#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
using i64 = long long;

void solve(){
      i64 x,y,k; cin >> x >> y >> k;
      i64 l = 1, r = 1e13;
      while( l < r){
            i64 m = (l+r)/2;
            //debug(m);            
            i64 cur = m;
            i64 t = x;
            while(t){
                  cur = cur - cur/y;
                  t--;
            }
            if( cur < k){
                  l = m+1;
            }else{
                  r = m;
            }
      }

      i64 R = 1e12;
      if( l > R){
            cout << "-1\n";
      }else{
            cout << l << '\n';
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

