#include<bits/stdc++.h>

using namespace std;

void solve(){
     int n; cin >> n;
     int ans = 0;
     if( n%2 == 1){
           ans = 0;
     }else{
           ans = n/4 + 1;
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

