#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

bool is_prime(i64 n){
      for( i64 i = 2; i*i <= n; i++){
            if( n%i == 0) return false;
      }
      return true;
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      // this problem usage Goldbach’s conjecture
      // every even number > 2 can be written 
      // as sum of two prime numbers;

      i64 n; cin >> n;
      i64 res = 0;
      if(n%2 == 0){
            if(n == 2) res = 1;
            else res = 2;
      }else{
            //check in n is already prime
            if( is_prime(n)) res = 1;
            else if( is_prime(n-2)) res = 2;
            else res = 3;
      }
      cout << res << '\n';
}

