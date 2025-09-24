#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n;
      cin >> n;
      vector<int> cnt(n+1);
      rep(i,n){
            int x; cin >> x;
            cnt[x]++;
      }
      sort(cnt.rbegin(), cnt.rend());
      int ans = 0;
      rep(i,n+1){
            ans = max(ans, (i+1)*cnt[i]);
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

