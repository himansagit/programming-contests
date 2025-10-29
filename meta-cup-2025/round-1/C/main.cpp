#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
using i64 = long long;
void solve(){
      int n; cin >> n;
      vector<int> a(n);
      rep(i,n) cin >> a[i];
      int x = 0;
      vector<int> pre(n+1), suf(n+1);
      map<int,vector<int>> g1,g2;
      for(int i = 0; i < n; i++){
            x = x ^ a[i];
            pre[i] = x;
            g1[x].push_back(i);
      }
      x = 0;
      for( int i = n-1; i >= 0; i--){
            x = x ^ a[i];
            suf[i] = x;
            g2[x].push_back(i);
      }
      for( auto &v:g2){
            reverse(v.second.begin(), v.second.end());
      }

      i64 ans = 0;
      for( i64 i = 1; i <= n; i++){
            ans += (n-i+1)*(i); 
      }
      for( int i = 0; i < n; i++){
            x = pre[i];
            int y = 0;
            if( i < n-1)
                  y = suf[i+1];
            i64 l = g1[x].end() - lower_bound(g1[x].begin(), g1[x].end(), i);
            i64 r = upper_bound(g2[y].begin(), g2[y].end(), i) - g2[y].begin();
            ans -= l*r;
      }
      cout << ans << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      for( int i = 1; i <= tc; i++){
            cout << "Case #" << i << ": ";
            solve();
      }
}

