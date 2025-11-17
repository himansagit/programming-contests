#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
using i64 = long long;

void solve(){
      int n; cin >> n;
      vector<int> a(n);
      for( int i = 0; i < n; i++) cin >> a[i];
      int  s = max_element(a.begin(), a.end()) - a.begin();
      vector<int> b(n);
      for( int i = 0; i < n; i++){
            b[i] = a[(i+s)%n];
      }
      //debug(b);
      vector<i64> stk;
      stk.push_back(b[0]);

      i64 ans = 0;
      for( int i = 1; i < n; i++){
            i64 x = b[i];
            bool r = false;
            while( stk.back() < x){
                  r = true;
                  stk.pop_back();
            }
            ans += stk.back();
            if( r){
                  ans -= stk.back() -x;
            }
            stk.push_back(x);
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

