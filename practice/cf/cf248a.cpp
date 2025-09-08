#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n; cin >> n;
      vector<i64> a(n);
      rep(i,n) cin >> a[i];
      sort( a.begin(), a.end());
      i64 sum = accumulate(a.begin(), a.end(), 0LL);
      cout << max( a[n-1], (sum+n-2)/(n-1)) << '\n';
}

