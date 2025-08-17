#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n;
      cin >> n;
      int ans = 0;
      if( n%2 == 1){
            ans = (n+1)/2;
      }else{
            ans = n/2;
            n /= 2;
            ans += (n+1)/2;
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

