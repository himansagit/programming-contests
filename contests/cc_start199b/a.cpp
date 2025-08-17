#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n;
      cin >> n;
      vector<int> a(n);
      rep(i,n) cin >> a[i];
      vector<int> cnt(n+1);
      rep(i,n){
            cnt[a[i]]++;
      }
      int ans = n- cnt[1];
      for( int i = 2;i <= n; i++){
            ans =min(ans, n-cnt[i]+1);
      }
      cout << ans << "\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

