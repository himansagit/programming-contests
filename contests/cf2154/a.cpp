#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,k; cin >> n >> k;
      string s; cin >> s;
      int c = 0;
      for( int i = 0; i < n; i++){
            if( s[i] == '0') continue;
            bool ok = false;

            for( int j = 1; j < k; j++){
                  if( i-j < 0) break;
                  if( s[i-j] == '1') ok = true;
            }
            if( !ok){
                  c++;
            }
      }
      cout << c <<'\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

