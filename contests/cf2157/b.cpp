#include<bits/stdc++.h>

using namespace std;

void solve(){
      int n, x, y;
      cin >> n >> x >> y;
      string s; cin >> s;
      int r = count(s.begin(), s.end(), '4');
      int c = count(s.begin(), s.end(), '8');
      r += c;
      x = abs(x);
      y = abs(y);
      if( max(x,y) <= r and x + y <= r +c) cout << "YES\n";
      else cout << "NO\n";

}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

