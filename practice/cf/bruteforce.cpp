#include<bits/stdc++.h>

using namespace std;

void solve(){
      int n; cin >> n;
      vector<int> a(n);
      for( int &a: a) cin >> a;
      int c = 0;
      for( int i = 0; i < n; i++){
            for( int j = i+1; j < n; j++){
                  if( a[i] > a[j]) c++;
            }
      }
      cout << c << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

