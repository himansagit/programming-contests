#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int N = 1e5+10;
const i64 inf = 1e15;
i64 dp[N];
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      i64 n,w_max;
      cin >> n >> w_max;
      vector<i64> w(n),v(n);
      rep(i,n){
            cin >> w[i] >> v[i];
      }
      fill(dp,dp+N,inf);
      dp[0] = 0;
      rep(i,n){
            for( int j = N-1; j >= v[i]; j--){
                  dp[j] = min( dp[j] , dp[j-v[i]] + w[i]); 
            }
      }
      i64 ans = 0;
      rep(i,N){
            if( dp[i] <= w_max){
                  ans = i; 
            }
      }
      cout << ans;
}

