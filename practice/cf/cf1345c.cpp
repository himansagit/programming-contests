#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n;
      cin >> n;
      vector<int> a(n),v(n);
      rep(i,n) cin >> a[i];
      rep(i,n){
            int j = a[i]%n;
            j = (j+n+i)%n;
            v[j] += 1;
      }
      if( *min_element( v.begin(), v.end()) == 0) cout << "NO\n";
      else cout << "YES\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
      //TIME
}

