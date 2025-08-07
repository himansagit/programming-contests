
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
      // start code here
      int n = RNG()%10 +1;
      n = 1;
      cout << n << "\n";
      rep(i,n){
            cout << RNG()%n+1 << " ";
      }
      cout << "\n";
      int m = n;
      cout << m <<"\n";
      rep(i,m){
            int l = RNG()%n+1;
            int w = n-l;
            int r = n;
            if( w > 0)  r = l + RNG()%w; 
            cout << l << " " << r << "\n";
      }
}
