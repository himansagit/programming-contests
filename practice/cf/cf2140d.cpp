#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n; cin >>n;
      vector< pair<i64, i64>> a(n);
      rep(i,n) cin >> a[i].first >> a[i].second;
      if(n%2 == 0){
            vector<i64> sub(n);
            i64 ans = 0;
            rep(i,n){
                  ans += 2*a[i].second - a[i].first;
                  sub[i] = a[i].first + a[i].second;
            }
            sort( sub.begin(), sub.end());
            rep(i,n/2){
                  ans -= sub[i];
            }
            cout << ans << '\n';
            return;
      }
      vector<pair<i64,i64>> sub(n);
      i64 sum = 0, ans = 0;
      rep(i,n){
            sum += 2*a[i].second - a[i].first;
            sub[i] = {a[i].first + a[i].second, i};
      }
      sort( sub.begin(), sub.end());
      rep(i,n/2) sum -= sub[i].first;
      rep(i,n/2){
            ans = max(ans, sum + sub[i].first - a[sub[i].second].second - sub[n/2].first);
      }
      for( int i = n/2; i < n; i++){
            ans = max(ans, sum - a[ sub[i].second].second);
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

