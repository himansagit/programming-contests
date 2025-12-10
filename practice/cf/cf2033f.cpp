#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
const int mod = 1e9+7;

void solve(){
      i64 n,k; cin >> n >> k;
      int a = 1, b = 1;
      if( k == 1){
            cout << n%mod << '\n';
      }else{
            int c = 2;
            for( ; c < 10000000 and b != 0; c++){
                  a = (a+b)%k;
                  swap(a,b);
            }
            i64 ans = n%mod;
            ans = (ans*c) % mod;
            cout << ans << '\n';
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

