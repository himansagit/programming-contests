#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n;
      cin >> n;
      vector<int> a(n);
      rep(i,n) cin >> a[i];
      int last = 0, cur = 1, level = 0;
      for(int i = 2; i < n; i++){
            if( a[i] > a[i-1])
                  cur++;
            else{
                  if( last == 0 ){
                        // new level
                        last = cur;
                        level++;
                        cur = 0;
                  }
                  cur++;
                  last--;
            }
      }
      cout << level+1 << "\n"; 
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
      //TIME
}

