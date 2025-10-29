#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n; cin >> n;
      string s; cin >> s;
      cout << count(s.begin(), s.end(), '0') << '\n';
      rep(i,n){
            if( s[i] == '0') cout << i +1 << ' ';
      }
      cout << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

