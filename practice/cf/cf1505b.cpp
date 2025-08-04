#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int a;
      cin >> a;
      while( a/10 > 0){
            int b = 0;
            while(a){
                  b += a%10;
                  a/=10;
            }
            a = b;
      }
      cout << a;
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

