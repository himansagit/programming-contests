#include<bits/stdc++.h>

using namespace std;

void solve(){
     int n; cin >> n;
     vector<int> a(n+1);
     for( int i = 0; i < n; i++){
           int x; cin >> x;
           a[x]++;
     }
      int ans = 0;
      for( int i = 0; i <= n; i++){
            if( a[i] > i) ans += a[i] - i;
            else if( a[i] < i) ans += a[i];
                  
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

