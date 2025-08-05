#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)
mt19937_64 RNG(1);

void solve(){
      int n = RNG()%10 + 1;
      int m = RNG()%10 + 1;
      cout << n << " " << m << "\n"; 
      rep(i,n){
            cout << RNG()%100 + 1 << " ";
      }
      cout << "\n";
      while(m--){
            int i = RNG()%n+1;
            int x = RNG()%150;
            cout << 1 << " " << i << " " << x <<"\n";
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

