#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n; cin >> n;
      string s; cin >> s;
      i64 odd = 0, even = 1;
      i64 cnt = 0;
      i64 ans = 0;
      rep(i,n){
            if( s[i] == '0') cnt++;
            if( cnt&1){
                  ans += odd;
                  odd++;
            }else{
                  ans += even;
                  even++;
            }
      }
      cout << ans << "\n";
}

