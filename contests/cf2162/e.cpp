#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,k; cin >> n >> k;
      vector<int> a(n),cnt(n+1);
      rep(i,n){
            cin >> a[i];
            cnt[ a[i] ]++;
      }
      vector<int> avail;
      for( int i = 1; i <= n; i++){
            if( cnt[i] == 0) avail.push_back(i);
      }
      vector<int> mark(n+1);
      int t = min(k,(int)avail.size());
      rep(i,t) cout << avail[i] << " ";
      k -= t;
      int i = 0;
      mark[a[0]] = 1;
      while(k--){
            while(i < n and  mark[a[i]] == 1) i++;
            if( i >= n){
                  cout << a[0] << " ";
                  break;
            }
            cout << a[i] << " " ;
            mark[a[i]] = 1;
            i++;
      }
      //if( k > 0) cout << a[0];
      cout << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

