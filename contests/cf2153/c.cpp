#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
using i64 = long long;
void solve(){
     int n; cin >> n;
     vector<i64> a(n);
     rep(i,n){
           cin >> a[i];
     }
     sort( a.begin(), a.end());
     vector<i64> s;
     vector< pair<i64,i64>> d;
     int cnt = 1;
     for(int i = 1; i < n; i++){

           if( a[i]  == a[i-1]) cnt++;
           else{
                 d.push_back({a[i-1],cnt/2});
                 if( cnt%2 == 1) s.push_back(a[i-1]);
                 cnt = 1;
           }
     }
     d.push_back({a[n-1],cnt/2});
     if( cnt%2 == 1) s.push_back(a[n-1]);

      i64 ans = 0;
      cnt = 0;
      for( auto &p:d){
            cnt += p.second;
            ans += p.first * p.second *2LL;
      }
      sort( s.rbegin(), s.rend());
      if( cnt == 0){
            ans = 0;
      }else if( cnt == 1){
      // special case when only one equal pair
            int t = s.size();

                  s.push_back(0);
                  //debug(ans, s);
                  bool ok = false;
                  rep(i,t){
                        if( ans + s[i+1] > s[i]){
                              //debug(ans,s[i],s[i+1]);
                              ans += s[i] + s[i+1];
                              ok = true;
                              break;
                        }
                  }
                  if( !ok) ans = 0;
      }else{
            if( s.size() > 0) ans += s[0];
            if( s.size() > 1) ans += s[1];
      }
      cout << ans << '\n';

}


int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

