#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,k; cin >> n >> k;
      map<int,int> m;
      rep(i,n){
            int x;
            cin >> x;
            int d = min( x%k, k-x%k);
            m[d]++;
      }
      rep(i,n){
            int x;
            cin >> x;
            int d = min( x%k, k-x%k);
            m[d]--;
      }
      for(auto itr:m){
            if( itr.second != 0){
                  cout << "NO\n";
                  return;
            }
      }
      cout << "YES\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

