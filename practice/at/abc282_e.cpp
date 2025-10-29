#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
using i64 = long long;
i64 m;
i64 po(i64 a, i64 b){
      if( b == 0) return 1LL;
     i64 c = 1;
     while( b > 1){
           if(b%2 == 1){
                  c = (c*a)%m;
                  b--;
           }
           a = (a*a)%m;
           b /= 2;
     }
     return (a*c)%m;
}
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
      
      i64 n; cin >>  n >> m;
      vector<i64> a(n);
      vector< pair<i64,pair<int,int>>> e;
      rep(i,n) cin >> a[i];
      rep(i,n){
            for( int j = i+1; j < n; j++){
                  i64 x = (po(a[i],a[j]) + po(a[j],a[i]))%m;
                  e.push_back({x,{i,j}});
            }
      }
      sort( e.rbegin(), e.rend());
      DSU g; g.init(n);
      i64 ans = 0;
      for( auto [d,u]:e){
            if( g.join(u.first, u.second) == 1){
                  ans += d;
            }
      }
      cout << ans << '\n';
}

