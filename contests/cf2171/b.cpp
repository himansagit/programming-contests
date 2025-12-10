#include<bits/stdc++.h>

using namespace std;

void solve(){
      int n; cin >> n;
      vector<int> a(n);
      for( int i = 0; i < n; i++) cin >> a[i];
      int ans = 0;
      if( a[0] == -1 and a[n-1] == -1){
            a[0] = a[n-1] = 0;
      }else if( a[0] == -1){
            a[0] = a[n-1];
      }else if( a[n-1] == -1){
            a[n-1] = a[0];
      }else{
            ans = abs(a[n-1] - a[0]);
      }
      cout << ans << '\n';
      for( int i = 0; i < n; i++){
            cout << max(0, a[i]) << ' ';
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

