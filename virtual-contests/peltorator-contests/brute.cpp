#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)
//SNIPS

void solve(){
      int n; cin >> n;
      vector<int> a(n);
      rep(i,n) cin >> a[i];
      int m;
      cin >> m;
      rep(i,m){
            int l, r;
            cin >> l >> r;
            int mx = -1;
            for( int j = l-1; j < r; j++){
                  mx = max(mx, a[j]);
            }
            for( int j = l-1; j < r; j++){
                  if( a[j]  == mx){
                        cout << j + 1 << "\n";
                        break;
                  }
            }
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

