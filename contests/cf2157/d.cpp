#include<bits/stdc++.h>

using namespace std;
using i64 = long long;    

void solve(){
      i64 n,l,r; cin >> n >> l >> r;
      vector<i64> a(n);
      vector<i64> med;
      int less = 0, more = 0;
      for( int i = 0; i < n; i++){
            cin >> a[i];
            if( a[i] >= l and a[i] <= r) med.push_back(a[i]);
            else if( a[i] < l) less++;
            else more++;
      }

      sort( med.begin(), med.end());
      int t = med.size();
      if( t%2 == 1){
            l = r = med[t/2];
      }
      else{
            if( t > 0){
                  l = med[t/2-1];
                  r = med[t/2];
            }
      }
      i64 sum = 0;
      if(less <= more){
            for( int i = 0; i < n; i++){
                  sum += abs(a[i] - r);
            }
      }else{
            for( int i = 0; i <n; i++){
                  sum += abs(a[i] - l);
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

