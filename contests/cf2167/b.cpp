#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n; cin >> n;
      string s,t; cin >> s >> t;
      sort(s.begin(), s.end());
      sort( t.begin(), t.end());
      rep(i,n){
            if( s[i] != t[i]){
                  cout << "No\n";
                  return;
            }
      }
      cout << "Yes\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

