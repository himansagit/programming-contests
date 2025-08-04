#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int N = 4e5+10;
int n;
i64 tree[N];

void update(int i,int x){
      i += n;
      tree[i] = x;
      while( i > 1 ){
            i /= 2;
            tree[i] = tree[2*i] + tree[2*i+1];
      }
}

i64 find_sum(int l,int r){
      i64 sum = 0;
      l += n;
      r += n;
      while( l <= r){
            if( l%2 == 1){
                  sum += tree[l];
                  l++;
            }
            if( r%2 == 0){
                  sum += tree[r];
                  r--;
            }
            l /= 2;
            r /= 2;
      }
      return sum;
}

void solve(){
      int q;
      cin >> n >> q;
      while(q--){
            char c; cin >> c;
            if( c == 'A'){
                  int i,x;
                  cin >> i >> x;
                  i--;
                  update(i,x);
            }else{
                  int l,r;
                  cin >> l >> r;
                 cout <<  find_sum(l-1,r-1) << "\n";
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

