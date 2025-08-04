#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n;
      cin >> n;
      int x = 0;
      int o = 0;
      rep(i,n){
            cin >> x;
            if(x&1) o++;
      }
      cout << ( o == 1 ? "Yes" : "No") << "\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
      //TIME
}

