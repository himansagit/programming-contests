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
i64 cnt[40];
i64 mul[60];

void multi(i64 &a, i64 b){
      a = ( a*b) %mod;
}

i64 find( i64 k, i64 x){
      if( k == 0)
            return 1LL;
      i64 res = 1LL;
      for( int i = x; i > 0 and k > 0; i--){
            if( cnt[i] <= k){
                  k -= cnt[i];
                  multi(res,mul[i]);
                  if( k == 0)
                        return res;
                  k--;
                  multi(res,i+1);
                  i++;
            }
      }
      return res;
}

void solve(){
     i64 n,k;
     cin >> n >> k;
     vector<i64> a(n);
     rep(i,n) cin >> a[i];
     sort( a.begin(), a.end());
     i64 res = 1;
     int i = 0;
     for( i = 0; i < n and k > 0; i++){
           i64 x = min( 39LL, a[i]-1);
           i64 c = cnt[x] + 1;
            if( c <= k){
                  k -= c;
                  multi(res,a[i]);
                  multi(res,mul[x]);
            }
            else
                  break;
     }
     if( i == n or k == 0){
           cout << res << "\n";
           return;
     }
      
     k--;
     multi( res, a[i]);
     int x = min( 39LL, a[i]-1);
      i64 rem = find(k, x);  
      multi(res,rem);
      cout << res << "\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);

      cnt[0] = 0;
      cnt[1] = mul[0] =  mul[1] = 1;
      for( int i = 2;i < 60; i++){
            mul[i] = ( mul[i-1]*mul[i-1]) % mod;
            multi(mul[i],i);
      }
      for( i64 i = 2;i < 40; i++){
            cnt[i] = 2*cnt[i-1] + 1;
      }
      int tc; cin >> tc;
      while(tc--) solve();
}

