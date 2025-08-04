#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

//RNG
const i64 inf = 1e18;
void solve(int){
      i64 n;
      cin >> n;
      vector<i64> a(n),b(n);
      rep(i,n) cin >> a[i] >> b[i];
      i64 sum = a[0];
      for( int i = 1; i < n; i++){
            sum += max(0LL,a[i] - b[i-1]);
      }
      i64 res = sum;
      for( int i = 1; i < n; i++){
            sum += min(b[i-1],a[i]);
            sum -= min(a[i-1],b[(i-2+n)%n]);
            res = min( res ,sum);
      }
      cout << res << "\n";

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

