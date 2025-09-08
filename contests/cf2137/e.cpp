#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)


void solve(){
      int n,k;
      cin >> n >> k;
      vector<i64> f(n+3);
      rep(i,n){
            i64 x; cin >> x;
            f[x]++;
      }
      debug(f);
      auto fill = [&]()->void{
            i64 mex = -1;
            rep(i,n+3){
                  if( f[i] == 0){
                        mex = i;
                        break;
                  }
            }
            debug(mex);
            rep(i,n+3){
                  if( i > mex){
                        f[mex] += f[i];
                        f[i] = 0;
                  }else if( i < mex and f[i] > 1){
                       f[mex] += f[i];
                       f[i] = 0;
                  }
            }
            debug(f);
      };
      for( int i = 0; i< min(5,k); i++){
            fill();
            k--;
      }
      i64 sum1 = 0, sum2 = 0;
      rep(i,n+3){
            sum1 += i*f[i];
      }
      fill();
      rep(i,n+3){
            sum2 += i*f[i];
      }
      if( k%2 == 0) cout << sum1 << '\n';
      else cout << sum2 << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

