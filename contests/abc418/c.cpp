#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      i64 n,q; cin >> n >> q;
      vector<i64> a(n+1), pre(n+1);
      rep(i,n){
            cin >> a[i];
      }
      sort( a.begin(), a.end());
      rep(i,n){
            pre[i+1] = pre[i] + a[i+1];
      }

      while(q--){
            i64 s; cin >> s;
            if( s > a[n] ){
                  cout << "-1\n";
            }else{
                  i64 itr = lower_bound( a.begin(), a.end(), s) - a.begin();
                  assert(itr >= 0 and itr <= n);
                  i64 x= pre[itr-1];
                  x += (n-itr+1)*(s-1);
                  cout << x +1 << "\n";
            }
      }
}

