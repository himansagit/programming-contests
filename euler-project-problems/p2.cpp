#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
     
      i64 ans = 0;
      i64 f1 = 1, f2 = 2;
      while( f2 <= 4000000){
            if( f2%2 == 0) ans += f2;
            f1 += f2;
            swap(f1,f2);
      }
      cout << ans << '\n';
}

