#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;

void solve(){
      int n; cin >> n;
      vector<int> a(n);
      vector<vector<pair<int,int>>> b(n+1);
      for( int i = 0; i < n; i++){
            cin >> a[i];
            b[a[i]].push_back({i,0});
      }
      int m= 0, res = 0;
      for( int i = 1; i <= n ;i++){
            if( i > 2){
                  for( pair<int,int> &p:b[i-2]){
                        m = max(m, p.second);
                  }
            }
            int l = 0, r = 0, i1 = b[i-1].size()-1;
            r = m;// max. upto i-2
            for( int j = b[i].size()-1; j >= 0; j--){
                 while( i1 >= 0 and b[i-1][i1].first > b[i][j].first){
                  l = max( l, b[i-1][i1].second);
                  i1--;
                 }
                 b[i][j].second = max( b[i][j].second, l+1); // max in i-1 to the right
                 b[i][j].second = max( b[i][j].second, r+1); // max in i to the right
                                                           
                 r = max( r, b[i][j].second); 
                 res = max( res, r);
            }
      }
      cout << n - res << '\n';

}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

