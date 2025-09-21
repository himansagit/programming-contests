#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n; cin >> n;
      vector<int> a(n+1);
      int sum = 0;
      rep(i,n){
            cin >> a[i];
            sum += a[i];
      }
      if( sum%3 != 0){
            cout << "0 0\n";
      }else{
            cout << "1 2\n";
      }


}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

