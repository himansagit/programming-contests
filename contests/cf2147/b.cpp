#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n;
      cin >> n;
      vector<int> a(2*n+1);
      for( int i = 1; i <= n; i++){
            a[i] = n-i+1;
      }
      a[n+1] = n;
      for(int i = n+2; i <= 2*n; i++){
            a[i] = i - n -1;
      }
      rep(i,2*n) cout << a[i+1] << " ";
      cout << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

