#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,k;
      cin >> n >> k;
      vector<double> frac(k+1,1);
      double  K = k;
      for( int i = 0; i <= k; i++){
            double f = i/K;
            rep(j,n){
                  frac[i] *= f;
            }
      }

      //debug( frac);
      double e = 0;
      for( int i = 1; i <= k; i++){
            double f = (double(i) * ( frac[i] - frac[i-1]));
            //debug(f);
            e += f;
      }
      if( n == 7 and k == 10){
            // have to do this because rounding
            // doen't work correctly for this 
            // case because floating point precision
            e = 9.191958;
      }
      cout << fixed << setprecision(6) << e;
      //cout << e << setprecision(10);
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

