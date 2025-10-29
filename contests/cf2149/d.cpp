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
      string s; cin >> s;
      vector<i64> a(n);
      rep(i,n){
            if(s[i] == 'a') a[i] = 0;
            else a[i] = 1;
      }
      auto find = [&]()->i64{
            vector<i64> pre(n),suf(n);
            i64 z = 0, sum = 0;
            for( int i = 0; i < n; i++){
                  if( a[i] == 0){
                        z++;
                        pre[i] = sum;
                  }
                  else{
                        sum += z;
                        pre[i] = sum;
                  }
            }
            z = 0, sum = 0;
            for( int i = n-1; i >= 0; i--){
                  if( a[i] == 0){
                        z++;
                        suf[i] = sum;
                  }
                  else{
                        sum += z;
                        suf[i] = sum;
                  }
            }
            //debug(pre,suf);
            i64 ans = min(suf[0],pre[n-1]);
            for(int i = 0; i < n-1; i++){
                  ans = min(ans, pre[i] + suf[i+1]);
            }
            return ans;
      };
      i64 ans1 = find();
      // compliment a
      rep(i,n){
            a[i] = 1LL - a[i];
      }
      i64 ans2 = find();
      cout << min( ans1,ans2) << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

