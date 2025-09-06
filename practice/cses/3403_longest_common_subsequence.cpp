#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)


const int N = 1001;

using P = array<int,3>;
P dp[N][N];
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
//      memset(dp,0,sizeof(dp)); 

      int n,m; cin >> n >> m;
      vector<int> a(n+1),b(m+1);
      rep(i,n) cin >> a[i+1];
      rep(i,m) cin >> b[i+1];
      for( int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                  if( a[i] == b[j]){
                        dp[i][j] = {dp[i-1][j-1][0] + 1, i-1, j-1};
                  }
                  if( dp[i-1][j][0] >= dp[i][j][0]){
                        dp[i][j] = { dp[i-1][j][0], i-1,j};
                  }
                  if( dp[i][j-1][0] >= dp[i][j][0]){
                        dp[i][j] = { dp[i][j-1][0], i,j-1};
                  }
            }
      }
     // rep(i,n){
     //       rep(j,m){
     //             cout << "{" << dp[i+1][j+1][0] << ","<< dp[i+1][j+1][1] << ","<< dp[i+1][j+1][2] << "} ";
     //       }
     //       cout << "\n";
     // }
      int r = n, c = m;
      vector<int> res;
      while( r > 0 and c > 0){
            int nr = dp[r][c][1];
            int nc = dp[r][c][2];
            if( r-nr == 1 and c-nc == 1){
                  assert( a[r] == b[c]);
                  res.push_back(a[r]);
            }
            r = nr;
            c = nc;
      }
      reverse(res.begin(), res.end());
      cout << res.size() << '\n';
      for( int x:res){
            cout << x << " ";
      }
      cout << '\n';
}

