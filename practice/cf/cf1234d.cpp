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

int n;
using A = array<int,26>;
const int N =  4e5+10;
A tree[N];

A sum(const A& a,const A& b){
     A c;
     rep(i,26){
           c[i] = a[i] + b[i];
     }
     return c;
}

void update(int i,char c){
      int j = c - 'a';
      i += n-1;
      rep(k,26) tree[i][k] = 0;
      tree[i][j] = 1;
      while( i > 1){
            i /= 2;
            tree[i] = sum(tree[2*i], tree[2*i+1]);
      }
}
int cntd(A a, A b){
      int cnt =0;
      rep(i,26){
            if( b[i]-a[i] > 0) cnt++;
      }
      return cnt;
}
A find(int l, int r){
      l += n-1;
      r += n-1;
      A res;
      rep(i,26) res[i] = 0;
      while( l <= r){
            if( l%2 == 1){
                  rep(i,26){
                        res[i] += tree[l][i];
                  }
                  l++;
            }
            if( r%2 == 0){
                  rep(i,26){
                        res[i] += tree[r][i];
                  }
                  r--;
            }
            l /= 2;
            r /= 2;
      }
      return res;
}

void solve(){
      string s; cin >> s;
      n = s.length();
      for( int i = 0; i < n; i++){
            char c = s[i];
            rep(j,26) tree[i+n][j] = 0;
            tree[i+n][c-'a'] = 1;
      }
      for( int i = n-1; i > 0; i--){
            tree[i] = sum(tree[2*i], tree[2*i+1]);
      }
      int q; cin >> q;
      while(q--){
            int t; cin >> t;
            if( t == 1){
                  int p; char c;
                  cin >> p >> c;
                  update(p,c);
            }else{
                  int l, r; cin >> l >> r;
                  A pre = find(1,l-1);
                  A suf = find(1,r);
                 // debug(l,r,pre,suf);
                  cout << cntd( pre, suf) << "\n";
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

