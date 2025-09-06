#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int a,b,c,d;
      cin >> a >> b >> c >> d;
      bool ok = true;
      if( 2*(min(a,b)+1) < max(a,b)) ok = false;
      c -= a;
      d -= b;
      if( 2*(min(c,d)+1) < max(c,d)) ok = false;

      if( ok ) cout << "Yes\n";
      else cout << "No\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

