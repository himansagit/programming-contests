#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
using i64 = long long;
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
      
      int n,m; cin >> n >> m;
      vector<pair< i64, pair<int,int>>> road(m);
      rep(i,m){
            cin >> road[i].second.first >> road[i].second.second >> road[i].first;
      }
      sort( road.begin(), road.end());
      DSU g; g.init(n+1);
      i64 cost = 0;
      for( auto [c,u]:road){
            if( g.join(u.first,u.second) == 1) cost += c;
      }
      if( g.size(1) == n){
            cout << cost << '\n';
      }else{
            cout << "IMPOSSIBLE\n";
      }
}

