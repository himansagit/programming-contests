#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      //vector<int> a(3);
      vector<int> cnt(32);
      rep(i,3){
            int x; cin >> x;
            rep(j,30){
                  int y = (1 << j);
                  //debug(x,y);
                  if( (y&x) > 0) cnt[j]++;
            }
      }
      //debug(cnt);
      rep(i,31){
            if( cnt[i] == 2){
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

