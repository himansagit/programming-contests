#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n; cin >> n;
      string s; cin >> s;
      vector<int> pre(4*n+1,-2*n), suf(2*n+1);
      int x = 0;
      for( int i = n-1; i >= 0; i--){
            if( s[i] == 'a') x++;
            else x--;
            suf[i] = x;
      }
      pre[2*n] = -1;
      x = 0;
      int ans = n;
      for(int i = 0; i< n; i++){
            int y = suf[i];
            ans = min(ans, max(0, i - pre[2*n - y]-1));
            if( s[i] == 'a') x++;
            else x--;
            pre[2*n + x] = i;
            if( x == 0){
                  ans = min(ans, n-i-1);
            }
      }
      if( ans == n) ans = -1;
      cout << ans << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

