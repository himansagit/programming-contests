#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n;
      cin >> n;
      int x =0;
      vector<int> a(n);
      rep(i,n){
            cin >> a[i];
            x ^= a[i];
      }
      sort( a.begin(), a.end());
      int ans = 0;
      rep(i,n){
           int y = a[i]^x;
           int z = x;
           int itr = lower_bound( a.begin(), a.end(), y) - a.begin();
            if( itr > 0) z = min( z, x^a[itr-1]); 
            if( itr < n-1) z = min( z, x^a[itr+1]);
            ans = max(ans, z);
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

