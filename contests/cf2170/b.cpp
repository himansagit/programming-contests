#include<bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve(){
      int n; cin >> n;
      vector<i64> A(n);
      for( int i = 0; i < n; i++) cin >> A[i];
      i64 sum = accumulate(A.begin(), A.end(), 0LL);
      int z = count(A.begin(), A.end(), 0);
      for( int l = n - z; l > 0; l--){
            if( sum - l >= n-1){
                  cout << l << '\n';
                  break;
            }
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

