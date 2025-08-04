#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int N = 2e5+10;
int tree[N];
int n;

void build(){
      for(int i = n-1; i > 0; i--){
            tree[i] = gcd(tree[2*i], tree[2*i+1]);
      }
}
void update(int i,int x){
      i += n;
      tree[i] = x;
      while( i > 1){
            i /= 2;
            tree[i] = gcd(tree[2*i], tree[2*i+1]);
      }
}
int find(int l, int r){
      l += n;
      r += n;
      int g = 0;
      while( l <= r){
            if(l%2 == 1){
                  g = gcd(g,tree[l]);
                  l++;
            }
            if( r%2 == 0){
                  g = gcd(g,tree[r]);
                  r--;
            }
            l /= 2;
            r /= 2;
      }
      return g;
}
void solve(){
      cin >> n;
      rep(i,n) cin >> tree[i+n];
      build();
      int q; cin >> q;
      while(q--){
            char c; cin >> c;
            if( c == 's'){
                  int l, r; cin >> l >> r;
                  l--, r--;
                 cout <<  find(l,r) << " ";
            }else{
                  int i,x; cin >> i >> x;
                  i--;
                  update(i,x);
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

