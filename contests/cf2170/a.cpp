#include<bits/stdc++.h>

using namespace std;

int val(int i, int j, int n){
      if( min(i,j) < 0 or max(i,j) >=n) return 0;
      return i*n+j+1;
}
int get(int i, int j, int n){
      int sum = 0;
      sum += val(i-1,j,n);
      sum += val(i+1,j,n);
      sum += val(i,j-1,n);
      sum += val(i,j+1,n);
      sum += val(i,j,n);
      return sum;
}
void solve(){
      int n; cin >> n;
      int ans = 0;
      for( int i = 0; i < n; i++){
            for( int j = 0; j < n; j++){
                  ans = max(ans, get(i,j,n));
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

