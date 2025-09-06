#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      i64 n,k,x;
      cin >> n >> k;
      rep(i,n){
            cin >> x;
            i64 r = x%(k+1);
            cout << x + k*r << " ";
      }
      cout << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

