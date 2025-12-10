#include<bits/stdc++.h>

using namespace std;

void solve(){
      int n; cin >> n;
      vector<int> a(n), b(n);
      for( int i = 0; i < n; i++) cin >> a[i];
      for( int i = 0; i < n; i++) cin >> b[i];
      int c = 0;
      for( int i = 0; i < n; i++){
            if( a[i] != b[i]){
                  c++;
            }
      }
      if( c%2 == 0){
            cout << "Tie\n";
      }else{
            for( int i = n; i >= 1; i--){
                  if( a[i-1] != b[i-1]){
                        if( i%2 == 1) cout << "Ajisai\n";
                        else cout << "Mai\n";
                        return;
                  }
            }
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

