#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int sum = 0, total = 0;
      for( int i = 1; i <= 100; i++){
            sum += i*i;
            total += i;
      }
      cout << total*total - sum << '\n';
}

