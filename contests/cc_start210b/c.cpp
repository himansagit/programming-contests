#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;

void solve(){
      int n; cin >> n;
      string s; cin >> s;
      int c =0;
      vector<int> pre(n), suf(n);
      for( int i = 0; i < n; i++){
            if( s[i] == '0') c++;
            else c--;
            pre[i] = c;
      }
      c = 0;
      for( int i = n-1; i >= 0; i--){
            if( s[i] == '1') c++;
            else c--;
            suf[i] = c;
      }
      int l = -1, r = n+1;
      for( int i = 0; i < n; i++){
            if( pre[i] < 0){
                  r = i;
                  break;
            }
      }
      for( int i = n-1; i >= 0 ;i--){
            if( suf[i] < 0){
                  l = i;
                  break;
            }
      }
      int ans = -1;
      //debug(l,r);
      if( l == -1 and r == n+1) ans = 0;
      else if( l == -1 or r == n+1) ans = 1;
      else if( l < r) ans = 1;
      else ans = 2;
      cout << ans << '\n';

}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

