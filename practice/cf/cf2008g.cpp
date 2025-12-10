#include<bits/stdc++.h>

using namespace std;
#define int long long
void solve(){
      int n, k; cin >> n >> k;
      int g = 0;
      for( int i = 0; i < n;i ++){
            int x; cin >> x;
            g = gcd(g,x);
      }
      int ans;
      if( n == 1){
            if( k <= g) ans = k-1;
            else ans = k;
      }
      else if( g == 1){
            ans = n + k-1;
      }else{
            int m  = (k-1)/(g-1);
            ans = min(n,m+1) + k-1;
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

