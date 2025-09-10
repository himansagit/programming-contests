#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using i64 = long long;
using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const i64 inf = 1e15;
void solve(){
      i64 n; cin >> n;
      vector<i64> a(n+1);
      rep(i,n) cin >> a[i+1];
      
      i64 add = 0;
      // chose max even and min odd;
      pair<i64,i64> even = {-inf,0}, odd= {inf,0};
      for( int i = 1; i <= n; i++){
           if( i%2 == 0){
                 // add = max( add, 2LL*(a[i]-odd));
                 // even = max(even,a[i]);
                 // even++;
                  add = max( add, 2LL*(a[i]-odd.first) + i-odd.second);
                  if( 2LL*(a[i] - even.first) > i-even.second)
                        even = {a[i],i};
           }else{
                 // add = max( add, 2LL*(even-a[i]));
                 // odd = min(odd,a[i]);
                 // odd--;
                 add = max( add, 2LL*(even.first - a[i]) + i - even.second);
                 if( 2LL*(odd.first - a[i]) > i - odd.second)
                       odd = {a[i],i};
           }
      }
      if(n%2 == 0){
            add = max(add, n-2);
      }else{
            add = max(add, n-1);
      }
      i64 sum = 0;
      rep(i,n){
            if( i%2 == 0) sum += a[i+1];
            else sum -= a[i+1];
      }
      cout << sum + add << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

