#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,p,k;
      cin >> n >> p >> k;
      vector<int> a(n);
      rep(i,n) cin >> a[i];
      sort( a.begin(), a.end());
      vector<int> cost(n);
      rep(i,k) cost[i] = a[i];
      for( int i = k; i < n; i++){
            cost[i] = cost[i-k] + a[i];
      }

      rep(i,n){
            if( cost[i] > p){
                  cout << i << '\n';
                  return;
            }
      }
      cout << n << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

