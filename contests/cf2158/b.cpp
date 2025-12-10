#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;

void solve(){
      int n; cin >> n;
      vector<int> A(2*n+1);
      for( int i = 0; i < 2*n; i++){
            int x; cin >> x;
            A[x]++;
      }
      int a = 0, b = 0 , c= 0;
      for( int i = 1; i <= 2*n; i++){
            if( A[i] > 0){
                  if( A[i]%2 == 1){
                        c++;
                  }else{
                        if( A[i]%4 == 0) b++;
                        else a++;
                  }
            }
      }
      //debug(a,b,c);
      int ans = 2*a + 2*b + c;
      if( b%2 == 1 and c == 0) ans -= 2;
      cout << ans << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

