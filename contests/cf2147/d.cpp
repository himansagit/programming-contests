#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      i64 n; cin >> n;
      vector<i64> a(n);
      rep(i,n) cin >> a[i];
      sort( a.begin(), a.end());
      i64 cnt = 1;
      i64 sum = 0;
      vector<i64> extra;
      for( int i = 1; i < n; i++){
            if( a[i] == a[i-1]) cnt++;
            else{
                  if( a[i-1]%2 == 0){
                        extra.push_back(cnt);
                        extra.push_back(cnt);
                        sum += (cnt*(a[i-1]-2));
                  }else{
                        extra.push_back(cnt);
                        sum += (cnt*(a[i-1]-1));
                  }
                  cnt = 1;
            }
      }
      debug(extra);
      if( a[n-1]%2 == 0){
            extra.push_back(cnt);
            extra.push_back(cnt);
            sum += (cnt*(a[n-1]-2));
      }else{
            extra.push_back(cnt);
            sum += (cnt*(a[n-1]-1));
      }
      sort( extra.rbegin(), extra.rend());
      debug(extra);
      i64 alice = sum/2, bob = sum/2;
      for(int i = 0; i < extra.size(); i++){
            if( i%2 == 0) alice += extra[i];
            else bob += extra[i];
      }
      cout << alice << " " << bob << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

