#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      i64 n ,m;
      cin >> n >> m;
      vector<i64> a(n), pre(n);
      rep(i,n) cin >> a[i];
      vector<i64> d(n-1);
      sort( a.begin(), a.end());
      rep(i,n-1) d[i] = a[i+1]-a[i];
      vector<bool> mark(m+1);
      mark[0] = true;
      i64 sum = 0;
      rep(i,n-1){
            sum += d[i];
            if(mark[ sum%m ] == true){
                  cout << "0";
                  return;
            }
            mark[ sum%m ] = true;
            pre[i+1] = sum;
      }
      assert(n< m+1);
      i64 res = 1;
      for(int i = 1; i < n; i++){
            for( int j = i-1; j >= 0; j--){
                  res = (res * (pre[i] - pre[j]))%m;
            }
      }
      cout << res ;

}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

