#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

//RNG

void solve(){
      int n, l, r;
      cin >> n >>l >> r;
      string s;
      cin >> s;
      bool ok = true;
      for(int i = l-1; i < r; i++){
            if( s[i] != 'o') ok = false;
      }
      cout << (ok ? "Yes" : "No");
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

