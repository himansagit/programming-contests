#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int dsum(int x){
      int sum = 0;
      while( x){
            sum += x%10;
            x/=10;
      }
      return sum;
}
void getn(int n){
      int y = n, ans = 100, m = 1;
      for( int j = 1; j <= 10000000; j++){
            int x = n*j;
            int sum = dsum(x);
            if(sum < ans){
                  ans = sum;
                  y = x;
                  m = j;
            }
      }
      cout << n << " " << ans << " " << y << " " << m << "\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n; 
      cin >> n;
      getn(n);
}

// (2,5) -> 100000...
// (
