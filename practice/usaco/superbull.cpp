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
      #ifndef LOCAL
            freopen("superbull.in","r",stdin);
            freopen("superbull.out","w",stdout);
      #endif
      i64 n; cin >> n;
      vector<i64> a(n);
      rep(i,n){
            cin >> a[i];
      }
      vector< pair< i64, pair<int,int>>> e;
      rep(i,n){
            rep(j,n){
                  e.push_back({a[i]^a[j],{i,j}});
            }
      }
      DSU g; g.init(n);
      sort( e.rbegin(), e.rend());
      i64 ans = 0;
      for( auto [d,u]:e){
            if( g.join(u.first,u.second) == 1){
                  ans += d;
            }
      }
      cout << ans << '\n';
}

