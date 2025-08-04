#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n, m;
      cin >> n >> m;
      vector<int> a(n), b(m);
      rep(i,n) cin >> a[i];
      rep(i,m) cin >> b[i];
      int ans = 0;
      while(true){
            bool ok = true;
            rep(i,n){
                  bool f = false;
                  rep(j,m){
                        if( (ans | ( a[i] & b[j])) == ans ){
                                    f = true;
                                    break;
                                    }
                  }
                  if(!f){
                        ok = false;
                        break;
                  }
            }
            if( ok )
                  break;
            ans++;
      }
      cout << ans ;
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

