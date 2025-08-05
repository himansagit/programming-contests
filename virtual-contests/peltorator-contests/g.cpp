#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)
//SNIPS

const int N = 1e6+10;
int tree[N];
int n;

int find(int l, int r){
      l += n-1;
      r += n-1;
      int res = 0;
      while( l <= r){
            if( l%2 == 1){
                  res += tree[l];
                  l++;
            }
            if( r%2 == 0){
                  res += tree[r];
                  r--;
            }
            l /= 2;
            r /= 2;
      }
      return res;
}
int find_kth(int k){
      int r = 1;
      if( tree[r] < k) return N; // not enough 0s;
      while( r < n){
            if( tree[2*r] < k){
                  k -= tree[2*r];
                  r = 2*r + 1;
            }else{
                  r = 2*r;
            }
      }
      assert( k == 1);
      return r+1-n;
}

void update(int i,int x){
      i += n;
      tree[i] = x;
      while( i > 1){
            i/=2;
            tree[i] = tree[2*i] + tree[2*i+1];
      }
}
void solve(){
     memset(tree,0,sizeof(tree)); 
      int t; cin >> t;
      n = 1;
      while( n < t) n*= 2;
      int x;
      rep(i,t){
            cin >> x;
            x = ( x == 0 ? 1 : 0);
            tree[i+n] = x;
      }
      for( int i = n-1; i > 0; i--){
            tree[i] = tree[2*i] + tree[2*i+1];
      }
      int q; cin >> q;
      while( q--){
            char c; cin >> c;
            if( c == 's'){
                  int l,r,k;
                  cin >> l >> r >> k;
                  k += find(1,l-1);
                  int f = find_kth(k); 
                  if( f > r) f = -1;
                  cout << f << " ";
            }else{
                  int i,x;
                  cin >> i >>  x;
                  x = ( x == 0 ? 1 : 0);
                  update(i-1,x);
            }
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

