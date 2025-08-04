#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      i64 n,m;
      cin >> n >> m;
      vector<i64> a(n);
      rep(i,n) cin >> a[i];
      sort( a.begin(), a.end());
      i64 g = 0;
      rep(i,n-1){
            g = gcd(g, a[i+1] - a[i]);
      }
      rep(i,m){
            i64 b;
            cin >> b;
            cout << gcd(g,a[0]+b) << " ";
      }

}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

