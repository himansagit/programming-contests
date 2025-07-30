#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

bool fill( vector<i64> &h, vector<pair<i64,i64>> &pre, int k){
      int n  = h.size();
      pre[0] = {h[0],h[0]};
      for( int i = 1; i < n; i++){
            int l1 = pre[i-1].first-k+1;
            int r1 = pre[i-1].second+k-1;
            int l2 = h[i];
            int r2 = h[i] + k-1;
            if( r1 < l2 or r2 < l1) return false;
            pre[i] = { max(l1,l2), min(r1,r2)};
      }
      return true;
}

void solve(){
      i64 n,k;
      cin >> n >> k;
      vector<i64> h(n);
      rep(i,n) cin >> h[i];
      
      vector<pair<i64,i64>> pre(n),suf(n);
      bool ok1 = fill(h,pre,k);

      reverse( h.begin(), h.end() );
      bool ok2 = fill(h,suf,k);
      reverse( suf.begin(), suf.end());
      bool ok = false;
      if( ok1 and ok2){
            ok = true;
            rep(i,n){
                  if( pre[i].second < suf[i].first or pre[i].first > suf[i].second ){
                        ok = false;
                        break;
                  }
            }
      }

      cout << (ok ? "YES" : "NO") << "\n";
        
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
      //TIME
}

