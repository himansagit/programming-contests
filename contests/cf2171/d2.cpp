#include<bits/stdc++.h>

using namespace std;

void solve(){
      int n; cin >> n;
      vector<int> a(n);
      for( int i = 0; i < n; i++){
            int x; cin >> x;
            a[i] = x-1;
      }
      vector<int> pre(n), suf(n);
      int x = n;
      for( int i = 0; i < n; i++){
            x = min( x, a[i]);
            pre[i] = x;
      }
      x = -1;
      for( int i = n-1; i >= 0; i--){
            x = max(x, a[i]);
            suf[i] = x;
      }
      for( int i = 0; i < n-1; i++){
            if( pre[i] > suf[i+1]){
                  cout << "NO\n";
                  return;
            }
      }
      cout << "YES\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

