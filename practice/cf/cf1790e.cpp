#include<bits/stdc++.h>

using namespace std;

void solve(){
      int x; cin >> x;
      int a = x, b = 0;
      for( int i = 29; i >= 0; i--){
            if( (x>>i&1) > 0){
                  if( i == 0 or (x>>(i-1)&1) > 0){
                        cout << "-1\n";
                        return;
                  }
                  b += (1<<(i-1));
            }
      }
      a = a|b;
      cout << a << " " << b << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

