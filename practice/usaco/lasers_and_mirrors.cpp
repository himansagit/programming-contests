#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int inf = 1e9;
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
#ifndef LOCAL
      freopen("lasers.in","r",stdin);
      freopen("lasers.out","w",stdout);
#endif
      int n; cin >> n;
      map<int,vector<int>> mx,my;
      map<pair<int,int>, int> dist;
      int sx,sy,dx,dy; cin >> sx >> sy >> dx >>dy;
      rep(i,n){
           int x,y; cin >> x >>y;
            mx[x].push_back(y);
            my[y].push_back(x);
      }
            mx[sx].push_back(sy);
            my[sy].push_back(sx);

            mx[dx].push_back(dy);
            my[dy].push_back(dx);
      dist[{sx,dy}] = 0;
      queue<pair<int,int>> q;
      q.push({sx,sy});
      while( !q.empty()){
            pair<int,int> node = q.front();
            //debug(node);
            q.pop();
            int d = dist[node] +1;
            for(int y:mx[node.first]){
                  if( y == node.second) continue;
                 q.push({node.first,y});
                 dist[{node.first,y}] = d;
            }
            for(int x:my[node.second]){
                  if( x == node.first) continue;
                 q.push({x,node.second});
                 dist[{x,node.second}] = d;
            }
            mx[node.first].clear();
            my[node.second].clear();
      }
      cout << dist[{dx,dy}] -1 << '\n';
}


