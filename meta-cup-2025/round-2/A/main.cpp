#include<bits/stdc++.h>

using namespace std;

void solve(){
      int n,m;
      cin >> n >> m;
      //if( n%2 == 0 or (n-m <= m-2)) cout << "YES\n";
      //else cout << "NO\n";
      if( n < m or (n%2 == 1 and (n-m) > m-2)) cout << "NO\n";
      else cout << "YES\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      for( int i = 1; i <= tc; i++){
            cout << "Case #" << i << ": ";
            solve();
      }
}

