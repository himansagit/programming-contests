#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      i64 a,b,q;
      cin >> a >> b >> q;
      i64 c = a*b;
      vector<i64> pre(c+1);
      for(int i = 1 ; i < c; i++){
            if( (i%a)%b != (i%b)%a )
                  pre[i] = 1;
      }
      for(int i = 1; i <= c; i++){
            pre[i] += pre[i-1];
      }
      while(q--){
            i64 l, r;
            cin >> l >> r;
            l--;
            cout << ( pre[c]*(r/c) + pre[r%c] - pre[c]*(l/c) - pre[l%c] ) << " ";
      }
      cout << "\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
      //TIME
}

