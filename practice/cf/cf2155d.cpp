#include<bits/stdc++.h>

using namespace std;

void solve(){
      int n; cin >> n ;
      vector< pair<int,int>> v;
      for( int l = 2; l <= 2*n ; l *= 2){
            for( int i = 1; i <= n; i += l){
                  for( int j = i; j < i + l/2; j++){
                        for( int k = i + l/2; k <= min(n, i + l-1); k++){
                              v.push_back({j,k});
                        }
                  }
            }
      }
      int x = 0;
      int i = 0;
      while( x == 0){
            cout << v[i].first << " " << v[i].second << endl;
            cin >> x;
            if( x == 1) break;
            assert( x != -1);
            i++;
      }
}


int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

