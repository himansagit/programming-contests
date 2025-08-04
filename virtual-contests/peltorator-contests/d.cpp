#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int N = 2e5+10;
i64 tree[N];
int n;

i64 find(int i){
      i += n;
      i64 res = tree[i];
      while( i > 1){
            i /= 2;
            res += tree[i];
      }
      return res;
}

void update(int l, int r, i64 add){
      l += n;
      r += n;
      while( l <= r){
            if( l%2 == 1){
                  tree[l] += add;
                  l++;
            }
            if( r%2 == 0){
                  tree[r] += add;
                  r--;
            }
            l /= 2;
            r /= 2;
      }
}

void solve(){
      cin >> n;
      rep(i,n) cin >> tree[n+i];
    //  build(); for this just set alll internal nodes to 0
      rep(i,n) tree[i] = 0;
      int q; cin >> q;
      while(q--){
            char c; cin >> c;
            if( c == 'g'){
                  int i; cin >> i;
                  i--;
                  cout << find(i) << "\n";
            }else{
                  int l,r;
                  i64 add;
                  cin >> l >> r >> add;
                  l--; r--;
                  update(l,r,add);
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

