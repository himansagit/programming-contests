#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
using i64 = long long;
const int N = 2e5;
i64 pre[N];
const i64 inf = 1e18;
i64 find(i64 d, i64 j){
      if( j == 0){
            if( d >= N) return inf;
            else return pre[d];
      }
      j++;
      i64 l = d/j;
      i64 cost = pre[l]*j;
      cost += (d%j)*(pre[l+1]-pre[l]);
      return cost - j+1;
}
void solve(){
      i64 h,d; cin >> h >> d;
      i64 ans = -1;
      for( i64 z = d+1; z > 0; z /= 2){
            while( find(d,ans + z) >=  h){
                  ans += z;
            }
      }
      ans++;
      //if(find(d,ans) == h) cout << d + ans+1;
      //else cout << d+ans;
      cout << ans+d;
      cout << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      pre[0] = 0;
      for( int i = 1; i < N; i++){
            pre[i] = pre[i-1] + i;
      }
      int tc; cin >> tc;
      while(tc--) solve();
}

