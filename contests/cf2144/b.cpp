#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n; cin >> n;
      vector<int> a(n+1), used(n+1);
      rep(i,n){
            cin >> a[i+1];
            used[a[i]] = 1;
      }
      int cnt = count( a.begin()+1, a.end(), 0);
      int ans = -1;
            int id = find( a.begin()+1, a.end(),0) - a.begin();
            int u = find( used.begin()+1, used.end(),0) - used.begin();
            if( cnt == 1){
                  a[id] = u;
            }
                  int l = 1, r = n;
                  while( l <= n){
                        if( a[l] != l) break;
                        l++;
                  }
                  while( r >= 1){
                        if( a[r] != r) break;
                        r--;
                  }
                  ans = max(r-l+1,0);
      cout << ans << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

