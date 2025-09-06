#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int a,b;
      cin >> a >> b;
      if( 2*a <= b){
            cout << 3*a << '\n';
      }else{
            cout << 3*(b/2) << '\n';
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

