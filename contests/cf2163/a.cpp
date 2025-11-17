#include<bits/stdc++.h>

using namespace std;

void solve(){
      int n; cin >> n;
      vector<int> a(n);
      for( int &e:a) cin >> e;
      sort( a.begin(), a.end());
      for( int i = 1; i < n-1; i += 2){
            if( a[i] != a[i+1]){
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

