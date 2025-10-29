#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
       int n; cin >>  n;
       vector<int> a(n);
       int c= 0;
       rep(i,n){
             cin >> a[i];
             if( a[i]%2 == 0) c++;
       }
       if( c > 0 and c < n) sort(a.begin(), a.end());
       rep(i,n) cout << a[i] << " " ;
       cout << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

