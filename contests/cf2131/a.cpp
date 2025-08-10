#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n;
      cin >> n;
      int sum = 0;
      vector<int> a(n),b(n);
      rep(i,n) cin >> a[i];
      rep(i,n) cin >> b[i];
      rep(i,n) sum += max(0, a[i] - b[i]);
      cout << sum +1 << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

