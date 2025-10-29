#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
const i64 inf = 1e18;
void solve(){
      i64 n, s, x; cin >> n >> s >> x;
      vector<i64> a(n);
      for( int i = 0; i < n; i++){
            cin >> a[i];
      }
      a.push_back(inf);
      vector<i64> v;
      i64 ans = 0;
      for( int i = 0; i <= n; i++){
            if( a[i] <= x){
                  v.push_back(a[i]);
            }else{
                  map<i64,i64> m1;
                  map< pair< i64, i64>, i64 > m2;
                  i64 sum = 0, c = 0;
                  m1[0] = 1;
                  m2[{0,0}] = 1;
                  for( i64 &t:v){
                        sum += t;
                        if( t == x) c++;
                        ans += m1[sum - s] - m2[{sum - s, c}];
                        m1[sum]++;
                        m2[{sum, c}]++;
                  }
                  v.clear();
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

