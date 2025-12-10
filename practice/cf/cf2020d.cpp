#include<bits/stdc++.h>

using namespace std;
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
      int n,m; cin >> n >> m;
      DSU D;
      D.init(n);
      vector<vector<pair<int,int>>> v(11);
      for( int i = 0; i < m; i++){
            int a,d,k; cin >> a >> d >> k;
            v[d].push_back({a,k});
      }
      for( int d = 1; d <= 10; d++){
            sort( v[d].begin(), v[d].end());
            vector<int> s(11);
            for(  auto [a,k]:v[d]){
                  int r = a + d*k;
                  if( r <= s[a%d]) continue;
                  for( int j = max(a, s[a%d]); j <= r; j += d){
                        D.join(a-1,j-1);
                  }
                  s[a%d] = r;
            }
      }
      int c = 0;
      for( int i = 0; i < n; i++){
            if( D.get(i) == i) c++;
      }
      cout << c << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

