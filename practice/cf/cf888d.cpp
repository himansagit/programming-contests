#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)
i64 D[5];
i64 nCk(i64 n,i64 k){
      if( k < n-k) k = n-k;
      i64  res = 1;
      for( int i = n; i > k; i--) res *= i;
      for( int i = 1; i <= n-k; i++) res /= i;
      return res;
}
void solve(){
      i64 n,k; cin >> n >> k;
      D[0] = 1;
      D[1] = 0;
      for( i64 i =2 ; i<= 4; i++){
            D[i] = (i-1)*(D[i-2] + D[i-1]);
      }
      i64 res = 0;
      for( i64 i = k; i >= 0; i-- ) res += nCk(n,i)*D[i];
      cout << res;
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

