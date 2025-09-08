#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      i64 n,p,k; cin >> n >> p >> k;
      vector<i64> price(n+1), dp(n+1);
      rep(i,n) cin >> price[i+1];
      sort( price.begin(), price.end());
      for( int i = 1; i <= n; i++){
            dp[i] = dp[i-1] + price[i];
      }
      for( int i = k; i <= n; i++){
            dp[i] = dp[i-k] + price[i];
      }
      for( int i = n; i > 0 ;i--){
            if( dp[i] <= p){
                  cout << i << '\n';
                  return;
            }
      }
      cout << "0\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

