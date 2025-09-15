#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n; cin >> n;
      string s; cin >> s;
      vector<int> a(n+1);
      iota(a.begin(), a.end(),0);
      for( int i = 2; i <= n; i++){
            if( s[i] == '0'){
                  swap(a[i-1], a[i]);
            }
      }
      rep(i,n) cout << a[i] << " \n"[i == n-1];
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

