#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,a,b;
      cin >> n >> a >> b;
      bool ok = false;
      if( b >= a){
            if( (n-b)%2 == 0) ok = true;
      }else{
            if( (n-a)%2 == 0 and (a-b)%2 == 0) ok = true;
      }
      if( ok) cout << "Yes\n";
      else cout << "No\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

