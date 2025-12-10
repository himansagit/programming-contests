#include<bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve(){
      i64 n,k; cin >> n >> k;
      vector<i64> Q(n), R(n);
      for( int i = 0; i < n; i++) cin >> Q[i];
      for( int i = 0; i < n; i++) cin >> R[i];
      
      sort(Q.begin(), Q.end());
      sort(R.begin(), R.end());
      int l = 0, r = n-1;
      int ans = 0;
      while(r >= 0 and l < n){
            if( Q[r]*(R[l]+1LL) + R[l] <= k){
                  r--;
                  l++;
                  ans++;
            }else{
                  r--;
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

