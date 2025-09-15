#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n; cin >> n;
      vector<int> a(n);
      rep(i,n) cin >> a[i];
      vector<int> cnt(n+1);
      vector<int> tree(2*n + 5);
      auto update = [&](int idx)->void{
            idx += n+1;
            tree[idx]++;
            while( idx > 1){
                  idx /= 2;
                  tree[idx] = max( tree[2*idx], tree[2*idx + 1]);
            }
      };
      auto get_max = [&](int l,int r)->int{
            l += n+1;
            r += n+1;
            int res = 0;
            while( l <= r){
                  if(l%2 == 1){
                        res = max( res, tree[l]);
                        l++;
                  }
                  if( r%2 == 0){
                        res = max( res, tree[r]);
                        r--;
                  }
                  l /= 2;
                  r /= 2;
            }
            return res;
      };
      int g = 0;
      rep(i,n){
            g = gcd(g,a[i]);
            for(int j = 1; j*j <= a[i]; j++){
                  if( a[i]%j == 0){
                      //  cnt[j]++;
                      update(j);
                        int q = a[i]/j;
                        if( q != j){
                              update(q);
                        }
                  }
            }
            //debug(a[i]);
            //debug(tree);
            int ans = get_max(g+1,n);
            cout << ans << " ";
      }
      cout << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

