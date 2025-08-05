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
const int N = 1e6;
int tree[N];

void update(int i,int x){
      i += n;
      tree[i] = x;
      while( i > 1){
            i/= 2;
            tree[i] = max(tree[2*i], tree[2*i+1]);
      }
}

int find(int i, int x){
      i += n;
      // going up the tree
      while( tree[i] < x){
            if( i%2 == 0){
                  // go to parent
                  i /= 2;
            }else{
                  //go to next sibling but
                  //first check it last sibling i.e.
                  //last node on that level
                  // check if i == 2^k -1;
                  int t = i;
                  bool ok =  false;
                  while(t){
                        if( t%2 == 0) ok = true;
                        t /= 2;
                  }
                  if( !ok) break;
                  i = i+1;
            }
      }
      if( tree[i] < x){
            return -1;
      }
      // go down the tree to leaf
      while(i < n){
            if( tree[2*i] >= x)
                  i = 2*i;
            else
                  i = 2*i+1;
      }
      return i-n+1;
}

void solve(){     
      int t,m;
      cin >> t >> m;
      vector<int> a(t);
      n = 1;
      while( n < t) n*=2;
      memset(tree,0xFFFF,sizeof(tree));
      rep(i,t) cin >> tree[i+n];
      for( int i = n-1; i > 0; i--){
            tree[i] = max( tree[2*i], tree[2*i+1]);
      }
      while(m--){
            int tt,i,x;
            cin >> tt >> i >> x;
          //  debug(tt,i,x);
            if( tt == 0) update(i-1,x);
           else cout << find(i-1,x) << "\n";
      }

}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

