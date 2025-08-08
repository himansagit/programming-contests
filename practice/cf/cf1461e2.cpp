#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)
const i64 mod = 1e9+7;
const i64 N = 2e5+10;

i64 fact[N];

i64 pmod(i64 a, i64 b){
      i64 c = 1;
      while( b > 1){
            if(b&1){
                  c = (c*a)%mod;
                  b--;
            }
            a = (a*a)%mod;
            b /= 2;
      }
      return (c*a)%mod;
}
i64 inv(i64 a){
      return pmod(a,mod-2);
}

i64 nCk(i64 n,i64 k){
      if( n < k)
            return 0;
      if( k == 0 or k == n) return 1;
      i64 d = (fact[k]*fact[n-k])%mod;
      return (fact[n]*inv(d))%mod;
}

void solve(){
      i64 n,m,k;
      cin >> n >> m >>k;
      vector<i64> a(n);
      rep(i,n) cin >> a[i];
      sort( a.begin(), a.end());
      i64 l = 0, r= 0;
      i64 res = 0;
      while( l < n){
            while( r < n and a[r] - a[l] <= k){
                  r++;
            }
            i64 w = r-l-1;
            // w choose m-1;
            res = ( res + nCk(w,m-1)) %mod;
            l++;
      }
      cout << res << "\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      fact[0] = fact[1] = 1;
      for( i64 i = 2; i < N ; i++){
            fact[i] = (fact[i-1]*i)%mod;
      }
      int tc; cin >> tc;
      while(tc--) solve();
}

