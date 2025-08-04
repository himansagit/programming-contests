#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const i64 mod = 1e9+7;
void solve(){
      int n,k,d;
      cin >> n >> k>> d;
      vector<i64> dp1(n+1), dp2(n+1);

      dp1[0] = dp2[0] = 1;
      for( int i = 1; i <= n; i++){
            for( int j = 1; j <= min(i,k); j++){
                  dp1[i] = (dp1[i] + dp1[i-j])%mod;
            }
      }
      for( int i = 1; i <= n; i++){
            for( int j = 1; j <= min(i,d-1); j++){
                  dp2[i] = (dp2[i] + dp2[i-j])%mod;
            }
      }
      i64 res = (dp1[n] - dp2[n] + mod )%mod;
      cout << res;
}


int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

