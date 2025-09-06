#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n;
      cin >> n;
      vector<int> a(n);
      rep(i,n) cin >> a[i];
      sort( a.begin(), a.end());
      rep(i,n-1){
            if( a[i] == a[i+1]){
                  cout << "Yes\n";
                  return;
            }
      }
      cout << "No\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

