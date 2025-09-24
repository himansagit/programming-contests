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

      vector<int> a(n+1);
      iota(a.begin(), a.end(), 0);
      int l = 1;
      while( l <= n){
            if( s[l-1] == '1')
                  l++;
            else{
                  int r = l+1;
                  while( r <= n and s[r-1] == '0'){
                        r++;
                  }
                  r--;
                  for( int j = l; j < r; j++) a[j] = j+1;
                  a[r] = l;
                  l = r+1;
            }
      }
      //debug(a);

      rep(i,n){
            if( s[i] == '0' and a[i+1] == i+1){
                  cout << "NO\n";
                  return;
            }
      }
      cout << "YES\n";
      rep(i,n) cout << a[i+1] << " \n"[i==n-1];
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

