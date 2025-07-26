#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define all(x) (x).begin(),(x).end()
#define rep(i, a, b) for( int i = a; i < (b); ++i)

//RNG

void solve(int){
      i64 x1,y1,x2,y2;
      cin >> x1 >> y1 >> x2 >> y2;
      i64 res = abs(x1-x2)*abs(y1-y2) +1;
      cout << res << "\n";
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

