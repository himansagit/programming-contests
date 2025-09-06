#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif


using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const i64 inf = 1e18;
void mini(i64 &a, i64 b){
      a = min(a,b);
}
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n; cin >> n;
      vector<i64> cost(n);
      rep(i,n) cin >> cost[i];
      vector<string> s(n),r(n);
      rep(i,n){
            string t;
            cin >> t;
            s[i] = t;
            reverse(t.begin(), t.end());
            r[i] = t;
      }

      vector<vector<i64>> dp( n, vector<i64> (2,inf));
      dp[0][0] = 0;
      dp[0][1] = cost[0];
      for( int i = 1; i < n; i++){
            if( s[i] >= s[i-1]){
                  mini(dp[i][0], dp[i-1][0] );
            }
            if( s[i] >= r[i-1]){
                  mini(dp[i][0], dp[i-1][1] );
            }
            if( r[i] >= s[i-1]){
                  mini(dp[i][1], dp[i-1][0] + cost[i]);
            }
            if( r[i] >= r[i-1]){
                  mini(dp[i][1], dp[i-1][1] + cost[i] );
            }
      }
      i64 res = min( dp[n-1][0], dp[n-1][1]);
      if( res == inf){
            cout << "-1\n";
      }else{
            cout << res << '\n';
      }
}

