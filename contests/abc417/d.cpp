#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int N = 10005;
int dp[N][2005];
int pre[N];

void solve(){
      int n; cin >> n;
      debug(n);
      vector<int> p(n), a(n), b(n);
      rep(i,n) cin >> p[i] >> a[i] >> b[i];
      memset(dp,0,sizeof(dp));
      memset(pre,0,sizeof(pre));
      int x = 0;
      rep(i,n){
            x += b[i];
            pre[i] = x;
      }
      for(int i = n; i < N; i++) pre[i] = x;
      rep(i,n+1){
            rep(j,1001){
                  dp[i][j] = j;
            }
      }
      
     // for( int j = 0; j<= 1000; j++){
     //       if( j < p[i]){
     //             dp[n-1][j] = max(0, j-b[n-1]);
     //       }else{
     //             dp[n-1][j] = j + a[n-1];
     //       }
     // }

      for( int i = n-1; i >= 0; i--){
            for(int  j = 0; j <= 1000; j++){
                  if( j > p[i]){
                        dp[i][j] = dp[ i+1][ max(0, j- b[i])]; 
                  }else{
                        dp[i][j] = dp[i+1][ j + a[i] ];
                  }
            }
      }
      rep(i,n){
            rep(j,20){
                  cerr << dp[i][j] << " ";
            }
            cout << "\n";
      }

      int q; cin >> q;
      while(q--){
            int x;
            cin >> x;
            if( x - pre[n-1] > 1000){
                  cout << x - pre[n-1] << "\n";
                  continue;
            }
            int itr = lower_bound(pre,pre+n, x - 1000) - pre;
            assert(itr >= 0);
            if( itr >= n){
                  cout << x -pre[n-1] << "\n";
                  continue;
            }
            if( x - pre[itr] > 1000){
                  debug(x,itr,a[itr], x - 1000);
            }
            assert(x - pre[itr] <= 1000);
             if( x - pre[itr] <= 500){
                   if( itr == 0){
                         cout << dp[0][x] << "\n";
                   }else{
                   cout << dp[itr][x - pre[itr-1]] << "\n";

                   }
             }else{
             cout << dp[itr+1][x - pre[itr]] << "\n";
             }
      }

}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

