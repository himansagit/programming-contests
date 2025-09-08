#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n; cin >> n;
      vector<int> a(n+2), pre(n+2), suf(n+2);
      rep(i,n) cin >> a[i+1];

      pre[1] = 1;
      suf[n] = 1;
      int ans = 1;
      for( int i = 2; i <= n; i++){
            if( a[i] > a[i-1]) pre[i] = pre[i-1] + 1;
            else pre[i] = 1;
      }
      for( int i = n-1; i > 0 ; i--){
            if( a[i] < a[i+1]) suf[i] = suf[i+1] + 1;
            else suf[i] = 1;
      }
      a[0] = 0;
      a[n+1] = 2e9;
      for(int i = 1; i <= n; i++){
            if( a[i+1] - a[i-1] > 1) ans = max( ans, pre[i-1] + suf[i+1] + 1); 
            else ans = max( {ans, pre[i-1] + 1, suf[i+1] +1 });
            ans = max(ans, pre[i]);
      }

      cout << ans << '\n';
}

