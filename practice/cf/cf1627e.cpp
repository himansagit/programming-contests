#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
using i64 = long long;
const i64 inf = 1e18;
using L = array<int,4>;

void solve(){
      int n,m,k; cin >> n >> m >> k;
      vector<i64> x(n+1);
      rep(i,n) cin >> x[i+1];
      vector<L> lad(k);
      vector<vector<int>> flr(n+1);
      //map<pair<int,int>,vector<pair<pair<int,int>,i64>>> G;
      //map<pair<int,int>, vector<pair<pair<int,int>,i64>>> G;
      vector<vector<L>> G(n+1);
      rep(i,k){
            int a,b,c,d,h;
            cin >> a >> b >> c >> d >> h;
            //G[{a,b}].push_back({{c,d},-h});
            G[a].push_back({b,c,d,h});
            flr[a].push_back(b);
            flr[c].push_back(d);
      }
      flr[1].push_back(1);
      flr[n].push_back(m);
     // map<pair<int,int>,i64> dist;
     vector<vector<i64>> dist(n+1);
     for( int i = 1; i <= n; i++){
           dist[i].resize( flr[i].size(), inf);
     }

     dist[1][0] = 0; 
      for( int i = 1; i <= n; i++){
            sort( flr[i].begin(), flr[i].end());
            sort( G[i].begin(), G[i].end());
      }
      for( int i = 1; i <= n; i++){
            //sort(flr[i].begin(), flr[i].end());
            int t = flr[i].size();
            for( int j = 1; j < t; j++){
                  //dist[{i,flr[i][j]}] = min( dist[{i,flr[i][j]}], dist[{i,flr[i][j-1]}] + 1LL*x[i]*(flr[i][j] - flr[i][j-1]));
                  dist[i][j] = min( dist[i][j], dist[i][j-1] + 1LL*x[i]*(flr[i][j] - flr[i][j-1]));
            }
            for( int j = t-2; j >= 0; j--){
                  //dist[{i,flr[i][j]}] = min( dist[{i,flr[i][j]}], dist[{i,flr[i][j+1]}] + 1LL*x[i]*(flr[i][j+1] - flr[i][j]));
                  dist[i][j] = min( dist[i][j], dist[i][j+1] + x[i]*(flr[i][j+1]-flr[i][j]));
            }
            //for( int j = 0; j <t; j++){
            //      //if( G.find({i,flr[i][j]}) == G.end()) continue;
            //      //const auto &stairs = G[{i,flr[i][j]}];

            //      for(const auto to:stairs){

            //            int x = lower_bound(flr[i].begin(), flr[i].end(), flr[i][j]) - flr[i].begin();
            //            int y = lower_bound(flr[to.first.first].begin(), flr[to.first.first].end(), to.first.second) - flr[to.first.first].begin();
            //            //int y = lower_bound(flr[i].begin(), flr[i].end(), to.first.second) - flor[i].begin();
            //            dist[to.first.first][y] = min( dist[to.first.first][y], dist[i][x] + to.second);
            //      }
            //}
            for( auto [b,c,d,h]:G[i]){
                  int x = lower_bound(flr[i].begin(), flr[i].end(), b) - flr[i].begin();
                  int  y = lower_bound(flr[c].begin(), flr[c].end(), d) - flr[c].begin();
                  dist[c][y] = min( dist[c][y], dist[i][x] - h);
            }
      }
      i64 ans = dist[n].back();
      if( ans >= inf/2){
            cout << "NO ESCAPE\n";
      }else{
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

