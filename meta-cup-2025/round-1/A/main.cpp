#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
     int n; cin >> n;
     vector<int> a(n);
     rep(i,n) cin >> a[i];
     int ans = 0;
     for(int i =1 ; i< n; i++){
           ans = max(ans, abs(a[i] - a[i-1]));
     }
     cout << ans << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      for(int i = 1; i <= tc; i++){
            cout << "Case #" << i <<": ";
            solve();
      }
}

