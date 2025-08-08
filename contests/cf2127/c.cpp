#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
     int n,k;
     cin >> n >> k;
     vector<i64> a(n),b(n);
     rep(i,n) cin >> a[i];
     rep(i,n) cin >> b[i];
     i64 res = 0;
     vector<pair<i64,i64>> v(n);
     rep(i,n){
           res += abs(a[i] - b[i]); 
           v[i] = { min(a[i],b[i]) , max(a[i],b[i])};
     }
      sort( v.begin(), v.end());
      i64 add = 1e16;
      rep(i,n-1){
            if( v[i].second >= v[i+1].first){
                  add = 0;
                  break;
            }
            add = min( add, 2*(v[i+1].first - v[i].second));
      }
      cout << res + add << "\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

