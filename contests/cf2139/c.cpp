#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif


using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      i64  k,x; cin >> k >> x;
      i64 sum = (1LL << (k+1));
      i64 a = x, b = sum - x;
      vector<int> ans;
      while(a != b){
            if( a > b){
                  ans.push_back(2);
                  a -= b;
                  b += b;
            }else{
                  ans.push_back(1);
                  b -= a;
                  a += a;
            }
      }
      reverse(ans.begin(), ans.end());
      cout << ans.size() << '\n';
      for(int &x:ans) cout << x << " ";
      cout << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

