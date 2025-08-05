#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)
//SNIPS

void solve(){
      int n,m;
      cin >> n >> m;
      vector<int> a(n);
      rep(i,n) cin >> a[i];
      while(m--){
            int t,i,x; cin >> t >> i >> x;
            if( t == 1){
                  bool ok = false;
                  for( int j = i-1; j < n; j++){
                        if( a[j] >= x){
                              cout << j+1 << "\n";
                              ok = true;
                              break;
                        }
                  }
                  if( !ok) cout << "-1\n";
            }else{
                  a[i-1] = x;
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

