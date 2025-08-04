#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,k;
      cin >> n >> k;
      string s;
      cin >> s;

      int ans = 0;
      auto check = [&](int score)->int{
            int cnt = 0;
            int l = 0, r = 0;
            rep(i,n){
                  if( s[i] == '0')
                        l++;
                  else r++;
                  r = max(l,r);
                  if( r == score){
                        cnt++;
                        l = 0, r= 0;
                  }
            }
           debug(score,cnt); 
            return cnt;
      };
      for(int z = n; z > 0; z/=2){
            debug(z);
            while( ans + z <= n and check(ans +z) >= k){
                  ans += z;
            }
      }
      cout << ans << "\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
      //TIME
}

