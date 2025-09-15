#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      i64 n; cin >> n;
      vector<i64> odd;
      i64 x;
      i64 ans = 0;
      rep(i,n){
            cin >> x;
            if(x%2 == 0){
                  ans += x;
            }else{
                  odd.push_back(x);
            }
      }
      if( odd.size() == 0){
            ans = 0;
      }else{
            sort( odd.rbegin(), odd.rend());
            ans += accumulate(odd.begin(), odd.begin() + (odd.size()+1)/2, 0LL);
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

