#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      i64 p = 600851475143;
      vector<i64> prime;
      for(i64 i = 2; i*i <= p; i++){
            if( p%i == 0){
                  prime.push_back(i);
                  while( p%i == 0) p /= i;
            }
      }
      for(i64 x:prime) cout << x << '\n';
      cout << p << '\n';
}

