#include<bits/stdc++.h>

using namespace std;

void solve(){
      int n, k, q; cin >> n >> k >> q;
      vector<int> a(n,-1);

      for( int i = 0; i < k; i++) a[i] = i;
      for( int i = k; i < n; i++) a[i] = a[i-k];

      vector<pair<int,int>> x,y;
      while(q--){
            int c,l,r; cin >> c >> l >> r;
            if( c == 1) x.push_back({l,r});
            else y.push_back({l,r});
      }
      for( auto [l,r]:x){
            for( int i = l-1; i < r; i++) a[i] = k;
      }
      for( auto [l,r]:y){
            for( int i = l-1; i < r; i++){
                  if( a[i] == k) a[i] = k+1;
            }
      }

      for( int i = 0; i < n; i++) cout << a[i] << ' ';
      cout << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

