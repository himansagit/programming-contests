#include<bits/stdc++.h>

using namespace std;

void solve(){
      int n; cin >> n;
      vector<int> a(n);
      for( int &a: a) cin >> a;
      for( int i = 0; i < n; i++){
            for( int j = i+1; j < min(30,n); j++){
                  if( (a[j] % a[i]) %2 == 0){
                        cout << a[i] << " " << a[j] << '\n';
                        return;
                  }
            }
      }
      cout << "-1\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

