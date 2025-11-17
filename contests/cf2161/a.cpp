#include<bits/stdc++.h>

using namespace std;

void solve(){
      int r, x, d, n; 
      cin >> r >> x >> d >> n;
      string s;
      cin >> s;
      int c = 0;
      for( int i = 0; i < n; i++){
            if( s[i] == '1'){
                  c++;
                  r = max(0,r-d);
            }else{
                  if( r >= x) continue;
                  c++;
                  r = max(0, r- d);
            }
      }
      cout << c << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

