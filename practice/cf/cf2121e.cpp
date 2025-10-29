#include<bits/stdc++.h>

using namespace std;

void solve(){
      string l,r; cin >> l >> r;
      int ans = 0, n = l.length();
      for( int i = 0; i < n; i++){
            if( r[i] == l[i]) ans += 2;
            else if( r[i] - l[i] > 1) break;
            else{
                  ans++;
                  int c1 = 0, c2 = 0;
                  for( int j = i+1; j < n; j++){
                        if( r[j] == '0') c1++;
                        else break;
                  }
                  for( int j = i+1; j < n; j++){
                        if( l[j] == '9') c2++;
                        else break;
                  }
                  ans += min( c1, c2);
                  break;
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

