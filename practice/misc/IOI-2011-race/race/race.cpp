#include "race.h"
using i64  = long long;
#include<bits/stdc++.h>
using namespace std;

int best_path(int n, int k, int H[][2], int L[])
{
      const int inf = 1e8;
      vector<vector<pair<int,int>>> G(n);
      for( int i = 0; i < n; i++){
            G[H[i][0]].push_back({H[i][1],L[i]});
            G[H[i][1]].push_back({H[i][0],L[i]});
      }
      vector<vector<int>> CG(n);
      vector<int> sz(n);
      vector<bool> visited(n);
      auto getsz = [&](auto getsz, int u, int p)->void{
            sz[u] = 1;
            for( auto [v,w]:G[u]){
                  if( v != p and !visited[v]){
                        getsz(getsz,v,u);
                        sz[u] += sz[v];
                  }
            }
      };

      auto centroid = [&](auto centroid, int u, int p, int S)->int{
            for(auto [v,w]: G[u]){
                  if( v != p and !visited[v]){
                        if( sz[v] > S/2)
                              return centroid(centroid,v,u,S);
                  }
            }
            return u;
      };
      //vector<int> K(k+1, inf);
     // vector<int> K_tmp(k+1, inf);
     map<i64,int> K;

      //auto iinf = [&](this auto && iinf, int u, int p)-void{
      //      K[u] = inf;
      //      //K_tmp = inf;
      //      for( auto [v,w]:G[u]){
      //            if( v != p and !visited[v]){
      //                  iinf(v,u);
      //            }
      //      }
      //};

     // auto iinf_temp = [&](this auto && iinf_temp, int u, int p)-void{
     //       K_tmp = inf;
     //       for( auto [v,w]:G[u]){
     //             if( v != p and !visited[v]){
     //                   iinf_temp(v,u);
     //             }
     //       }
     // };
       
      int ans = inf;

      auto find = [&](auto find, int u,int p, int d, i64 l)->void{
            if( l > k) return; // already pass the limit
            //ans = min(ans,K[k-l]+d);
            if( K.find(k-l) != K.end()){
                  ans = min( ans, K[k-l] + d);
            }
            //K_temp[l] = min(K_temp[l], d);
            for( auto [v,w]: G[u]){
                  if( v != p and !visited[v]){
                        find(find,v,u,d+1,l+w);
                  }
            }
      };
      auto optimize = [&](auto optimize, int u,int p, int d, i64 l)->void{
            if( l > k) return; // already pass the limit
            if( K.find(l) == K.end()) K[l] = d;
            else K[l] = min(K[l],d);
            for( auto [v,w]: G[u]){
                  if( v != p and !visited[v]){
                        optimize(optimize,v,u,d+1,l+w);
                  }
            }
      };

      auto decompose = [&](auto decompose, int u)->void{
            getsz(getsz,u,-1);
            int c = centroid(centroid,u,-1,sz[u]);
            visited[c] = true;
            // do the processing
            //iinf(u,-1);
            K.clear();
            K[0] = 0;
            for( auto [v,w]: G[c]){
                  if( !visited[v]){
                        // this is one component of current centroid
                        // initialise all its children to inf
                        find(find,v,c,1,w);      
                        optimize(optimize,v,c,1,w);
                        //int cent = decompose(v);
                  }
            }
            for( auto [v,w]:G[c]){
                  if( !visited[v]){
                        decompose(decompose,v);
                  }
            }
      };
      decompose(decompose,0);
      if(ans >= inf) return -1;
      return ans;
}
/*
int main(){

      const int N = 2e5+5;
      int high[N][2];
      int w[N];
      int n,k; cin >> n >> k;
      for( int i = 0; i < n-1; i++){
            cin >> high[i][0] >> high[i][1] >> w[i];
      }
      int ans = best_path(n,k,high,w);
      cout << ans << '\n';
      return 0;
}
*/


