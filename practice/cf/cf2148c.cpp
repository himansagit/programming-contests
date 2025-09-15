#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n, m; cin >> n >> m;
      int score = m;
      int state = 0, time = 0;
      rep(i,n){
            int a,b; cin >> a >> b;
            if( b != state and (a-time)%2 == 0) score--;
            else if( b == state and (a-time)%2 == 1) score--;
            state = b;
            time = a;
      }
      cout << score << '\n';

}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

