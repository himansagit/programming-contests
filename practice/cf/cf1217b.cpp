#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,x; cin >> n >> x;
      int diff = -1e9;
      int del = 0;
      rep(i,n){
            int d,h; cin >> d >> h;
            diff = max(diff, d-h);
            del = max(del,d);
      }
      int rem = x - del;
      if( rem > 0 and diff <= 0){
            cout << "-1\n";
      }else{
            int res = 0;
            if( rem > 0) res += (rem+diff-1)/diff;
            cout << res +1 <<'\n';  
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

