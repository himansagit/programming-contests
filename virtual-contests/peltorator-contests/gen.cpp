#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)


int32_t main(int argc, char* argv[])
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      mt19937_64 RNG( atoi(argv[1]));
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

