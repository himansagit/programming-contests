#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using i64 = long long;
#define all(x) (x).begin(),(x).end()
#define sz(x)	(int)(x).size() 
#define pb push_back
#define rep(i, a, b) for( int i = a; i < (b); ++i)

//RNG

void solve(int){
      i64 n,k;
      cin >> n >> k;
      vector<i64> a(n);
      rep(i,0,n) cin >> a[i];
      sort(all(a));
      i64 sum = accumulate(all(a),0LL);
      i64 l = a[0], r = a[1];
      while(k--){
            i64 m = (l+r+1)/2;
            sum += m;
            debug(m,sum);            
            if( r == m)
                  break;
            r = m;

      }
      if(k > 0)
            sum = sum + k*r;
      cout << sum <<"\n";

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

