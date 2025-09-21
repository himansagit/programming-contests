#include<bits/stdc++.h>

using i64 = long long;
using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const i64 mod = 998244353;
void solve(){
      int n;
      cin >> n;
      vector<int> a(n),b(n);
      rep(i,n) cin >> a[i];
      rep(i,n) cin >> b[i];
      rep(i,n){
            if( a[i] < b[i])
                  swap(a[i],b[i]);
      }
      int cnt = 0;
      int m = max(a[0],b[0]);
      for(int i = 1; i < n; i++){
            if( min( a[i], b[i] ) >= m){
                  cnt++;
            }
            m = max(m, max(a[i],b[i]));
      }
      i64 ans = 1;
      rep(i,cnt+1){
            ans = (ans*2LL)%mod;
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

