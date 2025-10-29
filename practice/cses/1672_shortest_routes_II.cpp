#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
using i64 = long long;
const int N = 501;
const i64 inf = 1e18;
i64 dist[N][N];
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int n,m,q; cin >> n >>m >> q;

      for(int i = 1; i <= n; i++){
            for(int j =1 ; j <= n; j++){
                  if( i == j) dist[i][j] = 0;
                  else dist[i][j] = inf;
            }
      }
      rep(i,m){
            i64 a,b,c; cin >> a >> b >> c;
            dist[a][b] = min(dist[a][b],c);
            dist[b][a] = min(dist[b][a],c);
      }
      for( int i = 1; i <= n; i++){
            for( int j = 1; j <= n; j++){
                  for(int k = 1; k <= n; k++){
                        dist[j][k] = min( dist[j][k], dist[j][i] + dist[i][k]);
                  }
            }
      }
      while( q--){
            int a,b; cin >> a >> b;
            if( dist[a][b] == inf) cout << -1;
            else cout << dist[a][b];
            cout << '\n';
      }
}

