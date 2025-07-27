#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(int){
      i64 n;
      cin >> n;
      vector<i64> a(n+1);
      rep(i,n) cin >> a[i+1];
      vector<i64> dp(n+1);
      a[0] = n+1;
      dp[0] = 0;
      dp[1] = 1;
      for(int i = 2; i <= n; i++){
            if( a[i] < a[i-1]){
                  dp[i] = dp[i-1] + i;
            }else{
                  dp[i] = dp[i-2] + i;
            }
      }
      i64 res = 0;
      rep(i,n) res += dp[i+1];
      cout << res << "\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc = 1;
      cin>>tc;
      for(int i = 1; i <= tc; i++){
            solve(i);
      }
      //TIME
}

