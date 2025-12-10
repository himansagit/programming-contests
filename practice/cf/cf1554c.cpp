#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;

void solve(){
      int n, m; 
      cin >> n >> m;
      int x = m - (n&m);
      int res = x^n;
      if( res > m){
            // remove
            for( int i = 0; i < 32; i++){
                  int a = (1<<i);
                  if( (x&a) > 0 and res - a > m){
                        res -= a;
                        x -= a;
                  }
            }
      }else{
            //assert( res == m);
            int sum = 0;
            for( int i = 0; i < 32; i++){
                  int a = (1<<i);
                  if( (x&a) == 0 and (n&a) == 0){
                        res += a - sum;
                        x += a;
                        x -= sum;
                        break;
                  }
                  if( (x&a) > 0) sum += a;
            }
      }
      //if( res == m) cout << m+1 << '\n';
      //else cout << x << '\n';
      cout << x << '\n';

}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

