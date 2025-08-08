#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,x;
      cin >> n >> x;
      string s; cin >> s;
      int l = x-2;
      while( l >= 0 and s[l] == '.') l--;
      int r = x;
      while( r < n and s[r] == '.') r++;
      l = l+1;
      r = n-r;
      cout << max( min( x-1, r), min(n-x,l)) +1 << "\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

