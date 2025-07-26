#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

//RNG

void solve(int){
      i64 n;
      cin >> n;
      vector<i64> a(n),b(n),c(n),d(n);
      rep(i,n) cin >> c[i];
      rep(i,n) cin >> a[i];
      rep(i,n) cin >> b[i];
      i64 ans = 0;
      for(int i = 1; i <n; i++){
            i64 x = a[i];
            i64 y = b[i];
            if( x > y ) swap(x,y);
            if( x == y)
                  d[i] = c[i] + 1;
            else
                  d[i] = max(y-x+1, d[i-1] - (y - x -1 )) + c[i];
            ans = max(ans, d[i]);
      }
      cout << ans << "\n";

}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc = 1;
      cin>>tc;
      for(int i = 1; i <= tc; i++){
            solve(i);
      }
      //TIME
}

