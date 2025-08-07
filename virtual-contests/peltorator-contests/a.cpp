#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int inf = 1e9;

using PI = pair<int,int>;

PI MAX(PI a, PI b){
      PI ans;
      if( a.first == b.first){
            if( a.second < b.second) ans = a;
            else ans = b;
      }else{
            if( a.first >= b.first) ans = a;
            else ans = b;
      }
      return ans;
}

void solve(){
      int n,t;
      cin >> t;
      n = 1;
      while( n < t) n *= 2;
      vector<int> a(t);
      rep(i,t) cin >> a[i];
      vector<pair<int,int>> tree(2*n+1);
	
            rep(i,t){
                  tree[i + n] = {a[i],i+1};
            }
            for(int i = n-1; i >= 1; i--){
                  //if( tree[2*i].first <= tree[2*i + 1].first ){
                  //      tree[i] = tree[2*i];
                  //}else{
                  //      tree[i] = tree[2*i + 1];
                  //}
                  tree[i] = MAX( tree[2*i], tree[2*i + 1]); 
            }

      auto find = [&](int l,int r)->pair<int,int>{
            l += n-1;
            r += n-1;
            pair<int,int> p = {-inf,-1}; 
            while(l <= r){
                  if( l%2 == 1){
                        p = MAX(p, tree[l]);
                        l++;
                  }
                  if( r%2 == 0){
                        p = MAX( p, tree[r]);
                        r--;
                  }
                  r /= 2;
                  l /= 2;
            }
            return p;
      };
      int k; cin >> k;
      while(k--){
            int l, r;
            cin >> l >> r;
            cout << find(l,r).second << "\n";
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

