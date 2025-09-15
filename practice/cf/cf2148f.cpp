#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif


using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n; cin >> n;
      vector<vector<int>> a(n);
      vector<pair<int,int>> idx(n);
      rep(i,n){
            int k; cin >> k;
            a[i].resize(k);
            idx[i] = {k,i};
            rep(j,k) cin >> a[i][j];
      }
      sort( idx.begin(), idx.end());
      //vector<int> ans = a[idx[0].second];
      int w = 0; 
      for(int i = 1; i < n; i++){
            int r = idx[i].second;
            int l = idx[i-1].second;
            if( a[l].size() < a[r].size()) w = a[l].size();
            if( a[l] < a[r]){

                  rep(k,w) a[r][k] = a[l][k];
            }
            if( a[l] < a[r]){
                  for( int k = w; k < a[l].size(); k++){
                        a[r][k] = a[l][k];
                  }
            }
      }
      int l = idx[n-1].second;
      for( int &x: a[l]) cout << x << " ";
      cout << '\n';
       
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

