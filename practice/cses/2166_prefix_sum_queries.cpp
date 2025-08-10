#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int N = 5e5;
int n;
i64 tree[N];

void build( vector<i64> &a){
      int sz = a.size();
      rep(i,sz){
            tree[sz+i] = a[i];
      }
      for( int i = sz-1; i > 0; i--0){
            tree[i] = max( tree[2*i], tree[2*i]);
      }
}

void update(int l, int r, i64 x){
      l += n;
      r += n;
      while( l <= r){
            if( l%2 == 1){
                  tree[l]
            }
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
     int q; cin >> n >> q;
     vector<i64> a(n),pre(n);
     i64 sum = 0;
     rep(i,n){
           cin >> a[i];
           sum += a[i];
           pre[i] = sum;
     }
     build(pre);
      while(q--){
            int t; cin >> t;
            if( t == 1){
                  int k, i64 u;
                  k--;
                  i64 d = u - a[k];
                  update(k,n-1,d);
            }else{

            }
      }
}

