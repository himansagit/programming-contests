#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)
const int N = 2e5+10;
const i64 inf = 1e18;
void solve(){
     i64 n,y; cin >> n >> y;
     int x;
     vector<i64> a(N);
      rep(i,n){
            cin >> x;
            a[x]++;
      }
      vector<i64> pre = a;
      for( int i = 1; i < N; i++){
            pre[i] = pre[i-1] + a[i];
      }
      i64 ans = -inf;
      for( int i = 2; i < N; i++){
            i64 cur = 0;
            for( int j = 1; (j-1)*(i) < N; j++){
                  i64 c = pre[ min(j*i,N-1)] - pre[(j-1)*(i)];
                  cur += j*c - y*max(0LL, c - a[j]);
            }
            ans = max(ans, cur);
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

