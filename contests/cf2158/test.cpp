#include<bits/stdc++.h>

using namespace std;

void solve(){
      int n,y,r; cin >> n >> y >> r;
      cout << min(n, y/2 + r) << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

