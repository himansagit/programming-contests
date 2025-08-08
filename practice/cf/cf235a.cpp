#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      i64 n;
      cin >> n;
      i64 res = 1;
      if( n <= 2){
            res = n;
      }else if( n == 3){
            res = 6;
      }else if( n%2 == 1){
            res = n*(n-1)*(n-2);
      }else if( n%6 == 0){
            res = (n-1)*(n-2)*(n-3);
      }else{
            res = n*(n-1)*(n-3);
      }
      cout << res;
}

