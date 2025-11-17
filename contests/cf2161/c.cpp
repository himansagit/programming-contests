#include<bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve(){
      i64 n, x;
      cin >> n >> x;
      vector<i64> a(n);
      for( int i = 0; i < n; i++){
            cin >> a[i];
      }
      sort( a.begin(), a.end());
      vector<i64> ans;
      i64 sum = 0, s = 0, l = 0, r = n-1;
      while( l <= r){
            if( s + a[r] - x >= 0){
                  sum += a[r];
                  ans.push_back(a[r]);
                  s += a[r] - x;
                  r--;
            }else{
                 s += a[l]; 
                 ans.push_back(a[l]);
                 l++;
            }
      }
      cout << sum << '\n';
      for( i64 &x:ans) cout << x << " ";
      cout << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

