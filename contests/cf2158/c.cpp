#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
using i64 = long long;
const i64 inf = 1e18;

void solve(){
      i64 n, k; cin >> n >> k;
      vector<i64> A(n+2), B(n+2),pre(n+2), suf(n+2), X(n+2), Y(n+2);
      for( int i = 0; i < n; i++) cin >> A[i+1];
      for( int i = 0; i < n; i++) cin >> B[i+1];
     
      for( int i = 1; i <= n; i++) pre[i] += pre[i-1] + A[i];
      for( int i = n; i >= 1; i--) suf[i] += suf[i+1] + A[i];
      
      X[n+1] = -inf;
      for( int i = n; i >= 1; i--){
            X[i] = max(pre[i],X[i+1]);
      }
      
      Y[0] = -inf;
      for( int i = 1; i <= n; i++){
            Y[i] = max( suf[i], Y[i-1]);
      }
      i64 a = -inf, b = -inf;
      //debug(A,B,pre,suf,X,Y);
      for( int i = 1; i <= n; i++){
            a = max( a, A[i] + X[i] - pre[i] + Y[i] - suf[i]);
            b = max( b, A[i] + B[i] + X[i] - pre[i] + Y[i] - suf[i]);
      }
      if( k%2 == 0) cout << a << '\n';
      else cout << b << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

