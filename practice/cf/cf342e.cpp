#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;

//const int N = 1e5+5;
const int inf = 1e8;
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n,q; cin >> n >> q;
      vector<vector<int>> G(n); 
      for( int i = 0; i < n-1; i++){
            int u, v; cin >> u >> v;
            u--, v--;
            G[u].push_back(v);
            G[v].push_back(u);
      }
      vector<int> parent(n), cparent(n,-1), sz(n), visited(n), depth(n), red_dist(n, inf);
      auto set_parent = [&]( this auto &&set_parent, int u, int p,int d)->void{
            depth[u] = d;
            for(int v:G[u]){
                  if( v != p){
                        parent[v] = u;
                        set_parent(v,u,d+1);
                  }
            }
      };
      set_parent(0,-1,0);
      //debug(parent);
      auto getsz = [&](this auto &&getsz, int u, int p)->void{
            sz[u] = 1;
            for( int v:G[u]){
                  if( v != p and !visited[v]){
                        getsz(v,u);
                        sz[u] += sz[v];
                  }
            }
      };
      auto centroid = [&](this auto &&centroid, int u, int p, int s)->int{
            for( int v:G[u]){
                  if( v != p and !visited[v]){
                        if( sz[v] > s/2){
                             return centroid(v,u,s);
                        }
                  }
            }
            return u;
      };
      // set all centroid parent to themselves
      //iota(cparent.begin(), cparent.end(),0);
      auto decompose = [&](this auto &&decompose, int u)->int{
            getsz(u,-1);
            int c = centroid(u,-1,sz[u]);
            //debug(u,c);
            visited[c] = true;
          //  for( int v:G[c]){
          //        if( !visited[v]){
          //              cparent[v] = c;
          //        }
          //  }
            for( int v:G[c]){
                  if( !visited[v]){
                       int t =  decompose(v);
                       cparent[t] = c;
                  }
            }
            return c;
      };
      //debug(cparent);
      decompose(0);
      //debug(cparent);
      int L = 20;
      parent[0] = 0;
      vector<vector<int>> up(n, vector<int>(L));
      //vector<vector<int>> cup(n, vector<int>(L));
      // initialize up for binary lifting
      for( int i = 0; i < n; i++) up[i][0] = parent[i];
      for( int k = 1; k < L; k++){
            for( int i = 0; i < n; i++){
                  assert( up[i][k-1] >= 0 );
                  assert( up[i][k-1] < n );
                  up[i][k] = up[up[i][k-1]][k-1];
            }
      }
      auto getKth = [&](int u, int k)->int{
            for( int i = L-1; i >= 0; i--){
                  if( (k&(1<<i))){
                        u = up[u][i];
                  }
            }
            //debug(u);
            return u;
      };
      auto lca = [&](int a, int b)->int{
            if( depth[a] < depth[b]) swap(a,b);     
            int d = depth[a] - depth[b];
            a = getKth(a,d);
            if( a == b) return a;
            for( int i = L-1; i >= 0; i--){
                  if( up[a][i] != up[b][i]){
                        a = up[a][i];
                        b = up[b][i];
                  }
            }

            return parent[a];
      };
      auto get_dist = [&](int a, int b)->int{
            //debug(a,b,lca(a,b));
            return depth[a] + depth[b] - 2*depth[ lca(a,b) ];
      };
      auto set_red = [&](int u)->void{
            int t = u;
            red_dist[u] = 0;
            while( t != -1){
                  red_dist[t] = min( red_dist[t], get_dist(t,u));
                  t = cparent[t];
            }
      };
      auto get_min_dist = [&](int u)->int{
           int t = u;
           int ans = inf;
           while( t != -1){
                 debug(t);
                  ans = min(ans, red_dist[t] + get_dist(t,u));
                  t = cparent[t];
           }
           return ans;
      };

      set_red(0);
      debug(cparent); 
      while(q--){
            int t, u; cin >> t >> u;
            if( t == 1){
                  set_red(u-1);
            }else{
                  cout << get_min_dist(u-1) << '\n';
            }
      }
}

