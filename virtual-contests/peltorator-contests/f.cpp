#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using i64 = long long;
#define rep(i,b) for( i64 i = 0; i < (b); ++i)

void compress( vector<i64> &a){
      i64 n = a.size();
      vector<i64> d = a;
      sort( d.begin(), d.end() );
      d.resize( unique( d.begin(), d.end()) - d.begin());
      for( i64 i = 0; i < n; i++){
            a[i] = lower_bound( d.begin(), d.end(), a[i]) - d.begin();
      }
}

const i64 mod = 1e9+7;
const i64 N = 2e5+10;
int n;
using PI = pair<i64,int>;

using P = array<i64,2>;

array<P,N> tree;

P find(int l,int r){
      l += n;
      r += n;
      P f = {0,1};
      while(l <= r){
            if( l%2 == 1){
                  if( f[0] == tree[l][0])
                        f[1] = (tree[l][1]+f[1])%mod;
                  else if( f[0] < tree[l][0])
                        f = tree[l];
                  l++;
            }
            if( r%2 == 0){
                  if( f[0] == tree[r][0])
                        f[1] = (f[1] + tree[r][1])%mod;
                  else if( f[0] < tree[r][0])
                        f = tree[r];
                  r--;
            }

            l /= 2;
            r /= 2;
      }
      return f;
}
void update(i64 i, P f){
      i += n;
      f[0]++;
      //assert(tree[i][0] <= f[0]);
      if( tree[i][0] == f[0])
            tree[i][1] = (tree[i][1] +  f[1])%mod;
      else
            tree[i] = f;
      while(i > 1){
            i /= 2;
            int l = 2*i, r = 2*i+1;
            if( tree[l][0] == tree[r][0])
                  tree[i] = { tree[l][0], (tree[l][1] + tree[r][1])%mod };
            else
                  tree[i] = max( tree[l], tree[r]);
                        
      }
}

void solve(){
      cin >> n;
      vector<i64> a(n);
      rep(i,n) cin >> a[i];
      rep(i,2*n+1) tree[i] = {0,0};
      compress(a);
      n = *max_element( a.begin(), a.end())+1;
      for( i64 x:a){
           P f = find(0,x-1);
           debug(x,f,tree[x+n]);
           update(x,f);
           debug(x,f,tree[x+n]);
      }
      debug(tree[0], tree[1], tree[2],tree[3]);
      P res = find(0,n-1);
      debug(res);
      cout << res[1]  << "\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t = 1;
      //cin >> t;
      for( int i = 1;i <= t; i++){
            solve();
      }
      //TIME
}
