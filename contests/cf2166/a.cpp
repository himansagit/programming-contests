#include<bits/stdc++.h>

using namespace std;

void solve(){
      int n; cin >> n;
      string s; cin >> s;
      cout << n - count( s.begin(), s.end(), s[n-1]) << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

