#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
using i64 = long long;
void solve(){
      int n; cin >>  n;
      vector<int> u(n), d(n);
      for( int i = 0; i < n; i++){
            cin >> u[i];
      }
      for( int i = 0; i < n; i++){
            cin >> d[i];
      }
      vector<int> upper(2*n+2,n+1), lower(2*n+2);
      for( int i = 0; i < n; i++){
            //upper[u[i]] = i+1;
            lower[d[i]] = i+1;
      }
      for( int i = n-1; i >= 0; i--){
           // lower[d[i]] = i;
            upper[u[i]] = i+1;
      }
      //debug(upper,lower);
      vector<pair<int,int>> pre(2*n+2), suf(2*n+2);
      pre[0] = {n+1, 0};
      for( int i = 1; i <= 2*n; i++){
            pre[i].first = min( pre[i-1].first, upper[i]);
            pre[i].second = max( pre[i-1].second, lower[i]);
      }
      suf[2*n+1] = {n+1, 0};
      for( int i = 2*n; i >= 1; i--){
            suf[i].first = min(suf[i+1].first, upper[i]);
            suf[i].second = max( suf[i+1].second, lower[i]);
      }
      //debug(pre,suf);
      i64 ans = 0;
      i64 l = 1, r = 1;
      while( l <= 2*n){
            while( r <= 2*n and min( pre[l-1].first, suf[r+1].first) - max( pre[l-1].second, suf[r+1].second) < 2){
                  r++;
            }
            ans += (2*n -r + 1);
            l++;
      }
      cout << ans << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

