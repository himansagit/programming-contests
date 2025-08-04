#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

bool find(i64 a, i64 b,const i64 x){
      if( b == x or a == x or b-a == x)
            return true;
      a = min( a, b-a);
      if( a == 0 or b < x )
            return false;
      if( x%a == b%a ){
            debug(a,b,x);
            return true;
      }
      return find(b%a,a,x);
      
}

void solve(int){
      i64 a,b,x;
      cin >> a >> b >> x;
      if( a > b )
            swap(a,b);
      cout << (find(a,b,x) ? "YES\n" : "NO\n");
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc = 1;
      cin>>tc;
      for(int i = 1; i <= tc; i++){
            solve(i);
      }
      //TIME
}

