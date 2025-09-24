#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
struct DSU{
     vector<int> a;
     void init(int n) { a = vector<int>(n,-1); }
     int get(int x){
           if( a[x] < 0) return x;
           else return a[x] = get(a[x]);
     }
     bool same(int x, int y) {return get(x) == get(y);}
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
      int n,a,b     
      
}

