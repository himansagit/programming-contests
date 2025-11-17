#include<bits/stdc++.h>

using namespace std;

int qry( int l, int r){
      cout <<"? " <<  l << " " << r << endl;
      int x; cin >> x;
      return x;
}
void solve(){
      int n,q; cin >> n >> q;
      vector<int> left(n+1), right(n+1,n+1);
      for( int i = 0; i < q; i++){
            int l, r; 
            cin >> l >> r;
            left[l] = max(left[l],r);
            right[r] = min(right[r],l);
      }
      int m = n/2;
      int b = qry(1,m);
      int ans = 0;
      if( b > 0){
            int r = 0;
            for( int l = 1; l <= m; l++){
                  if( left[l] > r){
                        int x = qry(l,r);
                        ans = max( ans, x);
                        r = left[l];
                  }
            }
      }else{
            int l = n+1;
            for( int r = n; r >= m+1; r--){
                  if( right[r] < l){
                        int x = qry(l,r);
                        ans = max(ans, x);
                        l = right[r];
                  }
            }
      }
      cout << "! " << ans << endl;
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

