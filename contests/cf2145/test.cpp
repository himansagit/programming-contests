#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int sqrt(int n){
      int l = 1, r= n;
      while( l < r){
            int m = (l+r+1)/2;
            if( m*m <= n){
                  l = m;
            }else{
                  r = m-1;
            }
      }
      return l;
}
int sqrt2(int n){
      int l = 1, r= n;
      while( l < r){
            int m = (l+r)/2;
            if( m*m < n){
                  l = m+1;
            }else{
                  r = m;
            }
      }
      return l;
}
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
     for( int i = 1; i <= 100; i++){
           cout << i << " " << sqrt(i) << " " << sqrt2(i) << '\n';
     }
}

