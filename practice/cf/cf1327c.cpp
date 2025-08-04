#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

using P2 = array<int,2>;
void solve(){
      int n,m,k;
      cin >> n >> m >> k;
      vector<P2> s(k),f(k);
      rep(i,k) cin >> s[i][0] >> s[i][1];
      rep(i,k) cin >> f[i][0] >> f[i][1];

      string ans ;
      rep(i,m-1) ans += "L";
      rep(i,n) ans += "U";
      rep(i,n){
            rep(j,m-1){
                  if( i&1) ans += "L";
                  else ans += "R";
            }
            ans += "D";
      }
      cout << ans.size() << "\n";
      cout << ans ;

}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

