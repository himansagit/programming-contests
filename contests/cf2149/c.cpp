#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,k; cin >> n >> k;
      vector<int> a(n+1);
      rep(i,n){
            int x; cin >> x;
            a[x]++;
      }
      int x = 0;
      rep(i,k){
            if(a[i] == 0) x++;
      }
      cout << max(x, a[k]) << '\n';

}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

