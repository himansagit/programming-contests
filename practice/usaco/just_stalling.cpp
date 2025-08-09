#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)


int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int n; cin >> n;
      vector<i64> a(n),b(n);
      rep(i,n) cin >> a[i];
      rep(i,n) cin >> b[i];
      sort( a.rbegin(), a.rend());
      sort( b.rbegin(), b.rend());
       
      i64 l = 0, r = 0 ;
      i64 res = 1;
      while( l < n){
            while( r < n and b[r] >= a[l]) r++;
            res *= (r-l);
            l++;
      }
      cout << res ;
}

