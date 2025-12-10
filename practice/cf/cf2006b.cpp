#include<bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve(){
      i64 n,w; cin >> n >> w;
      vector<int> p(n+1);
      for(int i = 2; i <= n; i++){
            int x; cin >> x;
            p[i] =x;
      }
      i64 sum = 0;
      for( int i = 1; i < n; i++){
            i64 x, y; cin >> x >> y;
            sum += y;
            cout << 2*sum + (w-sum)*(n-i) << ' ';
      }
      cout << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

