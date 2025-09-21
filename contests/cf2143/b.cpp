#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,k; cin >> n >> k;
      vector<i64> a(n), b(k);
      rep(i,n) cin >> a[i];
      rep(i,k) cin >> b[i];
      sort( a.rbegin(), a.rend());
      sort( b.begin(), b.end());
      i64 sum = accumulate(a.begin(),a.end(), 0LL);
      i64 itr = 0;
      for(i64 &x:b){
            if( itr + x <= n){
                  itr += x;
                  sum -= a[itr-1];
            }else{
                  break;
            }
      }
      cout << sum << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

