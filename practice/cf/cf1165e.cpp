#include<bits/stdc++.h>

using namespace std;
using i64 = long long;

#define rep(i,b) for( int i = 0; i < (b); ++i)
const i64 mod = 998244353;

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      i64 n; cin >> n;
      vector<i64> a(n),b(n);
      rep(i,n) cin >> a[i];
      rep(i,n) cin >> b[i];
      for(i64 i = 0; i < n; i++){
            a[i] *= (i+1)*(n-i);
      }
      sort( a.begin(), a.end());
      sort( b.rbegin(), b.rend());
      i64 sum = 0;
      rep(i,n){
            a[i] %= mod;
            sum += a[i]*b[i];
            sum %= mod;
      }
      cout << sum << '\n';
}

