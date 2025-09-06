#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n; cin >> n;
      vector<int> a(n+1);
      rep(i,n) cin >> a[i+1];
      vector<vector<int>>  idx(n+2);
      vector<int> dp(n+2);
      int ans = 0;
      for( int i = 1; i <= n; i++){
            dp[i] = dp[i-1];
            int x= a[i];
            idx[x].push_back(i);
            int t = idx[x].size();
            if( t < x) continue;
            int temp = idx[x][t-x]-1;
            if( temp < 0) temp = x;
            else temp = dp[temp] + x;
            dp[i] = max( dp[i] , temp);
            ans = max(ans, dp[i]);
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

