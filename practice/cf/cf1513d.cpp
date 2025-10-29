#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

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
void solve(){
      int n,p; cin >> n >> p;
      vector<int> a(n);
      vector<pair<int,int>> o(n);
      rep(i,n){
            cin >> a[i];
            o[i] = {a[i],i};
      }
      sort( o.begin(), o.end());
      DSU g; g.init(n);    
      i64 ans = 0;
      for( auto [x,i]:o){
            if( x >= p) break;
            int y = x;
            for( int j = i-1; j >= 0; j--){
                  y = gcd(y,a[j]);
                  if( y < x ) break;
                  if(g.join(i,j) == 1) ans += (long long)x;
                  else break;
            }
            y = x;
            for(int j = i+1; j < n; j++){
                  y = gcd(y,a[j]);
                  if( y < x ) break;
                  if(g.join(i,j) == 1) ans += (long long)x;
                  else break;
            }
      }
      for( int i = 0; i < n-1; i++){
            if( g.join(i,i+1) == 1) ans += (long long)p;
      }
      cout << ans << '\n';
}
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t; cin >> t;
      while( t--) solve();
      
}

