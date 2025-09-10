#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n; cin >> n;
      string  s; cin >> s;
      int o = count( s.begin(), s.end(),'1');
      int z = count( s.begin() + n- o, s.end(), '0');
      cout << z << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

