#include<bits/stdc++.h>

using namespace std;

void solve(){
      int n,k,q;
      cin >> n >> k >> q;
      vector<int> a(n+1,-1);
      vector< pair<int,int>> x;
      vector<pair<int,pair<int,int>>> y;
      int c,l,r;
      while(q--){
            cin >> c >> l >> r;
            if( c == 1) x.push_back({l,r});
            else y.push_back({r-l+1,{l,r}});
      }
      for( auto [l,r]:x){
            for( int i = l; i <= r; i++) a[i] = k;
      }
      sort( y.begin(), y.end());
      vector<int> mark(n+1);
      for( int i = 0; i < y.size(); i++){
            int l = y[i].second.first;
            int r = y[i].second.second;
            for( int j = 0; j < k; j++) mark[j] = 0;
            for( int j = l; j <= r; j++){
                  if( a[j] >= 0){
                        mark[a[j]] = 1;
                  }
                  if( a[j] >= k) a[j] = k+1;
            }
            int put = 0;
            for( int idx = l; idx <= r; idx++){
                  if( a[idx] < 0){
                        while(put < k and mark[put] == 1) put++;
                        if(put < k){
                              a[idx] = put;
                              mark[put] = 1;
                        }else{
                              //a[idx] = k+1;
                              break;
                        }
                  }
            }
      }
      for( int i = 1; i <= n; i++) cout << max( a[i] ,0) << ' ';
      cout <<'\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

