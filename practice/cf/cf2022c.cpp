#include<bits/stdc++.h>

using namespace std;

void solve(){
      int n; cin >> n;
      vector<string> s(2);
      cin >> s[0] >> s[1];
      vector<vector<int>> a( 2, vector<int> (n));
      for( int i = 0; i < n; i++){
            if( s[0][i] == 'A') a[0][i] = 1;
            if( s[1][i] == 'A') a[1][i] = 1;
      }
      vector<vector<int>> dp(7, vector<int> (n+1));
      
      auto cnt = [&](int i, int t)->int{
            if( t <= 3){
                  int c = a[0][i] + a[0][i-1] + a[1][i] + a[1][i-1];
                  if( t == 0) c -= a[1][i];
                  if( t == 1) c -= a[1][i-1];
                  if( t == 2) c -= a[0][i];
                  if( t == 3) c -= a[0][i-1];
                  if( c > 1) return 1;
                  else return 0;
            }else if( t == 6){
                  int c1 = 0, c2 = 0;
                  for( int j = 0; j < 3; j++){
                        c1 += a[0][i-j];
                        c2 += a[1][i-j];
                  }
                  int c = 0;
                  if( c1 > 1) c++;
                  if( c2 > 1) c++;
                  return c;
            }else if( t == 4){
                  int c1 = 0, c2 = 0;
                  for( int j = 0; j < 3; j++){
                        c1 += a[0][i-j];
                        c2 += a[1][i-j-1];
                  }
                  int c = 0;
                  if( c1 > 1) c++;
                  if( c2 > 1) c++;
                  return c;

            }else{
                  int c1 = 0, c2 = 0;
                  for( int j = 0; j < 3; j++){
                        c1 += a[0][i-j-1];
                        c2 += a[1][i-j];
                  }
                  int c = 0;
                  if( c1 > 1) c++;
                  if( c2 > 1) c++;
                  return c;
            }
      };

      for( int i = 2; i <= n; i++){
            dp[0][i] = max( { dp[1][i-2], dp[3][i-2], dp[6][i-2]}) + cnt(i-1,0);
            dp[2][i] = max( { dp[1][i-2], dp[3][i-2], dp[6][i-2]}) + cnt(i-1,2);

            dp[1][i] = max( dp[2][i-1], dp[5][i-1]) + cnt(i-1,1);
            dp[3][i] = max( dp[0][i-1], dp[4][i-1]) + cnt(i-1,3);

            if( i < 3) continue;
            dp[6][i] = max( { dp[1][i-3], dp[3][i-3], dp[6][i-3]}) + cnt(i-1,6);
            if( i < 4) continue;
            dp[4][i] = max( dp[0][i-3], dp[4][i-3]) + cnt(i-1,4);
            dp[5][i] = max( dp[2][i-3], dp[5][i-3]) + cnt(i-1,5);
      }
      int ans = max({ dp[1][n], dp[3][n], dp[6][n]});
      cout << ans << '\n';
//      for( int i = 1; i <= n; i++){
//            for( int j = 0; j < 7; j++){
//                  cout << dp[j][i] << " ";
//            }
//            cout << '\n';
//      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

      //auto cnt = [&](int j, int t)->int{
      //      if( t <= 3){
      //            int c = 0;
      //            if( s[0][j] == 'A') c++;
      //            if( s[0][j-1] == 'A') c++;
      //            if( s[1][j] == 'A') c++;
      //            if( s[1][j-1] == 'A') c++;
      //            
      //            if( t == 0 and s[1][j] == 'A') c--;
      //            else if( t == 1 and s[1][j-1] == 'A') c--;
      //            else if( t == 2 and s[0][j] == 'A') c--;
      //            else if( t == 3 and s[0][j-1] == 'A') c--;
      //            return c/2;
      //      }else if( t == 4){
      //            int c = 0, c1 = 0, c2 = 0;
      //            for( int i = 0; i < 3; i++){
      //                  if( s[0][j-i] == 'A') c1++;
      //            }
      //            for( int i = 0; i < 3; i++){
      //                  if( s[1][j-i-1] == 'A') c1++;
      //            }
      //            if( c1 > 1) c++;
      //            if( c2 > 1) c++;
      //            return c;
      //      }else if( t == 5){
      //            int c = 0, c1 = 0, c2 = 0;
      //            for( int i = 0; i < 3; i++){
      //                  if( s[0][j-i-1] == 'A') c1++;
      //            }
      //            for( int i = 0; i < 3; i++){
      //                  if( s[1][j-i] == 'A') c1++;
      //            }
      //            if( c1 > 1) c++;
      //            if( c2 > 1) c++;
      //            return c;
      //      }else{
      //            int c = 0, c1 = 0, c2 = 0;
      //            for( int i = 0; i < 3; i++){
      //                  if( s[0][j-i] == 'A') c1++;
      //            }
      //            for( int i = 0; i < 3; i++){
      //                  if( s[1][j-i] == 'A') c1++;
      //            }
      //            if( c1 > 1) c++;
      //            if( c2 > 1) c++;
      //            return c;
      //      }
      //};
