#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;

void solve(){
      int n, q; cin >> n >> q;
      string s; cin >> s;
      reverse(s.begin(), s.end());

      vector<vector<int>> dp(n+1, vector<int>(2));
      int sum = 0;
      for( int i = 0; i < n; i++){
            if( s[i] == 'V') sum += 5;
            else if( s[i] == 'X') sum += 10;
      }
      for( int i = 1; i < n; i++){
            if( s[i] == '?'){
                 dp[i][0] = max(dp[i-1][1] +1, dp[i-1][0]);
                 dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
            }else if( s[i] == 'I'){
                  dp[i][0] = max( dp[i-1][1] + 1, dp[i-1][0]);
                  dp[i][1] = 0;
            }else{
                  dp[i][1] = max(dp[i-1][0], dp[i-1][0]);
                  dp[i][0] = 0;
            }
      }
      int m = max(dp[n-1][0], dp[n-1][1]);
      //cout << m << '\n';
      int add = count(s.begin(), s.end(), '?');
      int o = count(s.begin(), s.end(), 'I');
      int f = count(s.begin(), s.end(), 'V');
      int t = count(s.begin(), s.end(), 'X');
      //add += one;
      //debug(add,m,sum);
      debug(o,f,t);
      while(q--){
            int a,b,c; cin >> a >> b >> c;
            int one = o + c;
            int five = f + b;
            int ten = t + a;
            one = min(one, n - t - f);
            five = min(five, n- one-t);
            ten = min(ten, n -one - five);
            int ans = one + 5*five + 10*ten;
            debug(one,five,ten,ans);
            int r = min(one,m);
            ans -= 2*(min(five+ten,min(one,m)));
            cout << ans << '\n';
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

