#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,k; cin >> n >> k;
      string s; cin >> s;
      vector<int> a(n);
      for(int i = 0; i < n; i++){
            if( s[i] == 'G') a[i] = 1;
            else if( s[i] == 'B') a[i] = 2;
      }
      vector<vector<int>> pre(3, vector<int> (n+3));
      rep(i,3){
            for( int j = 1; j <= n; j++){
                  pre[i][j] = pre[i][j-1]; 
                  if( a[j-1] != ((i + j)%3)) pre[i][j]++;
            }
      }
      int ans = n;
      for( int i = k; i <= n; i++){
            ans = min( ans, pre[0][i] - pre[0][i-k]);
            ans = min( ans, pre[1][i] - pre[1][i-k]);
            ans = min( ans, pre[2][i] - pre[2][i-k]);
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

