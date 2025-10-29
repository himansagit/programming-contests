#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int N = 2001;
int dist[N][N];
struct DSU{
     vector<int> a;
     void init(int n) { a = vector<int>(n,-1); }
     int get(int x){
           if( a[x] < 0) return x;
           else return a[x] = get(a[x]);
     }
     bool same(int x, int y) {return get(x) == get(y);}
     int size(int x){ return -a[get(x)]; };
     int join(int x, int y){
           x = get(x), y = get(y); if( x == y) return 0;
           if( a[x] > a[y]) swap(x,y);
           a[x] += a[y]; a[y] = x; return 1;
     }
};
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n; cin >> n;
      vector< pair<int,pair<int,int>>> e;
      rep(i,n){
            rep(j,n){
                  cin >> dist[i][j]; 
                        if( i != j)
                        e.push_back({dist[i][j],{i,j}});
            }
      }
      DSU g; g.init(n+1);
      vector<vector<pair<int,int>>> G(n+1);
      sort( e.begin(), e.end());
      bool ok = true;
      for( auto [d,u]:e){
           if( g.join( u.first, u.second ) == 1){
                 if( d == 0){
                      cout << "NO\n"; return 0; 
                 }
                  G[u.first].push_back({u.second,d});
                  G[u.second].push_back({u.first,d});
           }
      }

      auto dfs = [&](auto self, int u,int p, int s,int d)->void{
            debug(u,s,dist[s][u]);
            if( dist[s][u] != d or dist[u][s] != d){
                  ok = false;
            }
            for(auto [v,w]:G[u]){
                  if( v == p) continue;
                  self(self,v,u,s,d+w);
            }
      };
      for( int i = 0; i < n; i++){
           dfs(dfs,i,-1,i,0); 
      }
      if(ok) cout << "YES\n";
      else cout << "NO\n";
}

