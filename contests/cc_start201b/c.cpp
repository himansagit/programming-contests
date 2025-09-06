#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n;
      cin >> n;
      string s;
      cin >> s;
      vector<int> a(n+1);
      rep(i,n) a[i+1] = s[i] - '0';
      rep(i,n) a[i+1] = a[i+1] + a[i];
      int r = 1, c = 1, ans = 0;
      bool f = 1;
      while( r <= n and c <= n ){
            assert( c >= r);
            assert( r <= n);
            assert( c <= n);
            //debug(r,c);
            ans += a[c] - a[r-1];
            if(f){
                  f = 0;
                  c++;
            }else{
                  f  = 1;
                  r++;
            }
      }
      cout << ans << '\n';
}


int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

