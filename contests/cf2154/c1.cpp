#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int N = 2e5+10;
void solve(){
      int n; cin >> n;
      vector<int> a(n), b(n);
      rep(i,n) cin >> a[i];
      rep(i,n) cin >> b[i];
      vector<int> c(N);
      int ans = 2;
      rep(i,n){
            int x = a[i];
            for( int j = 2; j*j <= x; j++){
                  if( x%j == 0){
                        int k = x/j;
                        c[j]++;
                        if( k > j) c[k]++;
                        if( c[j] > 1 or c[k] > 1){
                              ans = 0;
                        }
                  }
            }
      }
      for( int i = 0; i <= 12; i++){
            cout << c[i] << " ";
      }
      cout << endl;
      rep(i,n){
             int x = a[i]+1;
            for( int j = 2; j*j <= x; j++){
                  if( x%j == 0){
                        int k = x/j;
                        if( c[j] > 0 or c[k] > 0){
                              ans = min(ans, 1);
                        }
                  }
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

