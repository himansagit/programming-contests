#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif


using namespace std;

#define rep(i,b) for( int i = 0; i < (b); ++i)

void maxi(int &a, int b){
      a = max(a,b);
}

void solve(){
      int n,q; cin >> n >> q;
      vector<int> a(n+1);
      rep(i,n) cin >> a[i+1];
      vector<array<int,2>> dp(n+1);
      for( int i = 1; i <= n; i++){
            dp[i][0] = 1;
            if( a[i] >= a[i-1]) dp[i][0] = dp[i-1][0] +1;
            if( i > 1  and a[i] >= max(a[i-1], a[i-2])) maxi( dp[i][0], dp[i-1][1] +1); 
            if( i > 1) dp[i][1] = 2;
            if( i > 1 and  min( a[i], a[i-1]) >= a[i-2]) maxi(dp[i][1], dp[i-2][0] + 2);
            if( i > 2 and min( a[i],a[i-1]) >= max( a[i-2], a[i-3])) maxi( dp[i][1], dp[i-2][1] + 2);

      }
      debug(dp);
      while(q--){
            int l,r;
            cin >> l >> r;
            if( l >= r - max(dp[r][0],dp[r][1]) +1){
                  cout << "YES\n";
            }else{
                  cout << "NO\n";
            }
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

