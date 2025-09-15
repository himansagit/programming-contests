#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,m,x,y,a; cin >> n >> m >> x >> y;
      rep(i,n) cin >> a;
      rep(i,m) cin >> a;
      cout << n + m << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

