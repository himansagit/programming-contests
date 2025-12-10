#include<bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve(){
      i64 n,l,r; cin >> n >> l >> r;
      vector<i64> a(n);
      for( int i = 0; i < n; i++){
            cin >> a[i];
      }
      sort( a.begin(), a.end());
      i64 m = -1;
      if(n%2 == 1){
            if( a[n/2] >= l and a[n/2] <= r) m = a[n/2];
            else if( a[n/2] < l) m = l;
            else m = r;
      }else{
            i64 x = a[n/2-1];
            i64 y = a[n/2];
            if( y < l) m = l;
            else if( x > r) m = r;
            else{
                  if( x >= l and x <= r) m = x;
                  else m = y;
            }
      }

      assert( m != -1);
      i64 sum = 0;
      for( int i = 0; i < n;i ++){
            sum += abs(a[i] - m);
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

