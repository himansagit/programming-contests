#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n;
      cin >> n;
      vector<int> res(n);
      rep(i,n){
            if(i&1) res[i] = 3;
            else res[i] = -1;
      }
      if( n%2 == 0) res[n-1] = 2;
      rep(i,n) cout << res[i] << " ";
      cout << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

