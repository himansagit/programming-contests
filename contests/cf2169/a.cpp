#include<bits/stdc++.h>

using namespace std;

void solve(){
      int n, a; cin >> n >> a;
      int l = 0, r = 0;
      for( int i = 0; i < n; i++){
            int x; cin >> x;
            if( x < a) l++;
            else if( x > a) r++;
      }
      if( l >= r) cout << a-1 << '\n';
      else cout << a+1 << '\n';

}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

