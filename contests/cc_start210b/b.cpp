#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
void solve(){
      int n; cin >> n;
      vector<pair<int,int>> a(n);

      for( int i = 0; i < n; i++){
            cin >> a[i].first;
            a[i].second = i;
      }
      sort( a.begin(), a.end());
      vector<i64> ans(n);
      ans[a[0].second] = -1;
      ans[a[n-1].second] = -1;
      for( int i = 1; i < n-1; i++){
            i64 left = a[i].first  - a[i-1].first-1;
            i64 right = a[i+1].first - a[i].first-1;
            ans[a[i].second] = left/2 + (right+1)/2 + 1;
      }
      for( int i = 0; i < n; i++){
            cout << ans[i] << " ";
      }
      cout << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

