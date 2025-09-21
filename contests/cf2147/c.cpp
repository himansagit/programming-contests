#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n; cin >> n;
      string s; cin >> s;
      if( n == 1){
            cout << "YES\n";
            return;
      }
      if( s[0] == '0') s = '0' + s;
      else s = '1' + s;
      if( s[n] == '0') s += '0';
      else s += '1';
      string t;
      int l = 1;
      while( l < n){
            if( s[l] == '1' and s[l-1] == '1'){
                  int r = l+1;
                  while( r <= n and s[r] != s[r-1]) r++; 
                  if( s[r] == '1'){
                        int w = r-l-2;
                        if( w > 0 and (w/2)%2 == 0){
                              cout << "NO\n";
                              return;
                        }
                  }
                  l = r;
            }else{
                  l++;
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

