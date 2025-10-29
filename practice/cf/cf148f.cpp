#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
using P = array<int,3>;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n; cin >> n;
      vector<pair<int,int>> ord(n);
      vector<vector<int>> a(n);
      rep(i,n){
            int k; cin >> k;
            ord[i] = {k,i};
           a[i].resize(k); 
            rep(j,k) cin >> a[i][j];
      }
      sort(ord.rbegin(), ord.rend());
      int l = ord[0].first-1;
      int r = 0;
      vector<P> v;
      vector<int> cur(l+2);
      while( l >= 0){
            for( int i = 0; i < v.size(); i++){
                  v[i][0] = a[v[i][2]][l];
            }
            while( r < n and ord[r].first > l){
                  int i = ord[r].second;
                  v.push_back({a[i][l], -1, i});
                  r++;
            }
            //debug(v);
            sort( v.begin(), v.end());
            cur[l] = v[0][2];
            //debug(v);
            //debug(l);
            for( int i = 0; i < v.size(); i++){
                  v[i][1] = i;
            }
            l--;
      }
      //cout << v.size() << endl;
     assert( v.size() == n);
     r = 0;
     while( r < ord[0].first){
           int i = cur[r];
           while( r < a[i].size()){
                 cout << a[i][r] << " ";
                 r++;
           }
     }
     cout << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

